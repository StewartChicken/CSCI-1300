//helloYou.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyler Ruvane
// Homework 2 - 2


#include <iostream> //import

using namespace std; //using the std namespace

string name; //string which will receive user input

int main(){ //main method

    cout << "Please enter your name below:" << endl; //user prompt
    
    cin >> name; //assigns user input to "name" string
    
    cout << "Hello, " << name << "!" << endl; //output

    return 0;
}