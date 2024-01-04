//getLikesDriver.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2 - Question 6

//Inclusions
#include <iostream>
#include <cassert>
#include "Post.h"
#include "User.h"

using std::cout;
using std::string;
using std::endl;

//Function declaration(s)
int getLikes(string, Post[], int, string, User[], int);
bool compareStrings(string, string);

int main()
{
    //Test case
    //Creates three posts
    Post posts[3];
    Post my_post_1 = Post("Hello!","Xuefei", 10, "10/02/22");
    posts[0] = my_post_1;
    Post my_post_2 = Post("new post","Morgan", 9, "10/04/22");
    posts[1] = my_post_2;
    Post my_post_3 = Post("Hey!","Jot", 10, "10/05/22");
    posts[2] = my_post_3;

    User users[2];
    // user 1
    int likes1[3] = {1, 3, 2};
    User u1 = User("bookworm43", likes1, 3);
    users[0] = u1; // insert first object at index 0
    
    assert(getLikes("Xuefei", posts, 3, "bookworm43", users, 2) == 1);
    assert(getLikes("Morgan", posts, 3, "bookworm43", users, 2) == 3);
    assert(getLikes("Jot", posts, 3, "bookworm43", users, 2) == 2);
    assert(getLikes("HE", posts, 3, "bookworm43", users, 2) == -3);
    assert(getLikes("Jot", posts, 3, "ron", users, 2) == -3);

    //Empty array test cases
    User empty_users[1] = {};
    Post empty_posts[1] = {};
    
    assert(getLikes("Xuefei", posts, 3, "bookworm43", empty_users, 0) == -2);
    assert(getLikes("Xuefei", empty_posts, 3, "bookworm43", users, 0) == -2);

    cout << "All tests passed.\n";

    return 0;
}

//getLikes function definition
/**
 * @brief Determines the number of times the user "username" liked a post by the author
 * If the number of posts stored or the number of users stored is less than 0, return -2
 * Finds the index of the post author in question
 * Finds the index of the user in question
 * If either the author or the user doesn't exist, returns -3 error code
 * Returns the number of times a user liked a certain authors post
 * 
 * @param post_author - string
 * @param posts - array of Post objects
 * @param num_posts_stored - number of posts stored
 * @param username - string
 * @param users - array of user objects
 * @param num_users_stored -number of users stored
 * @return int - number of likes
 */
int getLikes(string post_author, Post posts[], int num_posts_stored, string username, User users[], int num_users_stored)
{

    //Returns -2 error code of empty arrays are entered
    if(num_posts_stored <= 0 || num_users_stored <= 0)
    {
        return -2;
    }

    //Index of author in question - initially set to -3 
    int author_post_index = -3;
    
    //Iterates through array of posts and finds the index of the post_author
    for(int i{}; i < num_posts_stored; i ++)
    {
        //If names are equal
        if(compareStrings(posts[i].getPostAuthor(), post_author))
        {
            //Sets post index to 
            author_post_index = i;
            break;
        }
    }

    //If the author was not found in the posts array, returns -3 error code
    if(author_post_index == -3)
    {
        return author_post_index;
    }

    //index of the liker of the post
    int user_index = -3;

    //Searches for the index of the user who liked the post
    for(int i{}; i < num_users_stored; i ++)
    {
        if(compareStrings(users[i].getUsername(), username))
        {
            user_index = i;
            break;
        }
    }

    //If user was not found, return -3 error code
    if(user_index == -3)
    {
        return user_index;
    }

    //Returns the number of likes for a specific post
    return(users[user_index].getLikesAt(author_post_index));

}


//compareStrings function definition
//if the string lengths are not equal, return false
//iterate through strings - if one character doesn't match, return false
//otherwise, return true
//Parameters: string, string
//Return type: boolean
bool compareStrings(string a, string b)
{
    if(a.length() != b.length())
    {
        return false;
    }

    for(int i{}; i < a.length(); i ++)
    {
        if(a[i] != b[i])
        {
            return false;
        }
    }

    return true;
}
