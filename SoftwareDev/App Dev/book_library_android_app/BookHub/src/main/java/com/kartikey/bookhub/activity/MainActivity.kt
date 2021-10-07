package com.kartikey.bookhub.activity

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.MenuItem
import android.widget.FrameLayout
import android.widget.Toast
import androidx.appcompat.app.ActionBarDrawerToggle
import androidx.appcompat.widget.Toolbar
import androidx.coordinatorlayout.widget.CoordinatorLayout
import androidx.core.view.GravityCompat
import androidx.drawerlayout.widget.DrawerLayout
import com.google.android.material.navigation.NavigationView
import com.kartikey.bookhub.fragment.ProfileFragment
import com.kartikey.bookhub.R
import com.kartikey.bookhub.fragment.AboutAppFragment
import com.kartikey.bookhub.fragment.DashboardFragment
import com.kartikey.bookhub.fragment.FavouritesFragment

class MainActivity : AppCompatActivity() {

    lateinit var coordinatorLayout: CoordinatorLayout
    lateinit var frameLayout: FrameLayout
    lateinit var drawerLayout: DrawerLayout
    lateinit var toolBar: Toolbar
    lateinit var navigationView: NavigationView

    var previousMenuItem: MenuItem? = null
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        coordinatorLayout = findViewById(R.id.coordinatorLayout)
        frameLayout = findViewById(R.id.frameLayout)
        drawerLayout = findViewById(R.id.drawerLayout)
        toolBar = findViewById(R.id.toolbar)
        navigationView = findViewById(R.id.navigationview)

        setUpToolbar()
        //Open default
        openDashboard()
        //Put action bar toggle
        val actionBarDrawerToggle = ActionBarDrawerToggle(
            this@MainActivity,
            drawerLayout,
            R.string.open_drawer,
            R.string.close_drawer
        )

        drawerLayout.addDrawerListener(actionBarDrawerToggle)
        actionBarDrawerToggle.syncState()


        navigationView.setNavigationItemSelectedListener {
            //checking and unchecking of menu items
            if (previousMenuItem != null) {
                previousMenuItem?.isChecked = false
            }
            it.isChecked = true
            it.isCheckable = true//What does this do? To check selected item
            previousMenuItem = it

            when (it.itemId) {
                //To invoke the fragment of the dashboard
                R.id.dashboard -> {
                    openDashboard()
                    Toast.makeText(this@MainActivity, "Clicked Dashboard", Toast.LENGTH_SHORT)
                        .show()
                }
                R.id.profile -> {
                    supportFragmentManager
                        .beginTransaction().replace(
                            R.id.frameLayout,
                            ProfileFragment()
                        )
                        .addToBackStack("Profile").commit()
                    drawerLayout.closeDrawers()
                    supportActionBar?.title = "Profile"
                    Toast.makeText(this@MainActivity, "Clicked Profile", Toast.LENGTH_SHORT).show()
                }
                R.id.aboutapp -> {
                    supportFragmentManager
                        .beginTransaction().replace(
                            R.id.frameLayout,
                            AboutAppFragment()
                        )
                        .addToBackStack("AboutApp").commit()
                    drawerLayout.closeDrawers()
                    supportActionBar?.title = "About App"
                    Toast.makeText(this@MainActivity, "Clicked About App", Toast.LENGTH_SHORT)
                        .show()
                }
                R.id.favourites -> {

                    supportFragmentManager
                        .beginTransaction().replace(
                            R.id.frameLayout,
                            FavouritesFragment()
                        )
                        .addToBackStack("Favourites").commit()
                    drawerLayout.closeDrawers()

                    supportActionBar?.title = "Favourites"
                    Toast.makeText(this@MainActivity, "Clicked Favourites", Toast.LENGTH_SHORT)
                        .show()
                }
            }

            return@setNavigationItemSelectedListener true
        }


    }

    fun openDashboard() {
        supportFragmentManager.beginTransaction()
            .replace(
                R.id.frameLayout,
                DashboardFragment()
            )
            .addToBackStack("Dashboard").commit()
        supportActionBar?.title = "Dashboard"
        drawerLayout.closeDrawers()
        navigationView.setCheckedItem(R.id.dashboard)
    }

    fun setUpToolbar() {
        setSupportActionBar(toolBar)
        supportActionBar?.title = "Title"
        supportActionBar?.setHomeButtonEnabled(true)
        supportActionBar?.setDisplayHomeAsUpEnabled(true)
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {

        val id = item.itemId
        if (id == android.R.id.home) {
            drawerLayout.openDrawer(GravityCompat.START)
        }
        return super.onOptionsItemSelected(item)
    }

    override fun onBackPressed() {
        when (supportFragmentManager.findFragmentById(R.id.frameLayout)) {
            !is DashboardFragment -> {
                supportFragmentManager.beginTransaction()
                    .replace(
                        R.id.frameLayout,
                        DashboardFragment()
                    ).addToBackStack("Dashboard").commit()
                supportActionBar?.title = "Dashboard"
                drawerLayout.closeDrawers()
                navigationView.setCheckedItem(R.id.dashboard)
            }
            else -> finish()
        }
    }

}