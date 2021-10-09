package com.example.contentdownloader.Adapters

import android.content.Context
import android.media.MediaScannerConnection
import android.os.Environment
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide
import com.example.contentdownloader.Model.ConstantFilename
import com.example.contentdownloader.Model.WhatsappStatusModel
import com.example.contentdownloader.R
import com.example.contentdownloader.databinding.WhatsappStatusItemsBinding
import org.apache.commons.io.FileUtils
import java.io.File
import kotlin.collections.ArrayList

class WhatsappRecyclerViewAdapter(private val context: Context, private val filesList: ArrayList<Any>): RecyclerView.Adapter<WhatsappRecyclerViewAdapter.WhatsappViewHolder>() {


    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): WhatsappViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.whatsapp_status_items,parent,false)
        return WhatsappViewHolder(view)
    }


    override fun onBindViewHolder(holder: WhatsappViewHolder, position: Int) {

        val files: WhatsappStatusModel = filesList[position] as WhatsappStatusModel   //getting the list of files and typecasting to our defined model class

        //checking if the file is video
        if(files.uri.toString().endsWith(".mp4")){
            holder.binding.playButtonImage.visibility = View.VISIBLE
        }
        else{
            holder.binding.playButtonImage.visibility = View.INVISIBLE
        }

        //setting the image on the imageview
        Glide.with(context).load(files.uri).into(holder.binding.mainImageView)

        //handling download button click
        holder.binding.downloadButton.setOnClickListener{

            //to check if folder created or not (if not created then create)
            ConstantFilename.checkDirectory()

            //accessing the path for the source ie. the whatsapp status
            val filepath = filesList[position] as WhatsappStatusModel
            val file = File(filepath.path)


            //here we are accessing the path for the folder we created for our app in which we want to save the status
                            //  context.getExternalFilesDir(null)?.absolutePath
            val destPath = Environment.getExternalStorageDirectory().absolutePath+ ConstantFilename.SAVE_FOLDER_NAME+ ConstantFilename.WHATSAPP_SAVE_FOLDER
            val destFile = File(destPath)


            //now copy the file from src to destination
            //this fileUtils is from apache commons library
            FileUtils.copyFileToDirectory(file,destFile)

            MediaScannerConnection.scanFile(context, arrayOf(destPath+files.filename), arrayOf("*/*"),
                { path, uri ->  })

            Toast.makeText(context, "Download Successful!", Toast.LENGTH_SHORT).show()
        }

        holder.binding.playButtonImage.setOnClickListener{
            Toast.makeText(context, "Please Download Status", Toast.LENGTH_SHORT).show()
        }

    }


    //helper function
    override fun getItemCount(): Int {
        return filesList.size
    }


    inner class WhatsappViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        val binding = WhatsappStatusItemsBinding.bind(itemView)
    }

}