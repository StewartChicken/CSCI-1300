//calcSigmoid.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyler Ruvane
// Homework 2 - 6


#include <iostream> //imports
#include <cmath>

using namespace std; //using the std namespace

double x; //input for sigmoid

double sigmoid; //sigmoid value

int main(){ //main method

    cout << "Enter a value for x:" << endl; //x assignment
    cin >> x;

    sigmoid = 1.0 / (1 + exp(-x)); //sigmoid calculation

    cout << "The sigmoid for x=" << x << " is " << sigmoid; //output

    return 0; //returns 0 if main executes successfully
}