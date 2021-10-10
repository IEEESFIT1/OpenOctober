package com.example.newsfeed;

import retrofit2.Call;
import retrofit2.http.GET;
import retrofit2.http.Url;

public interface RetrofitAPI {
    //here we are not doing Call<List<NewsModel>> in return type bcz we have already made another class for 'Articles' which will handle that case
    @GET
    Call<NewsModel> getNewsFeed (@Url String url);

    @GET
    Call<NewsModel> getNewsByCategory (@Url String url);
}
