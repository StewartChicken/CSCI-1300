//project2pt2.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2pt2 - Question 10

//Inclusions
#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include "User.h"
#include "Post.h"
#include "Buffchat.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::ifstream;

//Function to print the main screen
void printMainScreen();

//User prompt functions
Buffchat readPostsPrompt(Buffchat);
void printPostsByYearPrompt(Buffchat);
Buffchat readLikesPrompt(Buffchat);
void getLikesPrompt(Buffchat);
void tagPrompt(Buffchat);
Buffchat addNewPostPrompt(Buffchat);
void printPopularPostsPrompt(Buffchat);
void leastActiveUserPrompt(Buffchat);
void uniqueLikesPrompt(Buffchat);


//Main
int main()
{

    //Main menu user input
    int userInput;

    //Buffchat object to be used by this program
    Buffchat buff;
    
    //Begin user prompts
    while(userInput != 10)
    {   
        //Menu screen prompt
        printMainScreen();
        cin >> userInput;

        //User input options
        switch(userInput)
        {
            case 1:
                //Read posts
                buff = readPostsPrompt(buff);
                break;
            case 2:
                //Prints posts by year
                printPostsByYearPrompt(buff);
                break;
            case 3:
                //reads likes
                buff = readLikesPrompt(buff);
                break;
            case 4:
                //Gets likes prompt
                getLikesPrompt(buff);
                break;
            case 5:
                //Tag prompt
                tagPrompt(buff);
                break;
            case 6:
                //Add post prompt
                buff = addNewPostPrompt(buff);
                break;
            case 7:
                printPopularPostsPrompt(buff);
                break;
            case 8:
                leastActiveUserPrompt(buff);
                break;
            case 9:
                uniqueLikesPrompt(buff);
                break;
            case 10:
                //Exit case
                cout << "Good bye!\n";
                break;
            default:
                //Invalid input case
                cout << "Invalid input.\n";
                break;
        };
    }

    //Return
    return 0;
}


//readPostsPrompt function definition
//Prompts user to enter file name
//Informs user what the program has done with the file
//Parameters : array of post objects
//return type : integer (number of files stored)
Buffchat readPostsPrompt(Buffchat buff)
{
    //Will store the user input file name
    string fileName;
    
    //User prompt
    cout << "Enter a post file name:\n";
    cin >> fileName;

    //Number of posts stored
    int value = buff.readPosts(fileName);

    //User information based on the value 
    switch(value)
    {
        //Fails to open file
        case -1:
            cout << "File failed to open. No posts saved to the database.\n";
            break;
        //Database is full
        case -2:
            cout << "Database is already full. No posts were added.\n";
            break;
        //Database reaches max capacity
        case 50:
            cout << "Database is full. Some posts may have not been added.\n";
            break;
        //All posts added
        default:
            cout << "Total posts in the database: " << value << "\n";
            break;
    };

    return buff;
}


//printPostsByYearPrompt definition
//prints the stored posts from a given year based on a user input
void printPostsByYearPrompt(Buffchat buff)
{
    //User input year
    string year;

    //User prompt
    cout << "Enter the year(YY):\n";
    cin >> year;

    //Function call
    buff.printPostsByYear(year);
}


//readLIkesPrompt definition
//Prompts user to enter a file name
//Inputs filename to readLikes function
//Parameters : Array of user objects, int
//Return type : int
Buffchat readLikesPrompt(Buffchat buff)
{
    //Filename
    string fileName;

    //User prompt for filename
    cout << "Enter a user file name:\n";
    cin >> fileName;

    //Read likes from user input filename
    int value = buff.readLikes(fileName);

    switch(value)
    {
        //File open fail
        case -1:
            cout << "File failed to open. No users saved to the database.\n";
            break;
        //Data base completely full
        case -2:
            cout << "Database is already full. No users were added.\n";
            break;
        //Database reaches max capacity after running
        case 50:
            cout << "Database is full. Some users may have not been added.\n";
            break;
        //All users successfully added
        default:
            cout << "Total users in the database: " << value << "\n";
            break;
    };  

    return buff;
}


