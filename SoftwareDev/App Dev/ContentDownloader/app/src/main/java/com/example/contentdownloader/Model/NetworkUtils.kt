package com.example.contentdownloader.Model

import android.content.Context
import android.net.ConnectivityManager
import android.net.NetworkInfo

class NetworkUtils {
    companion object {

        //helper for checking network status
        fun getNetworkCondition(context: Context): String? {
            var networkStatus: String? = null
            val cm: ConnectivityManager = context.getSystemService(Context.CONNECTIVITY_SERVICE) as ConnectivityManager
            val networkInfo: NetworkInfo? = cm.activeNetworkInfo
            if (networkInfo != null) {
                if (networkInfo.type == ConnectivityManager.TYPE_WIFI || networkInfo.type == ConnectivityManager.TYPE_MOBILE) {
                    networkStatus = "Connected to Internet"
                }
            } else {
                networkStatus = "No Internet"
                return networkStatus
            }
            return networkStatus
        }

    }
}