//wifiSpeeds.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyler Ruvane
// Homework 3 - Problem 4

#include <iostream> //Import
#include <string>

using namespace std; //Namespace

double speed1; //Three user input wifi speeds
double speed2;
double speed3;

string userInput; //Initial user input (will be parsed and manipulated)

void parseUserString(double &speed1, double &speed2, double &speed3, string &userInput);

int main()
{
    
    cout << "Enter wifi speeds over the last 3 classes:\n"; //User input of initial wifi speeds
    getline(cin, userInput); //getline function is used bc whitespaces need to be accounted for

    parseUserString(speed1, speed2, speed3, userInput); //Function call to parse user input string

    if(speed1 < 0 || speed2 < 0 || speed3 < 0)
    {
        cout << "Please enter a valid input.\n";
        return 0;
    }

    if(speed1 > speed2 && speed2 > speed3)
    {
        cout << "The wifi is getting slower!\n";
        return 0;
    }
    else if(speed1 < speed2 && speed2 < speed3)
    {
        cout << "The wifi is getting faster!\n";
        return 0;
    }
    else
    {
        cout << "The wifi speed is changing unpredictably.\n";
    }

    return 0;
}

//Parses user input data
void parseUserString(double &speed1, double &speed2, double &speed3, string &userInput)
{
    
    //This will track the index of the spaces for then the string is parsed into doubles
    int spaceIndex; 

    //Find first space and assign first entry to the first internet speed
    spaceIndex = userInput.find(' '); 
    speed1 = stod(userInput.substr(0, spaceIndex));

    //Removes the first internet speed from the initial string
    userInput = userInput.substr(spaceIndex + 1, userInput.length() - spaceIndex);
    
    //Find second internet speed and assign it to 'speed2' double
    spaceIndex = userInput.find(' ');
    speed2 = stod(userInput.substr(0, spaceIndex));

    //Removes the second internet speed from the initial string
    userInput = userInput.substr(spaceIndex + 1, userInput.length() - spaceIndex);

    //Assigns remaining value of user input to 'speed3'
    speed3 = stod(userInput.substr(0, spaceIndex));

}