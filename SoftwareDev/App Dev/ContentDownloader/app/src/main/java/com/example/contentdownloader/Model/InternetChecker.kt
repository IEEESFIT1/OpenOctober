package com.example.contentdownloader.Model

import android.app.Activity
import android.app.Dialog
import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.widget.Button
import android.widget.Toast
import com.example.contentdownloader.Activities.MainActivity
import com.example.contentdownloader.R

class InternetChecker : BroadcastReceiver() {
    override fun onReceive(context: Context, intent: Intent) {
        var status: String? = context.let { NetworkUtils.getNetworkCondition(it) }
        val dialog = Dialog(context, android.R.style.Theme_NoTitleBar_Fullscreen)
        dialog.setContentView(R.layout.activity_no_network)
        val retry: Button? = dialog.findViewById(R.id.retry)

        if (status?.isEmpty() == true || status?.equals("No Internet") == true) {
            Toast.makeText(context, status, Toast.LENGTH_SHORT).show()
            dialog.show()   //if no network then show dialog
        }

        if (retry != null) {
            retry.setOnClickListener {
                val intent = Intent(context, MainActivity::class.java)
                context.startActivity(intent)
                (context as Activity).finish()
                dialog.dismiss()
            }
        }

    }
}