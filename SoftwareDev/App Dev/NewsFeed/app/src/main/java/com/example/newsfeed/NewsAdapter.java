package com.example.newsfeed;

import android.content.Context;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.bumptech.glide.Glide;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.Locale;


public class NewsAdapter extends RecyclerView.Adapter<NewsAdapter.NewsViewHolder> {

    private ArrayList<Articles> articlesArrayList;
    private Context context;
    private OnNewsListener onNewsListener;  //creating reference of the interface created manually in this class for listening to click of recycler view item

    public NewsAdapter(ArrayList<Articles> articlesArrayList, Context context, OnNewsListener onNewsListener) {
        this.articlesArrayList = articlesArrayList;
        this.context = context;
        this.onNewsListener = onNewsListener;
    }

    @NonNull
    @Override
    public NewsAdapter.NewsViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.news_items,parent,false);
        return new NewsViewHolder(view, onNewsListener);
    }

    @Override
    public void onBindViewHolder(@NonNull NewsAdapter.NewsViewHolder holder, int position) {
        holder.newsHeading.setText(articlesArrayList.get(position).getTitle());
        if(articlesArrayList.get(position).getDescription()==null){
            holder.newsSubHeading.setText("Visit our website for detailed information");
        }
        else{
            holder.newsSubHeading.setText(articlesArrayList.get(position).getDescription());
        }
        if(articlesArrayList.get(position).getUrlToImage()==null){
            holder.poster.setImageResource(R.drawable.no_image);
        }
        else{
            Glide.with(context).load(articlesArrayList.get(position).getUrlToImage()).into(holder.poster);
        }
        String date = getPublishedDate(articlesArrayList.get(position).getPublishedAt());    //calling custom method defined below
        holder.publishDate.append(date);
    }

    @Override
    public int getItemCount() {
        return articlesArrayList.size();
    }


    public class NewsViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener {

        private TextView newsHeading, newsSubHeading, publishDate;
        private ImageView poster;
        private OnNewsListener onNewsListener;

        public NewsViewHolder(@NonNull View itemView, OnNewsListener onNewsListener) {
            super(itemView);
            newsHeading = itemView.findViewById(R.id.tv_newsHeadline);
            newsSubHeading = itemView.findViewById(R.id.tv_newsSubtitle);
            poster = itemView.findViewById(R.id.iv_news);
            publishDate = itemView.findViewById(R.id.tv_publish);
            this.onNewsListener = onNewsListener;

            itemView.setOnClickListener(this);   //setting onClickListener on each item in recycler view
        }

        @Override
        public void onClick(View v) {
            //calling the method 'OnNewsClick' of the interface (this method is defined in mainActivity). So that method will be triggered when ever any item is clicked
            onNewsListener.OnNewsClick(getAdapterPosition());
        }
    }

    //custom method crated to get the date the news is published and format it
    private String getPublishedDate(String date){
        DateFormat originalFormat = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss", Locale.US);
        DateFormat targetFormat = new SimpleDateFormat("MMM dd, yyyy", Locale.US);
        Date Fdate = new Date();
        try {
            Fdate = originalFormat.parse(date);
        }
        catch (ParseException e) {
            e.printStackTrace();
        }
        String formattedDate = targetFormat.format(Fdate);
        Log.d("demo", "onCreate: "+formattedDate);

        SimpleDateFormat timeFormat = new SimpleDateFormat("h:mm a");      // Format the time string (i.e. "4:30PM")
        String formattedTime = timeFormat.format(Fdate);
        Log.d("demo", "onCreate: "+formattedTime);

        return formattedDate+" "+formattedTime+" ";
    }


    //this is the interface created manually to detect clicks on the recyclerview items
    public interface OnNewsListener{
        void OnNewsClick(int position);
    }

}
