//tuneSimilarity.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project 1 - Question 4

#include <iostream> //Imports
#include <cassert>

using std::string;

//Function declarations
double tuneSimilarity(string, string);

bool doubleEquals(double a, double b);

int main()
{
    //test 1 for tuneSimilarity
    assert(doubleEquals(tuneSimilarity("A1B2C3", "A1B2C3"), 4));

    //test 2 for tuneSimilarity
    assert(doubleEquals(tuneSimilarity("G5G1B3D8", "E4A2G0B4"), -4));

    //test 3 for tuneSimilarity
    assert(doubleEquals(tuneSimilarity("A1B2C3", "D4"), 0));

    //std::cout << tuneSimilarity("G5G1B3D8", "E4A2G0B4");

    return 0;
}

//tuneSimilarity function definition

/** 
 * Algorithm: Determines whether or not a given tune is valid
 * 1. Takes two strings as input: tune1 and tune2
 * 2. If input strings are of different length, returns 0
 * 3. Declare integer variables totalNotes, numMatchingNotes, 
 *    numMatchingNotesPitches (number of notes with matching pitches),
 *    and numDifferentNotesPitches (Number of notes with different pitches and note letters)
 * 4. Iterates through both tunes - assigns number of matching notes to numMatchingNotes
 * 5. Iterates through both tunes - assigns number of notes with matching pitches to numMatchingNotesPitches
 * 6. Iterates through both tunes - assigns number of notes with differnt note and pitch to numDifferentNotesPitches
 * 7. Calculates the similarity using the formula
 *    similarity = (number of matching notes / total number of notes)
 *                 + number of matching notes with matching pitches
 *                 - number of different notes with different pitches
 * 8. Returns similarity
 * Parameter(s): tune1 (string), tune2 (string)
 * Returns: double
 */
double tuneSimilarity(string tune1, string tune2)
{

    //If input tune lengths are not equal, there is no similarity
    if(tune1.length() != tune2.length())
    {
        return 0;
    }

    //Formula parameters
    int totalNotes = tune1.length() / 2; 
    int numMatchingNotes = 0;
    int numMatchingNotesPitches = 0;
    int numDifferentNotesPitches = 0;

    //Iterates through tune1 and tune2 and count number of matching notes
    for(int i{}; i < tune1.length(); i += 2)
    {
        if(tune1[i] == tune2[i])
        {
            numMatchingNotes ++;
        }
    }

    //Iterates through tune1 and tune2 and counts number of notes
    //with matching pitches (not necessarily matching notes)
    for(int i{}; i < tune1.length() - 1; i += 2)
    {
        if(tune1.substr(i, 2) == tune2.substr(i, 2)){
            numMatchingNotesPitches ++;
        }
    }

    //Iterates through tune1 and tune2 and counts the number of notes
    //with different notes and pitches
    for(int i{}; i < tune1.length() - 1; i += 2)
    {
        if(tune1[i] != tune2[i] && tune1[i + 1] != tune2[i + 1])
        {
            numDifferentNotesPitches ++;
        }
    }

    //Returns double according to the specified formula
    return double(numMatchingNotes) / double(totalNotes) + numMatchingNotesPitches - numDifferentNotesPitches;

}

/**
 * doublesEqual will test if two doubles are equal to each other within two decimal places.
 */
bool doubleEquals(double a, double b)
{
    const double epsilon = 1e-2;
    double c = a - b;
    return c < epsilon && -c < epsilon;
}