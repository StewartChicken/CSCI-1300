//userDriver.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2 - Question 4

//Includes
#include <iostream>
#include <cassert>
#include "User.h"

using std::cout;
using std::endl;
using std::string;

//Compares two strings - for assert statements
bool compareStrings(string, string);

//Main
int main()
{

    //Testing default constructor
    /*User user1;
    
    cout << "user1\n";
    cout << "Num Posts:" << user1.getNumPosts() << "\n";
    cout << "Num Likes at post 1: " << user1.getLikesAt(1) << "\n";
    cout << "Username:" << user1.getUsername() << "\n";
    cout << "\nuser1 updated\n";

    //Testing functions
    user1.setNumPosts(5);
    user1.setLikesAt(1, 5);
    user1.setUsername("Robb132");

    cout << "Num Posts:" << user1.getNumPosts() << "\n";
    cout << "Num Likes at post 1: " << user1.getLikesAt(1) << "\n";
    cout << "Username:" << user1.getUsername() << "\n\n";

    //Testing parameterized constructor
    cout << "user2\n";
    string user2Username = "Edward153";
    int user2Likes[8] = {5, 1, 4, 0, 1, 3, -1, 9};
    int numPosts = 8;

    User user2(user2Username, user2Likes, numPosts);

    cout << "Num Posts:" << user2.getNumPosts() << "\n";
    cout << "Num Likes at post 10: " << user2.getLikesAt(2) << "\n";
    cout << "Username: " << user2.getUsername() << "\n\n";

    */

    //More thorough function testing
    string user3Username = "Username56";
    int user3Likes[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int user3NumPosts = 20;
    User user3(user3Username, user3Likes, user3NumPosts);

    //Testing username functionality
    assert(compareStrings(user3.getUsername(), "Username56") == true);
    user3.setUsername("NewUsername56");
    assert(compareStrings(user3.getUsername(), "NewUsername56") == true);

    //Tests user getLikesAt function
    for(int i{}; i < 20; i ++)
    {
        assert(user3.getLikesAt(i) == i);
    }

    assert(user3.getLikesAt(22) == -1);
    assert(user3.getLikesAt(55) == -2);
    assert(user3.getLikesAt(-5) == -2);

    //Tests uer setLikesAt function
    assert(user3.setLikesAt(5, -10) == false);
    assert(user3.setLikesAt(5, 70) == false);
    assert(user3.setLikesAt(-1, 5) == false);
    assert(user3.setLikesAt(35, 6) == false);
    assert(user3.setLikesAt(8, 5) == true);

    //Tests getNumPosts function
    assert(user3.getNumPosts() == 20);

    //Tests setNumPosts function
    user3.setNumPosts(100);
    assert(user3.getNumPosts() == 20);

    user3.setNumPosts(25);
    assert(user3.getNumPosts() == 25);

    //Tests getSize function
    assert(user3.getSize() == 50);


    cout << "All tests passed\n";
    return 0;
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