//snowfall.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyler Ruvane
// Homework 2 - 4


#include <iostream> //import

using namespace std; //using the std namespace

//Initial values and snowfall rates
const int breckRate = 5;
const int breckInit = 25;

const int vailRate = 12;
const int vailInit = 28;

const int copRate = 2;
const int copInit = 40;

int numDays; //user input for number of days

int main(){ //main method

    cout << "How many days in the future would you like a prediction for? " << endl;
    cin >> numDays;

    //Outputs snowfall prediction
    cout << "Breckenridge will have " << breckRate * numDays + breckInit << " inches, Vail will have "
        << vailRate * numDays + vailInit << " inches, and Copper Mountain will have " <<
            copRate * numDays + copInit << " inches." << endl;

    return 0; //returns 0 if main executes successfully
}