//readPostsDriver.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2 - Question 2

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

//Function declarations
bool compareStrings(string, string);
int readPosts(string, Post[], int, int);
int split(string, char, string array[], int);

int main()
{

    //Test case 1
    /*Expected Output

    user1
    Test body
    10/10/20
    10
    user2
    Test body 1
    02/11/19
    2
    user3
    Test body 2
    01/04/21
    30

    */
    Post posts1[10];
    //assert(readPosts("posts.txt", posts1, 0, 10) == 3);

    /*for(int i{}; i < 3; i ++)
    {
        cout << posts1[i].getPostAuthor() << "\n";
        cout << posts1[i].getPostBody() << "\n";
        cout << posts1[i].getPostDate() << "\n";
        cout << posts1[i].getPostLikes() << "\n";
    }*/

    //Test 2
    /*Expected output
    Xuefei
    new post
    10/02/22
    10
    user10
    Test body again
    11/10/21
    20
    user11
    More text
    05/12/20
    3
    user12
    Hello!
    01/04/19
    39
    */
    Post posts2[10];
    Post my_post_1 = Post("new post","Xuefei", 10, "10/02/22");   
    posts2[0] = my_post_1;
    assert(readPosts("posts_2.txt", posts2, 1, 10) == 4);
    
    /*for(int i{}; i < 4; i ++)
    {
        cout << posts2[i].getPostAuthor() << "\n";
        cout << posts2[i].getPostBody() << "\n";
        cout << posts2[i].getPostDate() << "\n";
        cout << posts2[i].getPostLikes() << "\n";
    }*/


    //Test 3
    /*Expected output
    Xuefei
    new post
    10/02/22
    10
    user10
    Test body again
    11/10/21
    20
    user11
    More text
    05/12/20
    3
    */
    Post posts3[3];
    posts3[0] = my_post_1;
    assert(readPosts("posts_2.txt",posts3,1,3) == 3);

    /*for(int i{}; i < 3; i ++)
    {
        cout << posts2[i].getPostAuthor() << "\n";
        cout << posts2[i].getPostBody() << "\n";
        cout << posts2[i].getPostDate() << "\n";
        cout << posts2[i].getPostLikes() << "\n";
    }*/

    //Test 4
    /*Expected Value
    Xuefei
    new post
    10/02/22
    10
    Morgan
    Hello!
    10/04/22
    9
    */
    Post posts4[2];
    posts4[0] = my_post_1;
    Post my_post_2 = Post("Hello!","Morgan", 9, "10/04/22");
    posts4[1] = my_post_2;
    assert(readPosts("posts_test2.txt",posts4,2,2) == -2);

    /*for(int i{}; i < 2; i ++)
    {
        cout << posts4[i].getPostAuthor() << "\n";
        cout << posts4[i].getPostBody() << "\n";
        cout << posts4[i].getPostDate() << "\n";
        cout << posts4[i].getPostLikes() << "\n";
    }*/

    //Test 5 - no file exists
    //Expected value : Could not open file.
    Post posts5[6];
    assert(readPosts("Does_Not_Exist.txt",posts5,0,6) == -1);

    return 0;
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
