//isValidNote.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project 1 - Question 1

#include <iostream> //Imports
#include <string>
#include <cassert>

using std::string; 

bool isValidNote(string); //Function declaration

int main() //Main function
{
    
    //test 1 for isValidNote
    assert(isValidNote("A0") == true);

    //test 2 for isValidNote
    assert(isValidNote("C10") == false);

    //test 3 for isValidNote
    assert(isValidNote("F") == false);

    //test 4 for isValidNote
    assert(isValidNote("8A") == false);

    //test 5 for isValidNote
    assert(isValidNote("Good morning") == false);

    return 0;
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
    string notes[7] = {"A", "B", "C", "D", "E", "F", "G"}; 
    
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