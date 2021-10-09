package com.example.contentdownloader.Activities

import android.content.BroadcastReceiver
import android.content.IntentFilter
import android.net.ConnectivityManager
import android.os.Build
import android.os.Bundle
import androidx.annotation.RequiresApi
import androidx.appcompat.app.AppCompatActivity
import com.example.contentdownloader.Adapters.ViewPagerAdapter
import com.example.contentdownloader.Model.InternetChecker
import com.example.contentdownloader.R
import com.example.contentdownloader.databinding.ActivityMainBinding
import com.google.android.material.tabs.TabLayoutMediator

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    private lateinit var broadcastReceiver: BroadcastReceiver

    @RequiresApi(Build.VERSION_CODES.M)
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        broadcastReceiver = InternetChecker()
        checkConnection()

        val titleArray = arrayOf("Reels/IGTV", "Facebook Videos", "Whatsapp Status")
        val iconArray = arrayOf(R.drawable.instagram_selector, R.drawable.facebook_selector, R.drawable.whatsapp_selector)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        //setting action bar as custom toolbar
        setSupportActionBar(binding.toolbar)

        //initilize
        val viewPager = binding.viewPager
        val tabLayout = binding.tabLayout
        val viewPagerAdapter = ViewPagerAdapter(supportFragmentManager, lifecycle)

        viewPager.adapter = viewPagerAdapter

        TabLayoutMediator(tabLayout, viewPager) { tab, position ->
            tab.text = titleArray[position]
            tab.setIcon(iconArray[position])
        }.attach()

    }

    override fun onResume() {
        super.onResume()
        checkConnection()
    }

    private fun checkConnection() {
        registerReceiver(broadcastReceiver, IntentFilter(ConnectivityManager.CONNECTIVITY_ACTION))
    }

    override fun onPause() {
        super.onPause()
        unregisterReceiver(broadcastReceiver)
    }

}