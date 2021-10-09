package com.example.contentdownloader.Model

import android.os.Environment
import java.io.File

class ConstantFilename {
    companion object {
        const val FOLDER_NAME = "/WhatsApp/"

        const val SAVE_FOLDER_NAME = "/Content Downloader/"
        const val WHATSAPP_SAVE_FOLDER = "/Whatsapp Downloads/"
        const val FACEBOOK_SAVE_FOLDER = "/Facebook Downloads/"
        const val INSTAGRAM_SAVE_FOLDER = "/Instagram Downloads/"

        //check if directory is created
        fun checkDirectory() {
            //context.getExternalFilesDir(null)?.absolutePath
            val path = Environment.DIRECTORY_DOWNLOADS + SAVE_FOLDER_NAME
            val path2 = Environment.DIRECTORY_DOWNLOADS + SAVE_FOLDER_NAME + WHATSAPP_SAVE_FOLDER
            val path3 = Environment.DIRECTORY_DOWNLOADS + SAVE_FOLDER_NAME + FACEBOOK_SAVE_FOLDER
            val path4 = Environment.DIRECTORY_DOWNLOADS + SAVE_FOLDER_NAME + INSTAGRAM_SAVE_FOLDER

            //creating the folder
            val dir = File(path)
            val dir2 = File(path2)
            val dir3 = File(path3)
            val dir4 = File(path4)

            if (!dir.exists()) {
                dir.mkdir()
            }

            if (!dir2.exists()) {
                dir2.mkdir()
            }

            if (!dir3.exists()) {
                dir3.mkdir()
            }

            if (!dir4.exists()) {
                dir4.mkdir()
            }
        }
    }
}