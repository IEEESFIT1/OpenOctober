package com.example.contentdownloader.Model

import android.net.Uri
import androidx.core.net.toUri

class WhatsappStatusModel (
        val name : String = "",
        var path: String = "",
        var filename: String = "",
        var uri: Uri = "".toUri()
)