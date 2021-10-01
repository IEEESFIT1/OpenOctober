package com.kartikey.bookhub.model

data class Book(
    var bookId: String,
    var bookName: String,
    var bookAuthor: String,
    var bookRating: String,
    var bookPrice: String,
    //book image is int as we refer to it via id
    var bookImage: String

)
