package com.kartikey.bookhub.util

import android.content.Context
import android.net.ConnectivityManager
import android.net.NetworkInfo

//checks connectivity
class ConnectionManager {

    fun checkConnectivity(context: Context): Boolean {
        var connectivityManager =
            context.getSystemService(Context.CONNECTIVITY_SERVICE) as ConnectivityManager
        //checks info for the active network
        var activeNetwork: NetworkInfo? = connectivityManager.activeNetworkInfo

        if (activeNetwork?.isConnected != null) {
            return activeNetwork.isConnected
        } else {
            return false
        }
    }
}