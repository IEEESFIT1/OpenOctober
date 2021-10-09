package com.example.contentdownloader.Activities

import android.content.Context
import android.content.Intent
import android.net.ConnectivityManager
import android.net.Network
import android.os.Bundle
import android.os.PersistableBundle
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.example.contentdownloader.databinding.ActivityNoNetworkBinding

class NoNetworkActivity : AppCompatActivity() {
    private lateinit var binding: ActivityNoNetworkBinding
    private var isConnected: Boolean = false
    private lateinit var connectivityManager: ConnectivityManager

    override fun onCreate(savedInstanceState: Bundle?, persistentState: PersistableBundle?) {
        super.onCreate(savedInstanceState, persistentState)

        binding = ActivityNoNetworkBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.retry.setOnClickListener {
            if (isConnected) {
                val intent = Intent(this, MainActivity::class.java)
                startActivity(intent)
                finish()
            } else {
                Toast.makeText(this, "Not connected", Toast.LENGTH_SHORT).show()
            }
        }

    }

    //to monitor network connectivity
    private fun registerNetworkCallback() {
        try {
            connectivityManager = applicationContext.getSystemService(Context.CONNECTIVITY_SERVICE) as ConnectivityManager
            val networkCallback = object : ConnectivityManager.NetworkCallback() {
                override fun onAvailable(network: Network) {
                    isConnected = true
                }

                override fun onLost(network: Network) {
                    isConnected = false
                }
            }
            connectivityManager.registerDefaultNetworkCallback(networkCallback)
        } catch (e: Exception) {
            isConnected = false
        }
    }


    private fun unregisterNetworkCallback() {
        connectivityManager.unregisterNetworkCallback(ConnectivityManager.NetworkCallback())
    }

    override fun onResume() {
        super.onResume()
        registerNetworkCallback()
    }

    override fun onPause() {
        super.onPause()
        unregisterNetworkCallback()
    }
}