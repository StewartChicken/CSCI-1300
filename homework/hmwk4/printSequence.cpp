// printSequence.cpp
// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 4 - Problem # 2

#include <iostream> //Imports
#include <cmath>

int input, finalValue;
bool valid;

int main() //Main
{

    valid = false; //Is input valid

    while(!valid) //User input prompt
    {
        std::cout << "Enter a value between 1 and 1000:\n";
        std::cin >> input;

        if(input > 1 && input < 1000) //Checks input validity
        {
            valid = true;
            break;
        }else{
            std::cout << "Invalid Input.\n"; 
        }
    }
    
    //Collatz Sequence
    finalValue = input; 

    while(finalValue != 1)
    {
        std::cout << finalValue << "\n";
        if(finalValue % 2 == 0) //finalValue is even 
        {
            finalValue /= 2;
        //finalValue is odd
        }else{
            finalValue = 3 * finalValue + 1;
        }
    }

    std::cout << finalValue << "\n";
   
    return 0;
}