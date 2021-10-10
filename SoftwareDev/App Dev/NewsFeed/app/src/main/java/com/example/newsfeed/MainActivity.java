package com.example.newsfeed;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.RecyclerView;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ProgressBar;
import android.widget.Toast;

import java.util.ArrayList;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

//implementing the interface which is created manually in 'NewsAdapter' to detect click of item in recycler view
public class MainActivity extends AppCompatActivity implements NewsAdapter.OnNewsListener, CategoryAdapter.OnCategoryListener {

    private RecyclerView news_rv, category_rv;
    private ProgressBar progressBar;
    private ArrayList<CategoryModel> categoryModelArrayList;
    private ArrayList<Articles> articlesArrayList;
    private CategoryAdapter categoryAdapter;
    private NewsAdapter newsAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        news_rv = findViewById(R.id.rv_news);
        category_rv = findViewById(R.id.rv_categories);
        progressBar = findViewById(R.id.progressBar);
        categoryModelArrayList = new ArrayList<>();
        articlesArrayList = new ArrayList<>();
        categoryAdapter = new CategoryAdapter(categoryModelArrayList,this,this::OnCategoryClick);
        newsAdapter = new NewsAdapter(articlesArrayList,this,this::OnNewsClick);
        news_rv.setAdapter(newsAdapter);
        category_rv.setAdapter(categoryAdapter);
        getCategories();
        getNews("All"); //by default data for 'All' news category will be shown
        newsAdapter.notifyDataSetChanged();

    }


    private void getCategories(){
        categoryModelArrayList.add(new CategoryModel("All",""));
        categoryModelArrayList.add(new CategoryModel("Technology","https://images.unsplash.com/photo-1526374965328-7f61d4dc18c5?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxzZWFyY2h8MTN8fHRlY2hub2xvZ3l8ZW58MHx8MHx8&auto=format&fit=crop&w=600&q=60"));
        categoryModelArrayList.add(new CategoryModel("Science","https://images.unsplash.com/photo-1564325724739-bae0bd08762c?ixid=MnwxMjA3fDB8MHxzZWFyY2h8M3x8c2NpZW5jZXxlbnwwfHwwfHw%3D&ixlib=rb-1.2.1&auto=format&fit=crop&w=600&q=60"));
        categoryModelArrayList.add(new CategoryModel("Sports","https://images.unsplash.com/photo-1484482340112-e1e2682b4856?ixid=MnwxMjA3fDB8MHxzZWFyY2h8MTJ8fHNwb3J0c3xlbnwwfHwwfHw%3D&ixlib=rb-1.2.1&auto=format&fit=crop&w=600&q=60"));
        categoryModelArrayList.add(new CategoryModel("General","https://images.unsplash.com/photo-1500462918059-b1a0cb512f1d?ixid=MnwxMjA3fDB8MHxzZWFyY2h8NTN8fGdlbmVyYWx8ZW58MHx8MHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=600&q=60"));
        categoryModelArrayList.add(new CategoryModel("Business","https://images.unsplash.com/39/lIZrwvbeRuuzqOoWJUEn_Photoaday_CSD%20(1%20of%201)-5.jpg?ixid=MnwxMjA3fDB8MHxzZWFyY2h8Mnx8YnVzaW5lc3N8ZW58MHx8MHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=600&q=60"));
        categoryModelArrayList.add(new CategoryModel("Entertainment","https://images.unsplash.com/photo-1617870236116-d99becf1c6c0?ixid=MnwxMjA3fDB8MHxzZWFyY2h8Mnx8ZW50ZXJ0YWlubWVudCUyMGRpc3RyaWN0fGVufDB8fDB8fA%3D%3D&ixlib=rb-1.2.1&auto=format&fit=crop&w=600&q=60"));
        categoryModelArrayList.add(new CategoryModel("Health","https://images.unsplash.com/photo-1505751172876-fa1923c5c528?ixid=MnwxMjA3fDB8MHxzZWFyY2h8Nnx8aGVhbHRofGVufDB8fDB8fA%3D%3D&ixlib=rb-1.2.1&auto=format&fit=crop&w=600&q=60"));
        categoryAdapter.notifyDataSetChanged();  //to notify adapter that data has been changed
    }


    private void getNews(String category){
        progressBar.setVisibility(View.VISIBLE);
        articlesArrayList.clear();
        String categoryURL = "https://newsapi.org/v2/top-headlines?country=in&category="+ category +"&apiKey=7443ff471d264f37a74a7f3d7fd8f92e";
        String url = "https://newsapi.org/v2/top-headlines?country=in&excludeDomains=stackoverflow.com&sortBy=publishedAt&language=en&apiKey=7443ff471d264f37a74a7f3d7fd8f92e";
        String BASE_URL = "https://newsapi.org/";

        //creating object of retrofit and adding the url
        Retrofit retroFit = new Retrofit.Builder().baseUrl(BASE_URL).addConverterFactory(GsonConverterFactory.create()).build();

        //The JSON data will be converted to 'RetrofitAPI.class' type
        RetrofitAPI api = retroFit.create(RetrofitAPI.class);

        //creating a call of NewsModel class
        Call<NewsModel> call;

        if(category=="All"){
            //passing the method declared in the interface
            call = api.getNewsFeed(url);
        }
        else {
            call = api.getNewsByCategory(categoryURL);
        }

        //enqueuing the call and receiving the response
        call.enqueue(new Callback<NewsModel>() {                                                 
            @Override
            public void onResponse(Call<NewsModel> call, Response<NewsModel> response) {
                NewsModel newsModel = response.body();
                progressBar.setVisibility(View.GONE);
                ArrayList<Articles> articles = newsModel.getArticles();
                for(int i=0;i<articles.size();i++){
                    articlesArrayList.add(new Articles(articles.get(i).getTitle(),
                            articles.get(i).getDescription(),articles.get(i).getUrl(),
                            articles.get(i).getUrlToImage(),articles.get(i).getContent(),articles.get(i).getPublishedAt()));
                }
                newsAdapter.notifyDataSetChanged();
            }

            @Override
            public void onFailure(Call<NewsModel> call, Throwable t) {
                Toast.makeText(MainActivity.this,"Failed to get news",Toast.LENGTH_SHORT).show();
            }
        });
    }


    //method of 'OnNewsListener' interface of 'NewsAdapter' class
    @Override
    public void OnNewsClick(int position) {
        Intent intent = new Intent(this,NewsDetailActivity.class);
        intent.putExtra("title", articlesArrayList.get(position).getTitle());
        intent.putExtra("content", articlesArrayList.get(position).getContent());
        intent.putExtra("desc", articlesArrayList.get(position).getDescription());
        intent.putExtra("url", articlesArrayList.get(position).getUrl());
        intent.putExtra("urlImage", articlesArrayList.get(position).getUrlToImage());
        startActivity(intent);
    }

    //method of 'OnCategoryListener' interface of 'CategoryAdapter' class
    @Override
    public void OnCategoryClick(int position) {
        String category = categoryModelArrayList.get(position).getCategoryName();
        getNews(category);
    }
}