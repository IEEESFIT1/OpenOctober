package com.example.contentdownloader.fragments

import android.app.DownloadManager
import android.content.ClipData
import android.content.ClipboardManager
import android.content.Context
import android.content.Context.CLIPBOARD_SERVICE
import android.net.Uri
import android.os.Bundle
import android.os.Environment
import android.text.Editable
import android.text.TextWatcher
import android.util.Log
import android.view.View
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.core.content.ContextCompat.getSystemService
import androidx.fragment.app.Fragment
import androidx.lifecycle.lifecycleScope
import com.android.volley.Request
import com.android.volley.VolleyError
import com.android.volley.toolbox.JsonObjectRequest
import com.example.contentdownloader.Model.ConstantFilename
import com.example.contentdownloader.Model.InstagramSingleton
import com.example.contentdownloader.R
import com.example.contentdownloader.databinding.FragmentInstagamBinding
import com.squareup.picasso.Picasso
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import org.json.JSONException
import org.json.JSONObject

class InstagamFragment : Fragment(R.layout.fragment_instagam) {

    private lateinit var binding: FragmentInstagamBinding
    private var FLAG: Boolean = false  //to detect if url is valid or not
    private var global_video_url: String = ""
    private lateinit var clipboardManager: ClipboardManager

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        binding = FragmentInstagamBinding.bind(view)

        clipboardManager = requireActivity().getSystemService(CLIPBOARD_SERVICE) as ClipboardManager

        binding.instagramUrl.addTextChangedListener(textWatcher)

        binding.InstaPasteBtn.setOnClickListener {
            if (clipboardManager.hasPrimaryClip()) {
                val clipData: ClipData? = clipboardManager.primaryClip
                val item: ClipData.Item? = clipData?.getItemAt(0)
                if (item != null) {
                    binding.instagramUrl.setText(item.text.toString())
                }
            } else {
                Toast.makeText(requireContext(), "Please copy URL!!", Toast.LENGTH_SHORT).show()
            }
        }

