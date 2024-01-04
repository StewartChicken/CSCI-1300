//project2pt1.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2 - Question 8

//Inclusions
#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include "User.h"
#include "Post.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::ifstream;

//Function declarations

//User prompt functions
void printMainScreen();
int readPostsPrompt(Post[], int);
void printPostsByYearPrompt(Post[], int);
int readLikesPrompt(User[], int);
void getLikesPrompt(Post[], int, User[], int);
void tagPrompt(User[], int);

//Application functionality functions
int readPosts(string, Post[], int, int);
void printPostsByYear(Post posts[], string, int);
int readLikes(string, User[], const int, const int, const int);
int getLikes(string , Post[], int, string, User[], int);
void findTagUser(string, User[], int);

//Helper functions
int split(string, char, string array[], int);
bool compareStrings(string, string);


//main
int main()
{
    //Main menu user input
    int userInput;

    //Post and User arrays
    Post posts[50];
    User users[50];

    //Initial number of posts and users stored
    int num_posts_stored = 0;
    int num_users_stored = 0;

    
    //Begin user prompts
    while(userInput != 6)
    {   
        //Menu screen prompt
        printMainScreen();
        cin >> userInput;

        //User input options
        switch(userInput)
        {
            case 1:
                //Read posts
                num_posts_stored = readPostsPrompt(posts, num_posts_stored);
                break;
            case 2:
                //Prints posts by year
                printPostsByYearPrompt(posts, num_posts_stored);
                break;
            case 3:
                //reads likes
                num_users_stored = readLikesPrompt(users, num_users_stored);
                break;
            case 4:
                //Gets likes prompt
                getLikesPrompt(posts, num_posts_stored, users, num_users_stored);
                break;
            case 5:
                //Tag prompt
                tagPrompt(users, num_users_stored);
                break;
            case 6:
                //Exit case
                cout << "Good bye!\n";
                break;
            default:
                //Invalid input case
                cout << "Invalid input.\n";
                continue;
        };
    }

    return 0;
}

//printMainScreen function definition
void printMainScreen()
{
    cout << "======Main Menu======\n1. Read Posts\n2. Print Posts By Year\n3. Read Likes\n4. Get Likes\n5. Find users with matching tag\n6. Quit\n";
}

//readPostsPrompt function definition
//Prompts user to enter file name
//Informs user what the program has done with the file
//Parameters : array of post objects
//return type : integer (number of files stored)
int readPostsPrompt(Post posts[], int num_posts_stored)
{
    //Will store the user input file name
    string fileName;
    
    //User prompt
    cout << "Enter a post file name:\n";
    cin >> fileName;

    //Number of posts stored
    int value = readPosts(fileName, posts, num_posts_stored, 50);

    //User information based on the value 
    switch(value)
    {
        case -1:
            cout << "File failed to open. No posts saved to the database.\n";
            return num_posts_stored;
        case -2:
            cout << "Database is already full. No posts were added.\n";
            return 50;
        case 50:
            cout << "Database is full. Some posts may have not been added.\n";
            return 50;
        default:
            cout << "Total posts in the database: " << value << "\n";
            break;
    };

    //Returns number of posts stored
    return value;

}

//readPosts definition
//Checks if the post array is already full - if it is, 
// returns -2
//If the file can't be opened, returns -1
//Reads text file line by line for new post data
//Parses the data using the split funciton and adds
// each line of data to its own Post object in the posts array
//If the end of the array is reached, stops adding data
//Returns the number of posts in the post array
//Parameters : string, Post[], int, int
//Return type: int
int readPosts(string fileName, Post posts[], int num_posts_stored, int post_arr_size)
{
    //Current line
    string line;

    //File input stream
    ifstream fin;   

    //Number of posts in system
    int numPosts = num_posts_stored;

    //Open input file
    fin.open(fileName); 

    //If posts array is already full
    if(num_posts_stored == post_arr_size)
    {
        return -2;
    }

    //If file can't be loaded
    if (fin.fail())
    {
        //cout << "Could not open file." << endl;
        return -1;
    }
    
    while (!fin.eof()) //Continues to loop while there is data in the text file
    {

        //Stores the individual componenets of a post object when read from file
        string arr[4];

        //Gets line
        getline(fin, line);
    
        //Skips blank lines
        if(line.length() == 0)
        {
            continue;
        }
        
        //As long as the posts array isn't full
        if(numPosts < post_arr_size)
        {   
            //Checks validity of each line
            //If line is valid, assigns values to post object
            if(split(line, '|', arr, 4) == 4)
            {
                
                //Creates post object at the current array index
                posts[numPosts] = Post();

                //Assigns values of current line
                posts[numPosts].setPostAuthor(arr[1]);
                posts[numPosts].setPostBody(arr[0]);
                posts[numPosts].setPostDate(arr[3]);
                posts[numPosts].setPostLikes(stoi(arr[2]));

                //Increments the number of posts
                numPosts ++;
            }
        }
        else
        {
            //If the number of posts is greater than or equal to the array size, breaks loop
            break;
        }

    } 
    
    //Close file
    fin.close();
    
    //Return number of posts in array
    return numPosts;
    
}

