//instrument.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyler Ruvane
// Homework 3 - Problem 6

#include <iostream>

using namespace std;

int userMenuSelection; //Holds the user's selection as they traverse the menu

//Functions which open the menu options for each respective instrument selection
void brassCategory();
void woodwindCategory();
void percussionCategory();

int price; //Cost of instrument

void printPrice(int); //Function declartion to print price

int main()
{

    //User prompt
    cout << "Select a category: (1)Brass (2)Woodwind (3)Percussion\n";
    cin >> userMenuSelection;

    //Switch that calls functions depending on a user's input
    switch(userMenuSelection)
    {
        case 1:
            brassCategory();
            break;
        case 2:
            woodwindCategory();
            break;
        case 3:
            percussionCategory();
            break;
        default:
            cout << "Please enter a valid input.\n";
            return 0;
    }
    return 0;
}

//Brass category menu
void brassCategory()
{
    //User prompt
    cout << "Select an instrument: (1)Trumpet (2)Trombone\n";
    cin >> userMenuSelection;

    switch(userMenuSelection)
    {
        case 1:
            printPrice(350);
            break;
        case 2:
            printPrice(400);
            break;
        default:
            cout << "Please enter a valid input.\n";
            break;
    }
}
//Woodwind menu
void woodwindCategory()
{
    //user prompt
    cout << "Select an instrument: (1)Flute (2)Saxophone\n";
    cin >> userMenuSelection;

    switch(userMenuSelection)
    {
        case 1:
            printPrice(325);
            break;
        case 2:
            printPrice(425);
            break;
        default:
            cout << "Please enter a valid input.\n";
            break;
    }
}
//percussin category
void percussionCategory()
{
    //user prompt
    cout << "Select an instrument: (1)Snare Drum (2)Cymbals\n";
    cin >> userMenuSelection;

    switch(userMenuSelection)
    {
        case 1:
            printPrice(275);
            break;
        case 2:
            printPrice(200);
            break;
        default:
            cout << "Please enter a valid input.\n";
            break;
    }
}

//Function implementation to print the price of the instrument
//given the 'price' argument
void printPrice(int price)
{
    cout << "Your instrument will be $" << price << "." << "\n";
}