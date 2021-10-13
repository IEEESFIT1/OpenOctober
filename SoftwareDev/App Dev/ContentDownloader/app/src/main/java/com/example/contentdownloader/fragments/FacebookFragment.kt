package com.example.contentdownloader.fragments

import android.app.DownloadManager
import android.content.ClipData
import android.content.ClipboardManager
import android.content.Context
import android.net.Uri
import android.os.Bundle
import android.os.Environment
import android.view.View
import android.widget.Toast
import androidx.fragment.app.Fragment
import androidx.lifecycle.lifecycleScope
import com.example.contentdownloader.Model.ConstantFilename
import com.example.contentdownloader.R
import com.example.contentdownloader.databinding.FragmentFacebookBinding
import com.google.android.material.snackbar.Snackbar
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import org.jsoup.Jsoup
import org.jsoup.nodes.Document
import java.net.URL

class FacebookFragment : Fragment(R.layout.fragment_facebook) {

    private lateinit var binding: FragmentFacebookBinding
    private lateinit var download_view: View
    private lateinit var clipboardManager: ClipboardManager

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        binding = FragmentFacebookBinding.bind(view)

        clipboardManager = requireActivity().getSystemService(Context.CLIPBOARD_SERVICE) as ClipboardManager

        binding.FbPasteBtn.setOnClickListener {
            if (clipboardManager.hasPrimaryClip()) {
                val clipData: ClipData? = clipboardManager.primaryClip
                val item: ClipData.Item? = clipData?.getItemAt(0)
                if (item != null) {
                    binding.facebookUrl.setText(item.text.toString())
                }
            } else {
                Toast.makeText(requireContext(), "Please copy URL!!", Toast.LENGTH_SHORT).show()
            }
        }

        binding.fbDownload.setOnClickListener {
            download_view = it
            //checking for valid url
            if (binding.facebookUrl.text.toString() != "") {
                val url: URL = URL(binding.facebookUrl.text.toString())
                val url_host: String? = url.host

                //valid
                if (url_host != null) {
                    if (url_host.contains("facebook.com")) {
                        binding.facebookProgBar.visibility = View.VISIBLE
                        viewLifecycleOwner.lifecycleScope.launch(Dispatchers.IO) {
                            makeCallForDownload(binding.facebookUrl.text.toString())
                        }
                    }
                }
            }
            //invalid
            else {
                Toast.makeText(requireContext(), "Invalid URL !!", Toast.LENGTH_SHORT).show()
            }
        }

    }

    //this function should run in background, it contains blocking calls
    private fun makeCallForDownload(pasted_url: String) {

        //connect() method creates a new Connection, and get() fetches and parses a HTML file.
        val fb_downloaded_document: Document = Jsoup.connect(pasted_url).get()

        var video_url = ""
        //parsing the html to get the attribute 'content' which consists the url of the video
        try {
            video_url = fb_downloaded_document.select("meta[property=\"og:video\"]").last().attr("content")
        } catch (e: Exception) {
            binding.facebookProgBar.visibility = View.INVISIBLE
            Snackbar.make(download_view, "Private video!! Copy URL from official page", Snackbar.LENGTH_SHORT).show()
        }

        if (!video_url.equals("")) {
            ConstantFilename.checkDirectory()
            download(video_url, ConstantFilename.SAVE_FOLDER_NAME + ConstantFilename.FACEBOOK_SAVE_FOLDER, "FB_" + System.currentTimeMillis() + ".mp4")
        }

    }

    //download the file to a destination
    private fun download(downloadPath: String, destinationPath: String, filename: String) {
        binding.facebookProgBar.visibility = View.INVISIBLE
        requireActivity()!!.runOnUiThread { Toast.makeText(activity, "Downloading Started...", Toast.LENGTH_SHORT).show() }
        val uri = Uri.parse(downloadPath)
        val request = DownloadManager.Request(uri)  //request to download the uri
        request.setAllowedNetworkTypes(DownloadManager.Request.NETWORK_MOBILE or DownloadManager.Request.NETWORK_WIFI)
        request.setNotificationVisibility(DownloadManager.Request.VISIBILITY_VISIBLE_NOTIFY_COMPLETED)    //to show download in notification bar
        request.setTitle(filename)
        request.setDestinationInExternalPublicDir(Environment.DIRECTORY_DOWNLOADS, destinationPath + filename)    //set the destination of the download
        (requireContext().getSystemService(Context.DOWNLOAD_SERVICE) as DownloadManager).enqueue(request)   //to enqueue the download
    }


}