//printPostsByYearPrompt definition
//prints the stored posts from a given year based on a user input
void printPostsByYearPrompt(Post posts[], int num_posts_stored)
{

    string year;

    cout << "Enter the year(YY):\n";
    cin >> year;

    printPostsByYear(posts, year, num_posts_stored);
}

//printPostsByYear function definition
//If the number of posts stored is less than or equal to zero, 
// prints "No posts stored"
//Iterates through posts array and looks for matching years
//If matching years are found, prints the list of posts
//If none are found, prints that none were found
//Paremeters : array of Post objects, string, int
//Return type : void
void printPostsByYear(Post posts[], string year, int numPostsStored)
{

    //Empty post array check
    if(numPostsStored <= 0)
    {
        cout << "No posts are stored\n";
        return;
    }

    //If a match is initially found. Allows the code to determine when to 
    //print a title for the list of posts
    bool found = false;

    //Iterates through all posts
    for(int i{}; i < numPostsStored; i ++)
    {
        //Checks if matching year is the first one found
        if((posts[i].getPostDate().substr(6, 2) == year) && !found)
        {
            found = true;
            cout << "Here is a list of posts for year " << year << "\n";
            cout << posts[i].getPostBody() << "\n";
        }
        //Checks if a year is matching after the first one was found
        else if(posts[i].getPostDate().substr(6, 2) == year)
        {
            cout << posts[i].getPostBody() << "\n";
        }
    }

    //If none were found, prints that there were no posts for that year
    if(!found)
    {
        cout << "No posts stored for year " << year << "\n";
    }
}

//readLIkesPrompt definition
//Prompts user to enter a file name
//Inputs filename to readLikes function
//Parameters : Array of user objects, int
//Return type : int
int readLikesPrompt(User users[], int num_users_stored)
{

    string fileName;

    cout << "Enter a user file name:\n";
    cin >> fileName;

    int value = readLikes(fileName, users, num_users_stored, 50, 50);

    switch(value)
    {
        case -1:
            cout << "File failed to open. No users saved to the database.\n";
            return num_users_stored;
        case -2:
            cout << "Database is already full. No users were added.\n";
            return 50;
        case 50:
            cout << "Database is full. Some users may have not been added.\n";
            return 50;
        default:
            cout << "Total users in the database: " << value << "\n";
            break;
    };  

    return value;

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

            if(currUserArr[i + 1] != "")
            {
                users[currUserIndex].setLikesAt(i, stoi(currUserArr[i + 1]));
            }
            
        }

        //Increments current index
        currUserIndex ++;

    }

    //Returns the number of users in the array
    return numUsersStored + numNewUsers;
}

//getLikesPrompt definition
//Prompts user to input a post author and a username
//Inputs username and post author into the getLikes function
//Informs user of the output
//Parameters : Post array, int, User array, int
//Return type : void
void getLikesPrompt(Post posts[], int num_posts_stored, User users[], int num_users_stored)
{

    string postAuthor;
    string username;

    cout << "Enter a post author:\n";
    cin >> postAuthor;

    cout << "Enter a user name:\n";
    cin >> username;

    int value = getLikes(postAuthor, posts, num_posts_stored, username, users, num_users_stored);

    switch(value)
    {
        case 0:
            cout << username << " has not liked the post posted by " << postAuthor << "\n";
            break;
        case -1:
            cout << username << " has not viewed the post posted by " << postAuthor << "\n";
            break;
        case -2:
            cout << "Database is empty.\n";
            break;
        case -3:
            cout << username << " or " << postAuthor << " does not exist.\n";
            break;
        default:
            cout << username << " liked the post posted by " << postAuthor << " " << value << " times\n";
            break;

    };
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

//tagPrompt definition
//Prompts user to enter a tag
//Finds the users that contain the user input tag
//Parameters : array of user objects, int
//Return : void
void tagPrompt(User users[], int num_users_stored)
{

    string tag;

    cout << "Enter a tag:\n";
    cin >> tag;

    findTagUser(tag, users, num_users_stored);

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
