package com.example.contentdownloader.Adapters

import androidx.fragment.app.Fragment
import androidx.fragment.app.FragmentManager
import androidx.lifecycle.Lifecycle
import androidx.viewpager2.adapter.FragmentStateAdapter
import com.example.contentdownloader.fragments.FacebookFragment
import com.example.contentdownloader.fragments.InstagamFragment
import com.example.contentdownloader.fragments.WhatsappFragment

class ViewPagerAdapter(fragmentManager: FragmentManager, lifecycle: Lifecycle) : FragmentStateAdapter(fragmentManager, lifecycle) {

    override fun getItemCount(): Int {
        return 3
    }

    //show fragment based on position number
    override fun createFragment(position: Int): Fragment {
        return when (position) {
            0 -> {
                InstagamFragment()
            }
            1 -> {
                FacebookFragment()
            }
            2 -> {
                WhatsappFragment()
            }
            else -> Fragment()
        }
    }
}