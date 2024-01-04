//Buffchat.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2pt2 - Question 1

#include "Buffchat.h"
#include <iostream>
#include <string>
#include <fstream>

using std::ifstream;

//Default constructor
Buffchat::Buffchat()
{
    num_posts_ = 0;
    num_users_ = 0;
}

//Getter methods
int Buffchat::getPostSize()
{
    return posts_size_;
}

int Buffchat::getUserSize()
{
    return users_size_;
}

int Buffchat::getNumPosts()
{
    return num_posts_;
}

int Buffchat::getNumUsers()
{
    return num_users_;
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
int Buffchat::readPosts(string fileName)
{

    //Current line
    string line;

    //File input stream
    ifstream fin;   

    //Open input file
    fin.open(fileName); 

    //If posts array is already full
    if(num_posts_ == posts_size_)
    {
        return -2;
    }

    //If file can't be loaded
    if (fin.fail())
    {
        cout << "Could not open file." << endl;
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
        if(num_posts_ < posts_size_)
        {   
            //Checks validity of each line
            //If line is valid, assigns values to post object
            if(split(line, '|', arr, 4) == 4)
            {
                
                //Assigns values of current line
                posts_[num_posts_].setPostAuthor(arr[1]);
                posts_[num_posts_].setPostBody(arr[0]);
                posts_[num_posts_].setPostDate(arr[3]);
                posts_[num_posts_].setPostLikes(stoi(arr[2]));

                //Increments the number of posts
                num_posts_ ++;
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
    return num_posts_;
    
}


//printPostsByYear function definition
//If the number of posts stored is less than or equal to zero, 
// prints "No posts stored"
//Iterates through posts array and looks for matching years
//If matching years are found, prints the list of posts
//If none are found, prints that none were found
//Paremeters : array of Post objects, string, int
//Return type : void
void Buffchat::printPostsByYear(string year)
{

    //Empty post array check
    if(num_posts_ <= 0)
    {
        cout << "No posts are stored\n";
        return;
    }

    //If a match is initially found. Allows the code to determine when to 
    //print a title for the list of posts
    bool found = false;

    //Iterates through all posts
    for(int i{}; i < num_posts_; i ++)
    {
        //Checks if matching year is the first one found
        if((posts_[i].getPostDate().substr(6, 2) == year) && !found)
        {
            found = true;
            cout << "Here is a list of posts for year " << year << "\n";
            cout << posts_[i].getPostBody() << "\n";
        }
        //Checks if a year is matching after the first one was found
        else if(posts_[i].getPostDate().substr(6, 2) == year)
        {
            cout << posts_[i].getPostBody() << "\n";
        }
    }

    //If none were found, prints that there were no posts for that year
    if(!found)
    {
        cout << "No posts stored for year " << year << "\n";
    }
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
int Buffchat::readLikes(string fileName)
{

    //Contains current line
    string line;

    //File stream
    ifstream fin;

    //Open input file
    fin.open(fileName); 

    //Tracks current location in users[] array
    int currUserIndex = num_users_;

    //Counts the number of new users or the number of lines
    int numNewUsers = 0;

    //If array is full, return -2
    if(num_users_ == users_size_)
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
        string *currUserArr = new string[posts_size_ + 1];

        //Gets line
        getline(fin, line);

        //If line is blank
        if(line.length() == 0)
        {
            continue;
        }

        //If the users array is full
        if(currUserIndex == users_size_)
        {
            break;
        }

        //Splits each line into an array containint the username and number of likes
        int num = split(line, '|', currUserArr, posts_size_ + 1);

        //Increments the number of users
        numNewUsers ++;

        //Changes current user's username
        users_[currUserIndex].setUsername(currUserArr[0]);

        //Changes current user's likes
        for(int i{}; i < posts_size_; i ++)
        {
            users_[currUserIndex].setNumPosts(posts_size_);
            if(currUserArr[i + 1] != "")
            {
                users_[currUserIndex].setLikesAt(i, stoi(currUserArr[i + 1]));
            }
           
        }

        //Increments current index
        currUserIndex ++;

    }

    //Returns the number of users in the array
    num_users_ += numNewUsers;
    return num_users_;
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
int Buffchat::getLikes(string post_author, string username)
{

    //Returns -2 error code of empty arrays are entered
    if(num_posts_ <= 0 || num_users_ <= 0)
    {
        return -2;
    }

    //Index of author in question - initially set to -3 
    int author_post_index = -3;
    
    //Iterates through array of posts and finds the index of the post_author
    for(int i{}; i < num_posts_; i ++)
    {
        //If names are equal
        if(compareStrings(posts_[i].getPostAuthor(), post_author))
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
    for(int i{}; i < num_users_; i ++)
    {
        if(compareStrings(users_[i].getUsername(), username))
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
    return(users_[user_index].getLikesAt(author_post_index));

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
void Buffchat::findTagUser(string username_tag)
{

    //If no users are stored
    if(num_users_ <= 0)
    {
        cout << "No users are stored in the database\n";
        return;
    }

    //Variable to determine when the header should be printed
    bool found = false;
    //Dynamic array that can at most store the number of users stored
    string *users_with_tag = new string[num_users_];

    //Iterate through each user
    for(int i{}; i < num_users_; i ++)
    {   
        //Iterate through each character
        for(int j{}; j <= users_[i].getUsername().length() - username_tag.length(); j ++)
        {
            //Check if character matches and if its the first instance of a match
            if(compareStrings(users_[i].getUsername().substr(j, username_tag.length()), username_tag) && !found)
            {
                //Prints match
                cout << "Here are all the usernames that contain " << username_tag << "\n";
                cout << users_[i].getUsername() << "\n";
                users_with_tag[i] = users_[i].getUsername();
                found = !found;
                break;
            //If header was already printed and another match is found
            }else if(compareStrings(users_[i].getUsername().substr(j, username_tag.length()), username_tag))
            {
                //Check for duplicate values
                bool duplicate = false;
                for(int k{}; k < num_users_; k ++)
                {
                    if(compareStrings(users_[i].getUsername(), users_with_tag[k]))
                    {
                        duplicate = true;
                        break;
                    }
                }
                //Prints user if it was not a duplicate
                if(!duplicate)
                {
                    cout << users_[i].getUsername() << "\n";
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

//addPost function definition
//If the array of posts is full, returns false
//Sets the first empty post's author, body, and date to the
// input parameters
//Parameters : post_body (string), author (string), date (string)
//Return : bool (successfully added post)
bool Buffchat::addPost(string post_body, string author, string date)
{
    //If posts_ array is full, return false
    if(num_posts_ == posts_size_)
    {
        return false;
    }
    
    //Fills the next empty post object with the new information
    posts_[num_posts_].setPostAuthor(author);
    posts_[num_posts_].setPostBody(post_body);
    posts_[num_posts_].setPostDate(date);

    //Increments the number of posts
    num_posts_++;

    //Return true if post was added successfully
    return true;
}

//printPopularPosts function definition
//If posts array is empty, inform the user and exit the function
//Checks to see if there are posts within the given year
//Checks to see if posts that match the desired criteria exist
//Prints out all posts that meet the popularity criteria
//Parameters : int, string
//Return : void
void Buffchat::printPopularPosts(int min_likes, string year) 
{

    //If the posts array is empty, inform user and exit function
    if(num_posts_ <= 0)
    {
        cout << "No posts are stored\n";
        return;
    }

    //Determines if a post of given year is found
    bool yearFound = false;
    
    //Loops through to check for matching year
    for(int i{}; i < num_posts_; i ++)
    {
        if(compareStrings(posts_[i].getPostDate().substr(6, 2), year))
        {
            yearFound = true;
            break;
        }
    }

    //If there are no popular posts for the given year, inform
    //user and exit function
    if(!yearFound)
    {
        cout << "No posts stored for year " << year << "\n";
        return;
    }

    //Determines if any posts match the given criteria
    bool postFound = false;

    //Looks for posts that meet given criteria
    for(int i{}; i < num_posts_; i ++)
    {
        if(compareStrings(posts_[i].getPostDate().substr(6, 2), year) && posts_[i].getPostLikes() > min_likes)
        {
            //Update conditional if desired criteria met
            postFound = true;
        }
    }

    //If no posts of popular criteria are met
    if(!postFound)
    {
        cout << "No posts found for year " << year << " with likes more than " << min_likes << "\n";
        return;
    }

    cout << "Top posts for year " << year << " with likes more than " << min_likes << "\n";
    
    //Prints posts that meet criteria
    for(int i{}; i < num_posts_; i ++)
    {
        if(compareStrings(posts_[i].getPostDate().substr(6, 2), year) && posts_[i].getPostLikes() > min_likes)
        {
            cout << posts_[i].getPostLikes() << " likes: " << posts_[i].getPostBody() << "\n";
        }
    }


}

//findLeastActiveUser function definition
//Returns empty user object if users array is empty
//Iterates through users array and finds user with least activity
//Parameters : none
//Return type : User object
User Buffchat::findLeastActiveUser()
{
    //Empty user object
    User newUser;

    //Returns empty object if num_users is 0
    if(num_users_ == 0)
    {
        return newUser;
    }

    //Tracks which user has the least activity
    int currLowestViewCount = 0; 
    int leastActiveIndex = 0;

    //Sets initial lowest view count
    for(int i{}; i < 50; i ++)
    {
        if(users_[i].getLikesAt(i) == -1)
        {
            //Increments the current lowest view count
            currLowestViewCount ++;
        }
    }

    //Iterates through users array and finds user with lowest activity
    for(int i{}; i < num_users_; i ++)
    {
        //Temp variable tracks view count of current iteration
        int tempViewCount = 0;
        for(int j{}; j < 50; j ++)
        {
            if(users_[i].getLikesAt(j) == -1)
            {
                //Increment temp view count
                tempViewCount ++;
            }
        }

        //Changes current lowest view count if necessary
        if(tempViewCount > currLowestViewCount)
        {
            currLowestViewCount = tempViewCount;
            leastActiveIndex = i;
        }
    }

    //Returns user at index with least activity
    return users_[leastActiveIndex];
}

//countUniqueLikes function definition
//If user or post array is empty, return -2
//Create array to track number of likes
//Create variable to check if author's posts have been viewed
//Iterate through posts array to check for matching author
//If an author matches, iterates through users array to 
// find users which have liked the post
//If a user has liked a post by the author, increments total likes
//If no users have viewed the post, returns -1
//Otherwise, returns the number of users who have liked the post
//Parameter : post_author (string)
//Return type : num unique likes (int)
int Buffchat::countUniqueLikes(string post_author)
{
    //Empty array case
    if(num_posts_ <= 0 || num_users_ <= 0)
    {
        return -2;
    }

    //Return value
    int totalLikes = 0;

    //Keeps track of an author's post viewership
    bool hasBeenViewed = false;

    //Iterates through each post to check for a matching author
    for(int i{}; i < posts_size_; i ++)
    {
        //If the current post's author matches the argument
        if(compareStrings(posts_[i].getPostAuthor(), post_author))
        {
            //Whenever a match is found, loops through users_ array and
            //increments the number of likes if that user has liked the
            //author's post
            for(int j{}; j < users_size_; j ++)
            {
                //If a user has liked the author's post more than once, increment total likes
                if(users_[j].getLikesAt(i) > 0)
                {
                    totalLikes ++;
                }
                //If a user has viewed the post, update hasBeenViewed variable
                if(users_[j].getLikesAt(i) != -1)
                {
                    hasBeenViewed = true;
                }
            }
        }
    }

    //If no posts have been viewed, returns -1
    if(!hasBeenViewed)
    {
        return -1;
    }

    //Returns total number of likes
    return totalLikes;

}

//split function definition
//Splits each string at a given splitter character and stores each part in a new array
//Will iterate through each string in search of the splitter character and split
//the string/add the substring to the new array until the array is full
//If the length of the initial string is 0, returns 0
//If there are more splits than can be stored in the array, returns -1
//parameters: string input, char splitter, string array, int size
//returns int (number of splits)
bool Buffchat::compareStrings(string a, string b)
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
int Buffchat::split(string mainString, char splitter, string array[], int size) 
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
