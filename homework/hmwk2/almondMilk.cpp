//almondMilk.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyler Ruvane
// Homework 2 - 3


#include <iostream> //imports
#include <iomanip>

using namespace std; //using the std namespace

int length; //holds user input of carton's length
int height; //holds uer input of carton's height
int volume; //volume of carton
double ounces;

int main(){ //main method

    //Prompts user for length of carton and assigns input to 'length' variable
    cout << "What is the side length of the base of the carton in inches?" << endl; 
    cin >> length;

    //Prompts user for length of carton and assigns input to 'height' variable
    cout << "What is the height of the carton in inches?" << endl;
    cin >> height;
    
    volume = length * length * height;
    ounces = 0.55 * volume;
    //outputs volume to console
    cout << fixed << setprecision(1) << "The carton has a volume of " << ounces << " ounces." << endl;

    return 0; //returns 0 if main executes successfully
}