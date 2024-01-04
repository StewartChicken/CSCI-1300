//findTagUserDriver.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2 - Question 7

//Inclusions
#include <iostream>
#include <cassert>
#include <string>
#include "User.h"

using std::string;
using std::cout;
using std::endl;

//Function declaration(s)
void findTagUser(string, User[], int);
bool compareStrings(string, string);

//main
int main()
{

    //Test cases
    User user_array[5];
    int likes1[3] = {1, 0, -1};
    int likes2[3] = {4, 5, 0};
    user_array[0] = User("foliwn22", likes1, 3);
    user_array[1] = User("joh23k", likes2, 3);
    user_array[2] = User("harry02", likes2, 3);
    user_array[3] = User("luwkml1", likes2, 3);
    user_array[4] = User("fwollow3", likes1, 3);

    //Test case 1
    //Expected output
    //Here are all the usernames that contain wkm
    //luwkml1
    //findTagUser("wkm", user_array, 5);

    //Test case 2
    //Expected output
    //Here are all the usernames that contain o
    //foliwn22
    //joh23k
    //fwollow3
        
    //findTagUser("o", user_array, 5);

    //Test case 3
    //Expected output
    //No matching user found

    //findTagUser("none", user_array, 5);

    //Test case 4
    //Expected output
    //No users are stored in the database

    //findTagUser("o", user_array, 0);

    return 0;
}

//findTagUser definition
/**
 * @brief 
 * If the number of users is stored, print that there are no users in the database
 * Create boolean variable called "found" that determines if the tag has been found for the first time
 * Create array of found users to prevent duplicates
 * Iterates through every user and every username to look for the tag
 * If the tag is found, check for duplicates and then add to the found users array
 * Print out all usernames that contain the tag
 * If no users with the matching tag are found, print that no users were found
 * 
 * @param username_tag 
 * @param users 
 * @param num_users_stored 
 */
void findTagUser(string username_tag, User users[], int num_users_stored)
{

    //If no users are stored
    if(num_users_stored <= 0)
    {
        cout << "No users are stored in the database\n";
        return;
    }

    //Variable to determine when the header should be printed
    bool found = false;
    //Dynamic array that can at most store the number of users stored
    string *users_with_tag = new string[num_users_stored];

    //Iterate through each user
    for(int i{}; i < num_users_stored; i ++)
    {   
        //Iterate through each character
        for(int j{}; j <= users[i].getUsername().length() - username_tag.length(); j ++)
        {
            //Check if character matches and if its the first instance of a match
            if(compareStrings(users[i].getUsername().substr(j, username_tag.length()), username_tag) && !found)
            {
                //Prints match
                cout << "Here are all the usernames that contain " << username_tag << "\n";
                cout << users[i].getUsername() << "\n";
                users_with_tag[i] = users[i].getUsername();
                found = !found;
                break;
            //If header was already printed and another match is found
            }else if(compareStrings(users[i].getUsername().substr(j, username_tag.length()), username_tag))
            {
                //Check for duplicate values
                bool duplicate = false;
                for(int k{}; k < num_users_stored; k ++)
                {
                    if(compareStrings(users[i].getUsername(), users_with_tag[k]))
                    {
                        duplicate = true;
                        break;
                    }
                }
                //Prints user if it was not a duplicate
                if(!duplicate)
                {
                    cout << users[i].getUsername() << "\n";
                }
                break;
                
            }
        }
    }

    //If no tag found, prints no users found
    if(!found)
    {
        cout << "No matching user found\n";
    }
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
