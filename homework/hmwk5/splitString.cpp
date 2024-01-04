//splitString.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 5 - Question 2

//Includes
#include <iostream>
#include <cassert>

using std::string;

//Function declarations
int split(string, char, string[], int);

//Main
int main()
{

    //test cases
    string arr1[3];
    assert(split("aa, bb, cc", ',', arr1, 3) == 3);

    string arr2[2];
    assert(split("aaaaaaaa", ',', arr1, 2) == 1);

    string arr3[3];
    assert(split("aa bb cc dd ee", ' ', arr1, 3) == -1);

    string arr4[3];
    assert(split("", ',', arr1, 3) == 0);

    //Return
    return 0;
}

//split function definition
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