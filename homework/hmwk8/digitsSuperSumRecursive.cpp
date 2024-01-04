//digitsSuperSumRecursive.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 8 - Question 1

//Inclusions
#include <iostream>
#include <string>
#include <cassert>

using std::cout;
using std::endl;

//Function Definitions
int digitsSuperSumRecursive(int);
int sum(int);

//Main
int main()
{
    //Test cases
    assert(digitsSuperSumRecursive(4567) == 4);
    assert(digitsSuperSumRecursive(9) == 9);
    assert(digitsSuperSumRecursive(195) == 6);
    assert(digitsSuperSumRecursive(123456789) == 9);
    assert(digitsSuperSumRecursive(88888888) == 1);
    assert(digitsSuperSumRecursive(97854) == 6);

    //Pass statement
    cout << "All tests passed" << endl;

    return 0;
}

//digitsSuperSumRecursive function definition
int digitsSuperSumRecursive(int N)
{
    //Base case - if N only has one digit, return N
    if(N < 10)
    {
        return N;
    }

    //Sums elements of number
    int newN = sum(N);

    //Recursive case - calls digitsSuperSumRecursive for the sum of N's digits
    return digitsSuperSumRecursive(newN);
}

//sum function definition
int sum(int initial)
{
    //If initial has one digit, return initial
    if(initial < 10)
    {
        return initial;
    }

    //Stores last digit of number
    int lastDigit = initial % 10;

    //Recursive case
    int remaining = sum(initial / 10);

    //Return
    return remaining + lastDigit;
}
