
//sumElements.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 7 - Question 1

//Inclusions
#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
using std::cout;
using std::endl;

//Function declaration 
int sumElements(vector<int>, int, int);

//Main function
int main()
{

    //Test case 1
    vector<int> vect1{10, 20, 30, 40, 50};
    int start_index = 1, end_index = 3;
    assert(sumElements(vect1, start_index, end_index) == 90);
    
    //Test case 2 - start > end
    vector<int> vect2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    start_index = 5;
    end_index = 3;
    assert(sumElements(vect2, start_index, end_index) == -1);

    //Test case 3 -  end out of bounds
    //Test case 2
    vector<int> vect3{2, 4, 6, 8, 10, 12, 14, 16, 18};
    start_index = 3;
    end_index = 15;
    assert(sumElements(vect2, start_index, end_index) == -2);

    cout << "All tests passed!" << endl;

    //Return
    return 0;
}

//sumElements definition
/**
 * @brief 
 * Returns -1 if start > end
 * Returns -2 if either the start or end is out of bounds
 * Creates sum variable
 * Iterates from start to end indeces and adds vector values to sum
 * Returns sum
 * 
 * @param numbers 
 * @param start 
 * @param end 
 * @return int 
 */
int sumElements(vector<int> numbers, int start, int end)
{

    //If start > end
    if(start > end)
    {
        return -1;
    }

    //If start or end out of bounds
    if(start >= numbers.size() || end >= numbers.size())
    {
        return -2;
    }

    //Create sum variable
    int sum = 0;

    //Iterates from start to end indeces and adds vector values to sum
    for(int i = start; i <= end; i++)
    {
        sum += numbers.at(i);
    }

    //Return sum
    return sum;
}