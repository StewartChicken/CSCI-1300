//bestSimilarity.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project 1 - Question 5

#include <iostream> //imports
#include <cassert>

using std::string;

//function declarations
double bestSimilarity(string, string);
double tuneSimilarity(string, string);

bool doubleEquals(double a, double b);

//main
int main()
{
    //test 1 for bestSimilarity
    assert(doubleEquals(bestSimilarity("D3A6G1B7", "G9F1B2B5"), -2.75));

    //test 2 for bestSimilarity
    assert(doubleEquals(bestSimilarity("G5", "G9F1B2B5"), 0));

    //test 3 for bestSimilarity
    assert(doubleEquals(bestSimilarity("G9F1B2B5", "G9F1B2B5"), 5));

    //test 4 for bestSimilarity
    assert(doubleEquals(bestSimilarity("A4B7E1G6F8", "A3"), 1));

    //std::cout << bestSimilarity("D3A6G1B7", "G9F1B2B5");
    return 0;
}

//bestSimilarity function definition

/** 
 * Algorithm: Calculates the best similarity between an input tune and a target tune
 * 1. Takes two input strings: an inputTune and a targetTune
 * 2. If input tune is smaller than target tune, returns 0
 * 3. Create currentSimilarityValue variable to hold the current-highest tuneSimilarity value
 * 4. Compares sections (equal in length to the length of the targetTune) to the target tune and 
 *    keeps track of the current highest similarity value
 * 5. Returns the highest similarity value
 * Parameter(s): inputTune (string), targetTune (string)
 * Returns: double
 */
double bestSimilarity(string inputTune, string targetTune)
{

    //If input length is smaller than targetTune
    if(inputTune.length() < targetTune.length())
    {
        return 0;
    }

    //Similarity double that will change as a new best similarity is found
    double currentSimilarityValue = 0;

    //Keeps track of where in the tune string the iteration is at any given time
    int startIndex = 0;

    //Initial similarity value 
    currentSimilarityValue = tuneSimilarity(inputTune.substr(startIndex, targetTune.length()), targetTune);

    //Increments the starting index by the length of a single note
    startIndex += 2;


    while(1)
    {

        //Keeps startIndex within bounds
        if(startIndex > inputTune.length() - targetTune.length())
        {
            break;
        }

        //Creates next tune whose similarity to the target will be calculatetd
        string nextString = inputTune.substr(startIndex, targetTune.length());

        //Checks nextString's similarity with the target string and, if it's greater than the current
        double tempSimilarity = tuneSimilarity(nextString, targetTune);
        if(tempSimilarity > currentSimilarityValue){
            currentSimilarityValue = tempSimilarity;
        }

        //Increments startIndex with the length of a single note
        startIndex += 2;
    }

    //Returns the highest similarity score
    return currentSimilarityValue;

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

    //If tune lengths don't match, similarity is 0
    if(tune1.length() != tune2.length())
    {
        return 0;
    }

    //Similarity function parameters
    int totalNotes = tune1.length() / 2;
    int numMatchingNotes = 0;
    int numMatchingNotesPitches = 0;
    int numDifferentNotesPitches = 0;

    //Finds number of matching notes
    for(int i{}; i < tune1.length(); i += 2)
    {
        if(tune1[i] == tune2[i])
        {
            numMatchingNotes ++;
        }
    }

    //Finds number of notes with same pitches
    for(int i{}; i < tune1.length() - 1; i += 2)
    {
        if(tune1.substr(i, 2) == tune2.substr(i, 2)){
            numMatchingNotesPitches ++;
        }
    }

    //Finds number of notes with different notes and pitches
    for(int i{}; i < tune1.length() - 1; i += 2)
    {
        if(tune1[i] != tune2[i] && tune1[i + 1] != tune2[i + 1])
        {
            numDifferentNotesPitches ++;
        }
    }

    //Returns the similarity score between two notes
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