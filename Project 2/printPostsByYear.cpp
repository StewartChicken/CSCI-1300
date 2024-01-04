//printPostsByYear.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2 - Question 3

//Includes
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include "Post.h"

using std::cout;
using std::string;
using std::endl;
using std::getline;
using std::ifstream;

//Compares two strings - for assert statements
bool compareStrings(string, string);
int readPosts(string, Post[], int, int);
int split(string, char, string array[], int);
void printPostsByYear(Post posts[], string, int);

//Main
int main()
{

    Post p_1 = Post("new post1","Lisa1", 10, "10/02/22");
    Post p_2 = Post("new post2","Lisa2", 11, "10/02/22");
    Post p_3 = Post("new post3","Lisa3", 8, "10/02/19");
    Post p_4 = Post("new post4","Lisa4", 14, "10/02/19");
    Post p_5 = Post("new post5","Lisa5", 15, "10/02/19");

    Post list_of_posts[] = {p_1, p_2, p_3, p_4, p_5};
    int number_of_posts = 5;
    string year = "22";

    //Test 1 - 2022
    /*
    Expected Value - 
    new post1
    new post2
    */
    printPostsByYear(list_of_posts, year, number_of_posts);
    cout << "\n";

    //Test 2 - 2019
    /*
    Expected Value - 
    new post3
    new post4
    new post5
    */
    printPostsByYear(list_of_posts, "19", number_of_posts);
    cout << "\n";

    //Test 3 - 2018
    /*
    No posts are stored for year 18
    */
    printPostsByYear(list_of_posts, "18", number_of_posts);
    cout << "\n";

    //Test 4 - empty list
    /*
    Expected Value - 
    No posts are stored
    */
    Post emptyList[5];
    printPostsByYear(emptyList, "19", 0);
    cout << "\n";

    return 0;
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
