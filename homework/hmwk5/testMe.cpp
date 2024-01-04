//testMe.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 5 - Question 5

//Includes
#include <iostream>
#include <cassert>

//Function declarations
int zeroesToFives(int[], int);

//Main
int main()
{

    //Test cases

    //Edge case 1: all 0's
    int arr1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    assert(zeroesToFives(arr1, 10) == 10);

    //Edge case 2: all 5's
    int arr2[10] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    assert(zeroesToFives(arr2, 10) == 0);

    //Edge case 3: numbers containing 0's
    int arr3[10] = {10, 10, 10, 50, 320, 13, 62, 101, 124, 502};
    assert(zeroesToFives(arr3, 10) == 0);

    int arr4[10] = {74, 34, 1, 0, 0, 14, 1, 4, 7, 9};
    assert(zeroesToFives(arr4, 10) == 2);

    int arr5[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(zeroesToFives(arr5, 10) == 1);

    int arr6[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    assert(zeroesToFives(arr6, 10) == 1);

    int arr7[10] = {1, 0, 0, 1, 1, 0, 1, 0, 0, 0};
    assert(zeroesToFives(arr7, 10) == 6);

    int arr8[10] = {0, 5, 5, 5, 5, 5, 5, 5, 5, 0};
    assert(zeroesToFives(arr8, 10) == 2);

    int arr9[10] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 5};
    assert(zeroesToFives(arr9, 10) == 8);

    int arr10[10] = {1, 2, 3, 0, 1, 2, 3, 0, 0, 0};
    assert(zeroesToFives(arr10, 10) == 4);

    std::cout << "Done\n";

    return 0;
}

//zeroesToFives definition
int zeroesToFives(int arr[], int size)
{
    int count = 0;

    for(int i{}; i < size; i ++)
    {
        if(arr[i] == 0)
        {
            arr[i] = 5;
            count ++;
        }
    }

    return count;
}