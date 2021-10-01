package com.kartikey.bookhub.adapter

import android.content.Context
import android.content.Intent
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.RelativeLayout
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import com.kartikey.bookhub.R
import com.kartikey.bookhub.activity.DescriptionActivity
import com.kartikey.bookhub.database.BookEntity
import com.kartikey.bookhub.model.Book
import com.squareup.picasso.Picasso
import org.w3c.dom.Text

//initialise class for data and context
class DashboardRecyclerAdapter(val context: Context, val itemList: ArrayList<Book>) :
    RecyclerView.Adapter<DashboardRecyclerAdapter.DashboardViewHolder>() {

    class DashboardViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        var txtBookName: TextView = view.findViewById(R.id.txtBookName)
        var txtBookRating: TextView = view.findViewById(R.id.txtBookRating)
        var txtBookAuthor: TextView = view.findViewById(R.id.txtBookAuthor)
        var imgBookImage: ImageView = view.findViewById(R.id.imgBookImage)
        var txtBookCost: TextView = view.findViewById(R.id.txtBookCost)
        var rlContent: RelativeLayout = view.findViewById(R.id.rlContent)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): DashboardViewHolder {
        //creates and reuses holders. respons for creating 10 viewholders
        // inflate layout of a list item
        //parent.context = for view holder
        //inflate() = for position
        val view = LayoutInflater.from(parent.context)
            .inflate(R.layout.recycler_dashboard_single_row, parent, false)
        return DashboardViewHolder(view)
    }

    override fun getItemCount(): Int {
        return itemList.size
    }

    override fun onBindViewHolder(holder: DashboardViewHolder, position: Int) {
        // Puts value in the current holder
        val book = itemList[position]
        holder.txtBookName.text = book.bookName
        holder.txtBookAuthor.text = book.bookAuthor
        holder.txtBookCost.text = book.bookPrice
        holder.txtBookRating.text = book.bookRating
        //  will not work with JSON objects : holder.imgBookImage.setImageResource(book.bookImage)
        Picasso.get().load(book.bookImage).error(R.drawable.default_book_cover)
            .into(holder.imgBookImage)

        holder.rlContent.setOnClickListener {
            val intent = Intent(context, DescriptionActivity::class.java)
            intent.putExtra("book_id", book.bookId)
            context.startActivity(intent)

            Toast.makeText(context, "Clicked on ${holder.txtBookName.text}!", Toast.LENGTH_SHORT)
                .show()
        }

    }
}