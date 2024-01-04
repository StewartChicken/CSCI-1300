//User.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2 - Question 4

#include "User.h"

//Default constructor
User::User()
{
    username_ = "";
    num_posts_ = 0;

    //All post's num likes set to -1
    for(int i{}; i < size_; i ++)
    {
        likes_[i] = -1;
    }
}
 
//Parameterized constructor
User::User(std::string username, int likes[], int num_posts)
{
    username_ = username;
    num_posts_ = num_posts;

    //Fills likes_ array with input array, then fills the rest with -1
    for(int i{}; i < num_posts; i ++)
    {
        likes_[i] = likes[i];
    }
    for(int i = num_posts; i < size_; i ++)
    {
        likes_[i] = -1;
    }
}

//Encapsulation methods

//Returns username
std::string User::getUsername()
{
    return username_;
}

//Changes username
void User::setUsername(std::string username)
{
    username_ = username;
}

//Returns a post's num likes
int User::getLikesAt(int index)
{
    if(index >= size_ || index < 0)
    {
        return -2;
    }

    return likes_[index];
}

//Changes numLikes at certain post id
bool User::setLikesAt(int index, int numLikes)
{
    if(numLikes < -1 || numLikes > 10)
    {
        return false;
    }

    if(index < 0 || index >= num_posts_)
    {
        return false;
    }

    likes_[index] = numLikes;
    return true;
}

//Returns number of posts in likes_ array
int User::getNumPosts()
{
    return num_posts_;
}

//Changes the number of posts 
void User::setNumPosts(int numPosts)
{
    if(numPosts < 0 || numPosts > 50)
    {
        return;
    }
    num_posts_ = numPosts;
}

//Returns size of array
int User::getSize()
{
    return size_;
}

