//isValidTune.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project 1 - Question 2

#include <iostream> //Imports
#include <cassert>

using std::string; //Uses std::string type for convenience

bool isValidTune(string); //Function declarations
bool isValidNote(string);

int main() //Main function
{

    //test 1 for isValidTune
    assert(isValidTune("") == false);

    //test 2 for isValidTune
    assert(isValidTune("A0B1C3") == true);

    //test 3 for isValidTune
    assert(isValidTune("A6b9C1") == false);

    //test 4 for isValidTune
    assert(isValidTune("B") == false);

    //test 5 for isValidTune
    assert(isValidTune("C1G") == false);

    //test 6 for isValidTune
    assert(isValidTune("B10") == false);

    //test 7 for isValidTune
    assert(isValidTune("A1") == true);

    //test 8 for isValidTune
    assert(isValidTune("0B") == false);

    return 0;
}

//isValidTune function definition

/** 
 * Algorithm: Determines whether or not a given tune is valid
 * 1. Input tune is passed into a function as a string
 * 2. If a tune is less than one note or has an odd number of characters, it is not valid
 * 3. Iterates through input string and checks if every two characters is a valid note
 * 4. If a single invalid note is found, returns false
 * 5. Return true if tune is valid
 * Parameter(s): notes (string)
 * Returns: boolean
 */
bool isValidTune(string notes) 
{

    //Odd length tunes and tunes of length 0 are immediately invalidated
    if(notes.length() % 2 != 0 || notes.length() == 0)
    {
        return false;
    }

    //Iterates through notes string, if any note is invalid, return false
    for(int i{}; i < notes.length() / 2; i ++)
    {
        if(!isValidNote(notes.substr(i * 2, 2)))
        {
            return false;
        }
    }

    //Return true by default
    return true;
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