//cardGame.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 7 - Question 3

//Inclusions
#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

//Main function
int main()
{
    
    //Vector containing your partners' cards
    vector<int> partnerCards;

    //Int tracking the number of cards you have
    int numCards = 0;

    //Stores user input
    int userInput;

    //Gets user input - ends game when input is 14
    while(userInput != 14)
    {
        //User prompt
        cout << "Please enter a number:\n";
        cin >> userInput;

        //Checks is user input is within bounds
        if(userInput > 14 || userInput < 1)
        {
            cout << "The number should be an integer between 1 and 14.\n";
            continue;
        }

        //Adds user input to vector
        partnerCards.push_back(userInput);

        //If Ace is pulled
        if(userInput == 1)
        {
            //If only one card is in the vector
            if(partnerCards.size() == 1)
            {
                //Removes partner card and increments my card
                partnerCards.erase(partnerCards.begin());
                numCards ++;

                //Continues loop
                continue;
            }
                
            //If more than one card is in the vector
            //Removes two cards from front of vector and increments my cards by 2
            partnerCards.erase(partnerCards.begin());
            partnerCards.erase(partnerCards.begin());
            numCards += 2;

            //Continues loop
            continue;
        }

        //If face card is pulled
        if(userInput == 11 || userInput == 12 || userInput == 13)
        {
            //If only one card is in vector
            if(partnerCards.size() == 1)
            {
                //Removes partner cards from back of vector and increments my cards
                partnerCards.pop_back();
                numCards ++;
                //Continues loop
                continue;
            }

            //If more than one card is in vector
            //Removes two cards from back of vector and increments my cards by 2
            partnerCards.pop_back();
            partnerCards.pop_back();
            numCards += 2;

            //Continues loop
            continue;
        }

        //If joker is pulled
        if(userInput == 14)
        {
            partnerCards.pop_back();
            break;
        }

    }

    //Prints partner's cards
    cout << "Your remaining cards are: ";
    for(int i = 0; i < partnerCards.size(); i++)
    {
        cout << partnerCards.at(i) << " ";
    }
    cout << endl;

    //Prints my card count
    cout << "I have " << numCards << " card(s).\n";

    //Checks win conditions
    if(numCards > partnerCards.size())
    {
        cout << "I win!\n";
    }
    else if (numCards < partnerCards.size())
    {
        cout << "You win!\n";
    }else{
        cout << "Tie!\n";
    }

    //Return 
    return 0;
}