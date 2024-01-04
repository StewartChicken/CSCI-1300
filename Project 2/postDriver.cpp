//postDriver.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2 - Question 1

//Includes
#include <iostream>
#include "Post.h"

using std::cout;
using std::endl;

//Main
int main()
{
    //Default constructor test
    Post post1;
    cout << post1.getPostAuthor() << endl;
    cout << post1.getPostBody() << endl;
    cout << post1.getPostDate() << endl;
    cout << post1.getPostLikes() << endl;

    //Tests functions
    post1.setPostAuthor("Ron");
    post1.setPostBody("My Post");
    post1.setPostDate("03/28/2023");
    post1.setPostLikes(300);

    cout << post1.getPostAuthor() << endl;
    cout << post1.getPostBody() << endl;
    cout << post1.getPostDate() << endl;
    cout << post1.getPostLikes() << endl;

    Post post2("My first post!", "Donald", 591, "02/18/2023");

    cout << post2.getPostAuthor() << endl;
    cout << post2.getPostBody() << endl;
    cout << post2.getPostDate() << endl;
    cout << post2.getPostLikes() << endl;

    return 0;
}