//getLikesPrompt definition
//Prompts user to input a post author and a username
//Inputs username and post author into the getLikes function
//Informs user of the output
//Parameters : Post array, int, User array, int
//Return type : void
void getLikesPrompt(Buffchat buff)
{

    //User input author and username
    string postAuthor;
    string username;

    //User prompts
    cout << "Enter a post author:\n";
    cin >> postAuthor;

    cout << "Enter a user name:\n";
    cin >> username;

    //Function call
    int value = buff.getLikes(postAuthor, username);

    switch(value)
    {
        //0 likes by user of post author
        case 0:
            cout << username << " has not liked the post posted by " << postAuthor << "\n";
            break;
        //User hasn't seen the author's post
        case -1:
            cout << username << " has not viewed the post posted by " << postAuthor << "\n";
            break;
        //Empty database
        case -2:
            cout << "Database is empty.\n";
            break;
        //Invalid user input
        case -3:
            cout << username << " or " << postAuthor << " does not exist.\n";
            break;
        //Counts number of likes
        default:
            cout << username << " liked the post posted by " << postAuthor << " " << value << " times\n";
            break;

    };
}


//tagPrompt definition
//Prompts user to enter a tag
//Finds the users that contain the user input tag
//Parameters : array of user objects, int
//Return : void
void tagPrompt(Buffchat buff)
{
    //User input tag string
    string tag;

    //User prompt
    cout << "Enter a tag:\n";
    cin >> tag;

    //Function call
    buff.findTagUser(tag);
}

//Prompts the user to input a post body, author, and date
//Attempts to add new post to Buffchat object, informs 
//user of success or failure of attempt
//Parameter : Buffchat object
//Return : void
Buffchat addNewPostPrompt(Buffchat buff)
{
    //User input body, author, date
    string postBody;
    string postAuthor;
    string postDate;

    //User prompts
    cout << "Enter a post body:\n";
    cin >> postBody;

    cout << "Enter a post author:\n";
    cin >> postAuthor;

    cout << "Enter a date(mm/dd/yy):\n";
    cin >> postDate;

    //Tracks success of post addition
    bool success = buff.addPost(postBody, postAuthor, postDate);

    //If post was added successfully
    if(success)
    {
        cout << postAuthor << "'s post added successfully\n";
    }
    else
    {
        cout << "Database is already full. " << postAuthor << "'s post was not added.\n";
    }

    return buff;
}

//printPopularPostsPrompt function definition
//Takes user input for the minimum number of likes
//Takes user input for year
//Prints popular posts according to these criteria
//Parameter : Buffchat buff
//Return : void
void printPopularPostsPrompt(Buffchat buff)
{
    //User input minLikes and year
    int minLikes;
    string year;

    //User prompts
    cout << "Enter the minimum number of likes for posts:\n";
    cin >> minLikes;

    cout << "Enter the year(YY):\n";
    cin >> year;

    //Prints popular posts
    buff.printPopularPosts(minLikes, year);
}

//leastActiveUserPrompt function definition
//Assigns a temp user object to the return of buff's
//leastActiveUser() function. If tempUser is empty,
//inform the user that the database is empty.
//Print username of non-empty User object.
//Parameter : Buffchat object
//Return : void
void leastActiveUserPrompt(Buffchat buff)
{
    //User object return from Buffchat's findLeastActiveUser
    User tempUser = buff.findLeastActiveUser();

    //If function call returns an empty User object
    if(tempUser.getNumPosts() == 0)
    {
        cout << "Database is empty.\n";
        return;
    }

    //Prints least active user
    cout << tempUser.getUsername() <<" is the least active user\n";

}

//uniqueLikesPrompt function definition
//Calls countUniqueLikes for the input postAuthor
//If the function returns 0, informs user that there have been 0 likes
//If function returns -1, informs user that there have been no views
//If function returns -2, informs user that the database is empty
//Informs user of the number of unique likes a specific author has
//Parameter : Buffchat object
//Return type : void    
void uniqueLikesPrompt(Buffchat buff)
{
    //User input postAuthor
    string postAuthor;

    //User prompt
    cout << "Enter a post author:\n";
    cin >> postAuthor;

    //Numlikes
    int numLikes = buff.countUniqueLikes(postAuthor);

    switch(numLikes)
    {
        //0 Likes
        case 0:
            cout << "The posts posted by " << postAuthor << " have received 0 likes so far.\n";
            break;
        //0 views
        case -1:
            cout << "The posts posted by " << postAuthor << " have not been viewed by anyone.\n";
            break;
        //Empty database
        case -2:
            cout << "Database is empty.\n";
            break;
        //Displays number of unique likes
        default: 
            cout << "The posts posted by " << postAuthor << " have been liked by " << numLikes << " unique users.\n";
            break;

    };
    
}

//printMainScreen function definition
void printMainScreen()
{
    cout << "======Main Menu======\n1. Read Posts\n2. Print Posts By Year\n3. Read Likes\n4. Get Likes\n5. Find users with matching tag\n";
    cout << "6. Add a new post\n7. Print popular posts for a year\n8. Find least active user\n9. Find unique likes for a post author\n10. Quit\n";
}