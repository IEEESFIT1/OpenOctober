package com.kartikey.activitylifecycle

import android.content.Context
import android.content.Intent
import android.content.SharedPreferences
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import android.widget.Toast

class LoginActivity : AppCompatActivity() {

    lateinit var etNumber : EditText
    lateinit var etPassword: EditText
    lateinit var btnLogin: Button
    lateinit var txtForgotPassword: TextView
    val validMobileNumber="1234567890"
    val validPassword= arrayListOf("tony","thor","steve","thanos")

    lateinit var sharedPreferences: SharedPreferences

    override fun onCreate(savedInstanceState: Bundle?) {

        super.onCreate(savedInstanceState)
        sharedPreferences= getSharedPreferences(getString(R.string.preference_file_name), Context.MODE_PRIVATE)
        val isLoggedIn = sharedPreferences.getBoolean("isLoggedIn",false)
        setContentView(R.layout.activity_login)

        if(isLoggedIn)
        {
            val intent= Intent(this@LoginActivity, AvengersActivity::class.java)
            startActivity(intent)
            finish()
        }

        title="Login"

        etNumber=findViewById(R.id.etNumber)
        etPassword=findViewById(R.id.etPassword)
        btnLogin=findViewById(R.id.btnLogIn)
        txtForgotPassword=findViewById(R.id.txtForgotPassword)

        txtForgotPassword.setOnClickListener {
            val intent= Intent(this@LoginActivity,ForgotPasswordActivity::class.java)
            startActivity(intent)
        }

        btnLogin.setOnClickListener {

           val mobileNumber = etNumber.text.toString()
            val password = etPassword.text.toString()
            lateinit var nameOfAvenger:String

            val intent= Intent(this@LoginActivity, AvengersActivity::class.java)
            if ((mobileNumber == validMobileNumber)) {

                when (password) {
                    validPassword[0] -> {


                        nameOfAvenger = "Iron Man"
                        savePreference(nameOfAvenger)
                      //  intent.putExtra("Name", nameOfAvenger)
                        startActivity(intent)

                    }
                    validPassword[1] -> {

                        nameOfAvenger = "Captain America"
                        savePreference(nameOfAvenger)
                     //   intent.putExtra("Name", nameOfAvenger)
                        startActivity(intent)

                    }
                    validPassword[2] -> {

                        nameOfAvenger = "The Hulk"
                        savePreference(nameOfAvenger)
                     //   intent.putExtra("Name", nameOfAvenger)
                        startActivity(intent)

                    }
                    validPassword[3] -> {

                        nameOfAvenger = "The Avengers"
                        savePreference(nameOfAvenger)
                      //  intent.putExtra("Name", nameOfAvenger)
                        startActivity(intent)

                    }
                    else -> Toast.makeText(this@LoginActivity, "Incorrect Password", Toast.LENGTH_LONG).show()
                }

            } else {

                Toast.makeText(this@LoginActivity, "Incorrect Credentials", Toast.LENGTH_LONG).show()

            }

        }


    }

    //Will come out of the app once it goes into Pause ,ie, the AvengersActivity takes over
    override fun onPause() {
        super.onPause()
        finish()
    }

    fun savePreference(nameofAvenger: String)
    {
        sharedPreferences.edit().putBoolean("isLoggedIn",true).apply()
        sharedPreferences.edit().putString("nameOfAvenger",nameofAvenger).apply()
    }

    override fun onBackPressed() {
        finish()
    }

}