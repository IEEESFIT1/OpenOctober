package com.example.newsfeed;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.bumptech.glide.Glide;

import java.util.ArrayList;


public class CategoryAdapter extends RecyclerView.Adapter<CategoryAdapter.CategoryViewHolder> {

    private ArrayList<CategoryModel> categoryModelArrayList;
    private Context context;
    private OnCategoryListener onCategoryListener;  //creating reference of the interface created manually in this class for listening to click of horizontal recycler view item

    public CategoryAdapter(ArrayList<CategoryModel> categoryModelArrayList, Context context, OnCategoryListener onCategoryListener) {
        this.categoryModelArrayList = categoryModelArrayList;
        this.context = context;
        this.onCategoryListener = onCategoryListener;
    }

    @NonNull
    @Override
    public CategoryAdapter.CategoryViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.category_items,parent,false);
        return new CategoryViewHolder(view, onCategoryListener);
    }

    @Override
    public void onBindViewHolder(@NonNull CategoryAdapter.CategoryViewHolder holder, int position) {
        holder.categoryName.setText(categoryModelArrayList.get(position).getCategoryName());
        Glide.with(context).load(categoryModelArrayList.get(position).getCategoryImage()).into(holder.poster);
    }

    @Override
    public int getItemCount() {
        return categoryModelArrayList.size();
    }

    public class CategoryViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener {

        private TextView categoryName;
        private ImageView poster;
        private OnCategoryListener onCategoryListener;

        public CategoryViewHolder(@NonNull View itemView, OnCategoryListener onCategoryListener) {
            super(itemView);
            categoryName = itemView.findViewById(R.id.tv_category);
            poster = itemView.findViewById(R.id.iv_category);
            this.onCategoryListener = onCategoryListener;

            itemView.setOnClickListener(this);  //setting onClickListener on each item in the category recycler view
        }

        @Override
        public void onClick(View v) {
            //calling the method 'OnCategoryClick' of the interface (this method is defined in mainActivity). So that method will be triggered when ever any category item is clicked
            onCategoryListener.OnCategoryClick(getAdapterPosition());
        }
    }

    //interface created manually for listening to the click of the categories (horizontal recycler view)
    public interface OnCategoryListener{
        void OnCategoryClick(int position);
    }
}
