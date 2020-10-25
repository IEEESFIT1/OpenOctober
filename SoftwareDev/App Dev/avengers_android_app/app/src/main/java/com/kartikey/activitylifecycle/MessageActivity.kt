package com.kartikey.activitylifecycle

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_avengers.*
import kotlinx.android.synthetic.main.activity_message.*

class MessageActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {

        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_message)

        if(intent!=null)
        {
            var message=intent.getStringExtra("Message")
            txtMessageEntered.text= message
        }

    }

}