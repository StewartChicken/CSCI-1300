//Buffchat.h

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2pt2 - Question 1

#include <iostream>
#include "User.h"
#include "Post.h"

#ifndef Buffchat_H
#define Buffchat_H

using std::string;
using std::cout; 
using std::cin;
using std::endl;

class Buffchat
{
    private:
        //Max posts/users
        const static int posts_size_ = 50;
        const static int users_size_ = 50;

        //Post/User array
        Post posts_[posts_size_];
        User users_[users_size_];

        //Current posts/users stored
        int num_posts_;
        int num_users_;

    public:
        //Default constructor
        Buffchat();

        //Getter methods
        int getPostSize();
        int getUserSize();
        int getNumPosts();
        int getNumUsers();

        //Enters posts into an array from a file
        int readPosts(string);


        //Prints all the posts from a given year
        void printPostsByYear(string);

        //Enters users into an array from file
        int readLikes(string);

        int getLikes(string, string);

        //Finds all users with a specific tag
        void findTagUser(string);

        //Adds new post to first empty slot in posts_ array
        bool addPost(string, string, string);

        //Prints all the posts of a given year that exceed a certain number of likes
        void printPopularPosts(int, string);

        //Finds user with fewest post views
        User findLeastActiveUser();

        //counts the number of unique likes
        int countUniqueLikes(string);

        //Compares two strings
        bool compareStrings(string, string);

        //Split function
        int split(string, char, string[], int);

};

#endif