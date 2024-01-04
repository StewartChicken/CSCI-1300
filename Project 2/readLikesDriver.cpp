//readLikesDriver.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2 - Question 5

//Includes
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <iomanip>
#include "User.h"

using std::cout;
using std::string;
using std::ifstream;
using std::getline;
using std::endl;

//Function declaration(s)
int readLikes(string, User[], int, int, int);
int split(string, char, string[], int);

//Main
int main()
{

    //Test 1
    User users[10];
    int num_users_stored = 0;
    int users_arr_size = 10;
    int max_posts = 3;
    assert(readLikes("users_test.txt", users, num_users_stored, users_arr_size, max_posts) == 2);

    //Test 2
    User users1[10];
    int num_users_stored1 = 0;
    int users_arr_size1 = 10;
    int max_posts1 = 10;
    assert(readLikes("doesn't_exist.txt", users1, num_users_stored1, users_arr_size1, max_posts1) == -1);

    //Test 3
    User users2[2];
    int likes1[3] = {1, 3, 0};
    User u1 = User("bookworm43", likes1, 3);
    users2[0] = u1; // insert first object at index 0

    // use setters to update the object at index 1 in the users array
    users2[1].setUsername("roboticscu");
    users2[1].setLikesAt(0,-1);
    users2[1].setLikesAt(1,2);
    users2[1].setLikesAt(2,4);
    int num_users_stored2 = 2;
    int users_arr_size2 = 2;
    int max_posts2 = 3;

    assert(readLikes("users_test2.txt", users2, num_users_stored2, users_arr_size2, max_posts2) == -2);

    cout << "Passed all tests\n";
    
    return 0;
}

//readLikes function definition
/*
 * @brief Loads 
 * Loads an array of user objects with new users from text file
 * If array is full, returns -2
 * If file fails to load, returns -1
 * Loads file in and reads it line by line -- if a line is blank, skips the line
 * Creates new user objects with a username and each post that they liked
 * 
 * @param fileName (string)
 * @param users (array of User objects)
 * @param num_users_stored (int)
 * @param users_arr_capacity (int)
 * @param max_posts (int)
 * @return (int) - num of users in the array
 */
int readLikes(string fileName, User users[], const int num_users_stored, const int users_arr_capacity, const int max_posts)
{

    //Contains current line
    string line;

    //File stream
    ifstream fin;

    //Open input file
    fin.open(fileName); 

    //Tracks current location in users[] array
    int currUserIndex = num_users_stored;

    //Tracks the final number of users stored
    int numUsersStored = num_users_stored;

    //Counts the number of new users or the number of lines
    int numNewUsers = 0;

    //If array is full, return -2
    if(num_users_stored == users_arr_capacity)
    {
        return -2;
    }

    //If fails to open file
    if (fin.fail())
    {
        //cout << "Could not open file." << endl;
        return -1;
    }

    while (!fin.eof()) //Continues to loop while there is data in the text file
    {
        ///First index contains the username, every index after that contains the number of likes
        string *currUserArr = new string[max_posts + 1];

        //Gets line
        getline(fin, line);

        //If line is blank
        if(line.length() == 0)
        {
            continue;
        }

        //If the users array is full
        if(currUserIndex == users_arr_capacity)
        {
            break;
        }

        //Splits each line into an array containint the username and number of likes
        int num = split(line, '|', currUserArr, max_posts + 1);

        //Increments the number of users
        numNewUsers ++;

        //Changes current user's username
        users[currUserIndex].setUsername(currUserArr[0]);

        //Changes current user's likes
        for(int i{}; i < max_posts; i ++)
        {
            users[currUserIndex].setNumPosts(max_posts);
            users[currUserIndex].setLikesAt(i, stoi(currUserArr[i + 1]));
        }

        //Increments current index
        currUserIndex ++;

    }

    //Returns the number of users in the array
    return numUsersStored + numNewUsers;
}


//split function definition
//Splits each string at a given splitter character and stores each part in a new array
//Will iterate through each string in search of the splitter character and split
//the string/add the substring to the new array until the array is full
//If the length of the initial string is 0, returns 0
//If there are more splits than can be stored in the array, returns -1
//parameters: string input, char splitter, string array, int size
//returns int (number of splits)
int split(string mainString, char splitter, string array[], int size)
{

    //Number of splits
    int split = 1;

    //Current index of traversal for array of strings
    int currIndex = 0;

    //If empty string, return 0
    if(mainString.length() == 0)
    {
        return 0;
    }

    //Loops through each character of the mainString for the same number of times as the "size" parameter
    for(int i{}; i < size; i ++)
    {
        for(int j = 0; j < mainString.length(); j ++)
        {
            //If character is delimiter
            if(mainString[j] == splitter)
            {
                //Adds sliced section of string to array
                array[i] = mainString.substr(0, j);
                //Modfies mainString
                mainString = mainString.substr(j + 1, mainString.length() - j);
                //Incrememnts number of splits and current index
                split ++;
                currIndex ++;
                break;
            }

        }

    }

    //Last element is equal to remainder of mainString
    array[currIndex] = mainString;

    //If there are mores splits than the size of the array, return -1
    if(split > size){
        return -1;
    }

    //Returns split
    return split;
}
