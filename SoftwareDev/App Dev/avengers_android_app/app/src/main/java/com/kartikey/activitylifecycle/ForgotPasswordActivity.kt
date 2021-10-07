package com.kartikey.activitylifecycle

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle

class ForgotPasswordActivity : AppCompatActivity() {


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_forgot_password)
    }

    override fun onBackPressed() {
        val intent= Intent(this@ForgotPasswordActivity,LoginActivity::class.java)
        startActivity(intent)
    }
}