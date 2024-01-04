//secondPlace.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 5 - Question 3b

#include <iostream>
#include <cassert>

using std::string;

//Function declarations
bool insertAfter(string[], int, int, int, string);
bool compareNames(string, string);
int secondPlace(string[], string, string, int, int, int);

int main()
{

    //Test cases
    string arr1[5] = {"clefairy", "meowth", "snorlax"}; 
    assert(secondPlace(arr1, "charizard", "meowth", 3, 5, 1) == 4);

    string arr2[12] = {"clefairy", "charizard", "pikachu", "clefairy" };
    assert(secondPlace(arr2, "pichu", "clefairy", 4, 12, 2) == 6);

    string arr3[4] = {"caterpie", "charizard", "pikachu", "ponyta"};
    assert(secondPlace(arr3, "pichu", "ponyta", 4, 4, 1) == 4);

    std::cout << "done\n";   
    return 0;
}   

//secondPlace definition
int secondPlace(string names[], string newName, string targetName, int numElements, int size, int numTargetStrings)
{

    //Boolean that holds the return value of insertAfter
    bool hasRoom;

    //start index of traversal
    int startIndex = 0;

    //If there isn't room to enter all the elements, return the original number of elements
    if(numElements + numTargetStrings > size)
    {
        return numElements;
    }

    //Insert new names after target names
    for(int j{}; j < numTargetStrings; j ++)
    {
        for(int i = startIndex; i <= numElements + numTargetStrings; i ++)
        {
            if(compareNames(names[i], targetName))
            {
                hasRoom = insertAfter(names, numElements, size, i, newName);
                startIndex = i + 1; //Increment startIndex
                break;
            }
        }
        
    }
    
    //Returns new array size
    return numElements + numTargetStrings;
}

//compareNames definition
//compares two names and returns true if they are the same
bool compareNames(string name1, string name2)
{
    if(name1.length() != name2.length())
    {
        return false;
    }

    for(int i{}; i < name1.length(); i ++)
    {
        if(name1[i] != name2[i])
        {
            return false;
        }
    }

    return true;
}

//insertAfter definition
bool insertAfter(string names[], int numElements, int size, int index, string newElement)
{

    //If the array is full or the index is out of bounds, return false
    if(numElements == size || index == size)
    {
        return false;
    }

    //Shifts names after the given index to the right
    for(int i = size - 1; i > index + 1; i --)
    {
        names[i] = names[i - 1];
    }

    //Sets new element at index + 1
    names[index + 1] = newElement;

    return true;
}