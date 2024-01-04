//arrayStats.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 5 - Question 1

//Includes
#include <iostream>
#include <cassert>

//Function declarations
double min(double[], int);
double sum(double[], int);
double average(double[], int);

/**
 * doublesEqual will test if two doubles are equal to each other within two decimal places.
 */
bool doublesEqual(double a, double b, const double epsilon = 1e-2)
{
    double c = a - b;
    return c < epsilon && -c < epsilon;
}
//Main
int main()
{

    //Three test cases to test average, sum, and min
    double arr1[5] = {1, 2, 3, 4, 5};
    double arr2[5] = {3, 3, 3, 3, 3};
    double arr3[5] = {5, 4, 3, 2, 1};

    //Assert statements
    assert(doublesEqual(min(arr1, 5), 1.0));
    assert(doublesEqual(sum(arr3, 5), 15));
    assert(doublesEqual(average(arr2, 5), 3));

    //Return
    return 0;
}

//min function definition
/**
 * @brief Takes input array of hours studied and returns the minum vaue
 * Iterates through array and finds min value
 * 
 * @param studyTimes 
 * @param size 
 * @return double 
 */
double min(double studyTimes[], int size)
{

    //This variable holds the lowest time studied and is initialized \
    //to the first element of the studyTimes array
    double currHour = studyTimes[0];
    for(int i = 1; i < size; i ++)
    {
        if(studyTimes[i] < currHour)
        {
            //Reassigns currHour if finds a new minStudy time
            currHour = studyTimes[i];
        }
    }

    //Return
    return currHour;    
}

//sum function definition
/**
 * @brief Takes an array of study times (double) and returns the sum
 * of each duration. Loops through array and adds to a "total" variable
 * 
 * @param studyTimes 
 * @param size 
 * @return double 
 */
double sum(double studyTimes[], int size)
{
    //Total study time
    double total = 0.0;

    //Iterates through studyTimes argument and adds to total
    for(int i{}; i < size; i ++)
    {
        total += studyTimes[i];
    }

    //Return
    return total;
}

//average function definition
/**
 * @brief returns the average time studied for the given array of times
 * 
 * @param studyTimes 
 * @param size 
 * @return double 
 */
double average(double studyTimes[], int size)
{
    //Calls sum function to find the total number of hours studied
    double total = sum(studyTimes, size);
    
    //Returns average
    return total / size;
}