package com.example.contentdownloader.fragments

import android.Manifest
import android.app.Activity
import android.content.Intent
import android.net.Uri
import android.os.Build
import android.os.Bundle
import android.os.Environment
import android.os.Handler
import android.provider.Settings
import android.view.View
import android.widget.Toast
import androidx.activity.result.ActivityResultLauncher
import androidx.activity.result.contract.ActivityResultContracts.StartActivityForResult
import androidx.fragment.app.Fragment
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import androidx.swiperefreshlayout.widget.SwipeRefreshLayout
import com.example.contentdownloader.Adapters.WhatsappRecyclerViewAdapter
import com.example.contentdownloader.Model.ConstantFilename
import com.example.contentdownloader.Model.WhatsappStatusModel
import com.example.contentdownloader.R
import com.example.contentdownloader.databinding.FragmentWhatsappBinding
import com.karumi.dexter.Dexter
import com.karumi.dexter.MultiplePermissionsReport
import com.karumi.dexter.PermissionToken
import com.karumi.dexter.listener.PermissionRequest
import com.karumi.dexter.listener.multi.MultiplePermissionsListener
import java.io.File

//this fragment implements the dexter interface 'MultiplePermissionsListener' as we need to handle permissions
class WhatsappFragment : Fragment(R.layout.fragment_whatsapp), MultiplePermissionsListener {

    private lateinit var binding: FragmentWhatsappBinding

    private lateinit var recyclerView: RecyclerView
    private lateinit var swipeRefreshLayout: SwipeRefreshLayout
    private lateinit var storyAdapter: WhatsappRecyclerViewAdapter
    private var files = arrayOf<File>() //array of files
    private var filesList = ArrayList<Any>()    //arraylist of the model class

    //for manage_external_storage  to check the permissions on android 11
    private lateinit var activityResultLauncher: ActivityResultLauncher<Intent>

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        binding = FragmentWhatsappBinding.bind(view)

        initComponents()   //to initialize all component

        //checking for only android 11 or above so the app wont work below that
        activityResultLauncher = registerForActivityResult(StartActivityForResult()) { result ->
            if (result.getResultCode() === Activity.RESULT_OK) {
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
                    if (Environment.isExternalStorageManager()) {
                        Toast.makeText(requireContext(), "Permession Granted", Toast.LENGTH_SHORT).show()
                    } else {
                        Toast.makeText(requireContext(), "Permession Denied", Toast.LENGTH_SHORT).show()
                    }
                }
            }
        }

        //handling user permissions (using dexter is recommended if there are more permissions)
        Dexter.withContext(requireContext())
                .withPermissions(Manifest.permission.READ_EXTERNAL_STORAGE, Manifest.permission.WRITE_EXTERNAL_STORAGE)
                .withListener(this)
                .check()

    }

    //below two methods are implemented for 'dexter'
    override fun onPermissionsChecked(p0: MultiplePermissionsReport?) {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            if (checkPermission()) {
                setRefreshLayout()   //if permission granted then call this function to do further work
            }
        } else if (Build.VERSION.SDK_INT < Build.VERSION_CODES.R) {
            setRefreshLayout()
        } else {
            requestPermission()
        }
    }

    override fun onPermissionRationaleShouldBeShown(p0: MutableList<PermissionRequest>?, p1: PermissionToken?) {
        p1?.continuePermissionRequest()
    }

    //helpers to check and request permission to access all files only on android 11
    private fun checkPermission(): Boolean {
        return Environment.isExternalStorageManager()
    }

    private fun requestPermission() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            try {
                //go to setting page for permission
                val intent = Intent(Settings.ACTION_MANAGE_APP_ALL_FILES_ACCESS_PERMISSION)
                intent.addCategory("android.intent.category.DEFAULT")
                intent.data = Uri.parse(String.format("package:%s", *arrayOf<Any>(requireContext().packageName)))
                activityResultLauncher.launch(intent)
            } catch (e: Exception) {
                val intent = Intent()
                intent.action = Settings.ACTION_MANAGE_ALL_FILES_ACCESS_PERMISSION
                activityResultLauncher.launch(intent)
            }
        }
    }

    private fun initComponents() {
        recyclerView = binding.recyclerView
        swipeRefreshLayout = binding.swipeRefresh

        //setting refreshing action on the swipeRefreshLayout layout
        swipeRefreshLayout.setOnRefreshListener {
            swipeRefreshLayout.isRefreshing = true
            setRefreshLayout()   //calling helper function

            Handler().postDelayed(Runnable {
                swipeRefreshLayout.isRefreshing = false
                Toast.makeText(requireContext(), "Refresh!", Toast.LENGTH_SHORT).show()
            }, 2000)

        }
    }

    //to refresh all the files in the array
    private fun setRefreshLayout() {
        filesList.clear()
        recyclerView.setHasFixedSize(true)
        recyclerView.layoutManager = LinearLayoutManager(requireContext())
        storyAdapter = WhatsappRecyclerViewAdapter(requireContext(), getFilesList())  //getFilesList() is an helper function
        recyclerView.adapter = storyAdapter
        storyAdapter.notifyDataSetChanged()
    }

    //helper function
    private fun getFilesList(): ArrayList<Any> {
        var model: WhatsappStatusModel

        val targetPath = Environment.getExternalStorageDirectory().absolutePath + "/Android/media/com.whatsapp/" + ConstantFilename.FOLDER_NAME + "Media/.Statuses"
        val targetDir = File(targetPath)  //we will get bunch of status files here

        if (targetDir.listFiles() == null) {
            val targetPath1 = Environment.getExternalStorageDirectory().absolutePath + ConstantFilename.FOLDER_NAME + "Media/.Statuses"
            val targetDir1 = File(targetPath1)  //we will get bunch of status files here
            files = targetDir1.listFiles()   //list all of the statuses into 'files' which is an array
        } else {
            files = targetDir.listFiles()   //list all of the statuses into 'files' which is an array
        }

        //iterate through each index in 'files'
        for (index in files.indices) {
            val file = files[index]
            model = WhatsappStatusModel()
            model.path = files[index].absolutePath
            model.filename = file.name
            model.uri = Uri.fromFile(file)

            //if the file is not of type 'nomedia' then add it to ArrayList
            if (!model.uri.toString().endsWith(".nomedia")) {
                filesList.add(model)
            }
        }
        return filesList    //return the arraylist of the model class containing info about the statuses
    }

}