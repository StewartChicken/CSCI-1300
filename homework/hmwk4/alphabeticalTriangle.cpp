// alphabeticalTriangle.cpp
// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 4 - Problem # 5

#include <iostream>

int height; //height of pyramid
int index = 0; //Ranges from 0-25 and tracks the current letter when traversing the alphabet array

std::string alphabet[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
                        "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", 
                        "w", "x", "y", "z"};

int main()
{

    //User prompt
    std::cout << "Enter the height:\n";
    std::cin >> height;

    if(height <= 0) //Invalid input check
    {
        std::cout << "Invalid input.\n";
        return 0;
    }

    //Width of each row is rowHeight * 2 - 1
    for(int i = 1; i <= height; i ++)
    {
        for(int j{}; j < (i * 2) - 1; j ++) //Prints each row
        {
            std::cout << alphabet[index];
            index == 25 ? index = 0 : index ++; //If index == 25, reset index so array starts fromm letter 'a'
        }                                       //Otherwise, increment index
        std::cout << "\n";
    }

    return 0;
}