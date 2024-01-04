//Post.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2 - Question 1

#include <iostream>
#include "Post.h"

//Post class implementation

//Default Constructor
Post::Post()
{
    body_ = "";
    post_author_ = "";
    num_likes_ = 0;
    date_ = "";  
}

//Parameterized Constructor
Post::Post(std::string body, std::string author, int likes, std::string date)
{
    body_ = body;
    post_author_ = author;
    num_likes_ = likes;
    date_ = date;  
}

//Body encapsulation
std::string Post::getPostBody()
{
    return body_;
}
void Post::setPostBody(std::string body)
{
    body_ = body;
}

//Author encapsulation
std::string Post::getPostAuthor()
{
    return post_author_;
}
void Post::setPostAuthor(std::string author)
{
    post_author_ = author;
}

//Likes encapsulation
int Post::getPostLikes()
{
    return num_likes_;
}
void Post::setPostLikes(int likes)
{
    if(likes < 0)
    {
        return;
    }
    num_likes_ = likes;
}

//Date encapsulation
std::string Post::getPostDate()
{
    return date_;
}
void Post::setPostDate(std::string date)
{
    date_ = date;
}