        binding.instaDownload.setOnClickListener {
            if (FLAG) {
                downloadVideo()
            } else {
                Toast.makeText(requireContext(), "Invalid URL!!", Toast.LENGTH_SHORT).show()
            }
        }
    }

    //watching the change in text of the edittext
    private val textWatcher = object : TextWatcher {
        override fun afterTextChanged(s: Editable?) {
        }

        override fun beforeTextChanged(s: CharSequence?, start: Int, count: Int, after: Int) {
        }

        override fun onTextChanged(s: CharSequence?, start: Int, before: Int, count: Int) {
            change_detected()   //load the video into videoview
        }
    }

    private fun change_detected() {

        val pasted_url = binding.instagramUrl.text.toString()

        if (pasted_url.contains("instagram.com")) {
            FLAG = true   //url is valid
            val replacedUrl: String = clean_url(pasted_url)
            var finalUrl = ""

            binding.progBar.visibility = View.VISIBLE

            //receiving jsonobject response from volley
            val jsonObjectRequest = JsonObjectRequest(Request.Method.GET, "$replacedUrl?__a=1", null,
                    //if success
                    { response ->

                        //calling function when we get a response
                        finalUrl = parseJSON(response)

                        //for images
                        if (finalUrl.substringBefore(" ") == "" && (finalUrl.substringAfter(" ").contains(".jpg") || finalUrl.substringAfter(" ").contains(".png") || finalUrl.substringAfter(" ").contains(".jpeg"))) {
                            global_video_url = finalUrl.substringAfter(" ")
                            val image_uri = Uri.parse(global_video_url)

                            //loading image
                            Picasso.get().load(image_uri).into(binding.thumbNail)

                            binding.progBar.visibility = View.INVISIBLE
                            binding.RL1.visibility = View.GONE
                            binding.RL2.visibility = View.VISIBLE
                        }

                        //for video
                        if (finalUrl.substringBefore(" ").contains(".mp4") && finalUrl.substringBefore(" ") != "") {
                            global_video_url = finalUrl.substringBefore(" ")

                            binding.preview.setVideoURI(Uri.parse(global_video_url))  //set the VideoView with the fetched url

                            binding.preview.start()
                            binding.preview.setOnPreparedListener({ mp -> mp.isLooping = true })

                            binding.progBar.visibility = View.INVISIBLE
                            binding.RL2.visibility = View.GONE
                            binding.RL1.visibility = View.VISIBLE
                        }

                    },
                    //if failure
                    {
                        fun onErrorResponse(error: VolleyError) {
                            Log.e("VideoURLErrors", "Something went wrong$error")
                            Toast.makeText(requireContext(), "Something went wrong", Toast.LENGTH_SHORT).show()
                        }
                    })

            InstagramSingleton.getInstance(requireContext()).addToRequestQueue(jsonObjectRequest)

        }
    }

    private fun parseJSON(response: JSONObject): String {
        var Obj1: JSONObject? = null
        //parsing the json response which is received
        try {
            Obj1 = response.getJSONObject("graphql")
        } catch (e: JSONException) {
            e.printStackTrace()
        }

        var Obj2: JSONObject? = null
        try {
            Obj2 = Obj1!!.getJSONObject("shortcode_media")
        } catch (e: JSONException) {
            e.printStackTrace()
        }

        var image_url = ""
        try {
            image_url = Obj2!!.getString("display_url")
        } catch (e: JSONException) {
            e.printStackTrace()
        }

        var finalVideoUrl = ""
        try {
            finalVideoUrl = Obj2!!.getString("video_url")
        } catch (e: JSONException) {
            e.printStackTrace()
        }

        return finalVideoUrl + " " + image_url
    }

    //remove unnecessary part
    private fun clean_url(postUrl: String): String {
        if (postUrl.contains("?utm_source=ig_web_copy_link")) {
            val partToRemove = "?utm_source=ig_web_copy_link"
            return postUrl.replace(partToRemove, "")
        } else if (postUrl.contains("?utm_source=ig_web_button_share_sheet")) {
            val partToRemove = "?utm_source=ig_web_button_share_sheet"
            return postUrl.replace(partToRemove, "")
        } else if (postUrl.contains("?utm_medium=share_sheet")) {
            val partToRemove = "?utm_medium=share_sheet"
            return postUrl.replace(partToRemove, "")
        } else if (postUrl.contains("?utm_medium=copy_link")) {
            val partToRemove = "?utm_medium=copy_link"
            return postUrl.replace(partToRemove, "")
        } else {
            return postUrl
        }
    }

    private fun downloadVideo() {
        viewLifecycleOwner.lifecycleScope.launch(Dispatchers.IO) {
            ConstantFilename.checkDirectory()
            var file_name = "Insta_" + System.currentTimeMillis().toString()
            if (global_video_url.contains(".mp4")) {
                file_name = "$file_name.mp4"
            } else {
                file_name = "$file_name.jpg"
            }
            download(global_video_url, ConstantFilename.SAVE_FOLDER_NAME + ConstantFilename.INSTAGRAM_SAVE_FOLDER, file_name)
        }
    }

    private fun download(downloadPath: String, destinationPath: String, fileName: String) {
        requireActivity()!!.runOnUiThread { Toast.makeText(requireContext(), "Download started...", Toast.LENGTH_SHORT).show() }
        val uri = Uri.parse(downloadPath)
        val request = DownloadManager.Request(uri)
        request.setAllowedNetworkTypes(DownloadManager.Request.NETWORK_MOBILE or DownloadManager.Request.NETWORK_WIFI)
        request.setNotificationVisibility(DownloadManager.Request.VISIBILITY_VISIBLE_NOTIFY_COMPLETED)
        request.setTitle(fileName)
        request.setDestinationInExternalPublicDir(Environment.DIRECTORY_DOWNLOADS, destinationPath + fileName)
        (requireContext().getSystemService(Context.DOWNLOAD_SERVICE) as DownloadManager).enqueue(request)
    }

}