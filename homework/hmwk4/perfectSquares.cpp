// perfectSquares.cpp
// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 4 - Problem # 1

#include <iostream> //Imports
#include <cmath>

int inputNumber, outputNumber, maxNumber; //Declarations


int main() //Main
{

    std::cout << "Enter a non-negative integer:\n"; //User prompt
    std::cin >> inputNumber;

    outputNumber = 0; //Initialize output to 0
    maxNumber = sqrt(inputNumber);

    if(inputNumber < 0) //Invalid input check
    {
        std::cout << "Invalid input.\n";
        return 0;
    }

    for(int i{}; i < maxNumber; i ++) //Sums all perfect squares
    {
        outputNumber += pow(maxNumber - i, 2);
    }

    std::cout << "Sum: " << outputNumber << "\n"; //Output
    return 0;
}