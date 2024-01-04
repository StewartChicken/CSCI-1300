//numValidNotes.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project 1 - Question 3

#include <iostream> //Imports
#include <cassert>

using std::string;

//Function declarations
int numValidNotes(string);
bool isValidNote(string); 

//Main
int main()
{

    //test 1 for numValidNotes
    assert(numValidNotes("A0B4C9") == 3);

    //test 2 for numValidNotes
    assert(numValidNotes("G4bC1Hello") == 2);

    //test 3 for numValidNotes
    assert(numValidNotes("A") == 0);

    //test 4 for numValidNotes
    assert(numValidNotes("aA0a") == 1);

    return 0;
}

//numValidNotes function definition

/** 
 * Algorithm: Counts the number of valid notes within a given input tune
 * 1. Input tune is passed into a function as a string
 * 2. Number of valid notes initially set to 0
 * 3. If the length of input is less than 2, return 0 (can't contain valid notes)
 * 4. Iterate through the input tune and increment the number of valid notes
 *    each time one is found
 * Parameter(s): note (string)
 * Returns: integer
 */
int numValidNotes(string input)
{
    //Initial value is 0
    int numValidNotes = 0;

    //Returns 0 if length is less than 2
    if(input.length() < 2)
    {
        return 0;
    }

    //Iterates through input and counts number of valid notes
    for(int i{}; i < input.length() - 1; i ++)
    {
        if(isValidNote(input.substr(i, 2)))
        {
            //Increment numValidNotes
            numValidNotes ++;
        }
    }

    //Return
    return numValidNotes;
}


//isValidNote function definition

/**
 * Algorithm: Checks wither or not a given note is valid
 * 1. Input note is passed into a function as a string
 * 2. If note is not of length 2, return false
 * 3. If second character of the note is not a digit (0-9), return false
 * 4. If the first character of the note is a valid musical letter, return true
 * Parameter(s): note (string)
 * Returns: boolean
 */
bool isValidNote(string note) 
{
    //Contains all valid natural notes
    std::string notes[7] = {"A", "B", "C", "D", "E", "F", "G"}; 
    
    //Ensures input is of valid size
    if(note.length() != 2)
    {
        return false;
    }
    
    //If second character of input is not a digit, returns false
    if(!std::isdigit(note[1]))
    {
        return false;
    }

    //Initial state of note before it is compared to every valid Note
    bool valid = false;

    //If note parameter contains a valid note (note from the string)
    //valid is set to true, otherewise, valid remains false
    for(int i{}; i < 7; i ++)
    {
        if(note.substr(0, 1) == notes[i])
        {
            valid = true;
        }
    }

    //Return
    return valid;
}