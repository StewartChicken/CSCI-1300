//insertAfter.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 5 - Question 3a

//Includes
#include <iostream>
#include <cassert>

using std::string;

//insertAfter declaration
bool insertAfter(string[], int, int, int, string);

//Main
int main()
{

    //Test cases
    string test1[5] = {"pikachu", "meowth", "snorlax"};
    assert(insertAfter(test1, 3, 5, 2, "clefairy") == true);

    string test2[5] = {"caterpie", "eevee"};
    assert(insertAfter(test2, 2, 5, 0, "bulbasaur") == true);

    string test3[2] = {"pichu", "ponyta"};
    assert(insertAfter(test2, 2, 2, 1, "charizard") == false);

    std::cout << "done\n";

    return 0;
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