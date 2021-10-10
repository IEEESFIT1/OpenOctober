package com.example.newsfeed;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.bumptech.glide.Glide;

public class NewsDetailActivity extends AppCompatActivity {

    private String title, url, urlImage, desc, content;
    private TextView tv_title, tv_content, tv_subDesc;
    private ImageView iv_poster;
    private Button btn_readNews;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_news_detail);

        title = getIntent().getStringExtra("title");
        url = getIntent().getStringExtra("url");
        urlImage = getIntent().getStringExtra("urlImage");
        desc = getIntent().getStringExtra("desc");
        content = getIntent().getStringExtra("content");

        tv_title = findViewById(R.id.tv_title);
        tv_content = findViewById(R.id.tv_content);
        tv_subDesc = findViewById(R.id.tv_subDesc);
        iv_poster = findViewById(R.id.iv_news);
        btn_readNews = findViewById(R.id.readNews);

        tv_title.setText(title);
        if(content==null && desc==null){
            tv_subDesc.setText("Visit our website for more detailed information");
            tv_content.setText("");
        }
        else if(content==null && desc!=null){
            tv_subDesc.setText(desc);
            tv_content.setText("Visit our website for more detailed information");
        }
        else if(desc==null && content!=null){
            tv_subDesc.setText("Visit our website for more detailed information");
            tv_content.setText("");
        }
        else if(content!=null && desc!=null){
            tv_subDesc.setText(desc);
            tv_content.setText(content);
        }

        if(urlImage==null){
            iv_poster.setImageResource(R.drawable.no_image);
        }
        else{
            Glide.with(this).load(urlImage).into(iv_poster);
        }


        btn_readNews.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse(url));
                startActivity(intent);
            }
        });
    }
}
