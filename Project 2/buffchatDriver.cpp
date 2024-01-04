//buffchatDriver.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2pt2 - Question 1

//Inclusions
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include "Buffchat.h"

using std::cout;
using std::endl;
using std::string;
using std::getline;

//Main
int main()
{

    //Create Buffchat object with default constructor
    Buffchat buff;

    //Testing encapsulation methods for default buff object
    cout << buff.getNumPosts() << endl;
    cout << buff.getNumUsers() << endl;
    cout << buff.getPostSize() << endl;
    cout << buff.getUserSize() << endl;

    //Testing readPosts and readLikes function
    buff.readPosts("posts.txt");
    buff.readLikes("users.txt");

    //Read file that doesn't exist
    buff.readPosts("DoesNotExist.txt");
    buff.readLikes("DoesNotExist.txt");

    //Checking new users and posts values
    cout << buff.getNumPosts() << endl;
    cout << buff.getNumUsers() << endl;

    //Testing printPostsByYear function
    buff.printPostsByYear("20");

    //Testing findTagUser function
    buff.findTagUser("chip");

    //Adding new post
    string newPostBody = "Ralph = goat";
    string newPostAuthor = "Ralph";
    string newPostDate = "03/23/2023";
   
    cout << "Num Posts before: " << buff.getNumPosts() << endl;
    buff.addPost(newPostBody, newPostAuthor, newPostDate);
    cout << "Num Posts after: " << buff.getNumPosts() << endl;

    //Testing printPopularPosts function - more than 50 likes for year 20
    buff.printPopularPosts(50, "20");

    //printPopularPosts test when no posts meet criteria
    buff.printPopularPosts(581, "20");

    //Find least active user
    User leastActiveUser = buff.findLeastActiveUser();
    cout << "Least active user: " << leastActiveUser.getUsername() << endl;

    //Counts the number of unique likes
    cout << "Unique likes for author bookworm43: " << buff.countUniqueLikes("bookworm43") << endl;

    //Return
    return 0;
}