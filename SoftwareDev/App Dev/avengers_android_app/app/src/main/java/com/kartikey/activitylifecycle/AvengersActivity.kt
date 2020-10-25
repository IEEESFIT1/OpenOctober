package com.kartikey.activitylifecycle

import android.content.Context
import android.content.Intent
import android.content.SharedPreferences
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import androidx.appcompat.app.AppCompatActivity

class AvengersActivity : AppCompatActivity() {

    var name: String? = null
    lateinit var etMessage: EditText
    lateinit var btnMessage: Button
    lateinit var btnLogout: Button
    lateinit var sharedPreferences: SharedPreferences

    override fun onCreate(savedInstanceState: Bundle?) {

        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_avengers)
     //   println("Create function called")

        sharedPreferences = getSharedPreferences(getString(R.string.preference_file_name), Context.MODE_PRIVATE)

        name = sharedPreferences.getString("nameOfAvenger","Thanos Killed You!")
        title = "Current User: $name"

        etMessage = findViewById(R.id.etMessage)
        btnMessage = findViewById(R.id.btnSendMessage)
        btnLogout=findViewById(R.id.btnLogOut)

        btnMessage.setOnClickListener {


            val intent = Intent(this@AvengersActivity, MessageActivity::class.java)
            //val message = etMessage.text.toString()
            intent.putExtra("Message", etMessage.text.toString())
            startActivity(intent)
        }

        btnLogout.setOnClickListener {

            val intent= Intent(this@AvengersActivity,LoginActivity::class.java)
            sharedPreferences.edit().clear().apply()
            startActivity(intent)
            finish()
    }

    }
}