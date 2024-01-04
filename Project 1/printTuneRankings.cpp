//printTuneRankings.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project 1 - Question 6

#include <iostream>

using std::string;
using std::cout;

//function declarations
void printTuneRankings(string, string, string, string);
double bestSimilarity(string, string);
double tuneSimilarity(string, string);

int main()
{

    //Test 1 for printTuneRankings
    //Expected output: 
    // 1) Tune 3
    // 2) Tune 1 
    // 3) Tune 2
    printTuneRankings("E4G4F8", "A3G5C3", "B6G4E2", "C6C8G1");

    //Test 2 for printTuneRankings
    //Expected output: 
    // 1) Tune 1
    // 2) Tune 2 
    // 3) Tune 3
    printTuneRankings("G1G8", "E3D4A1", "A4D1C6", "C5F3E7");

    //Test 3 for printTuneRankings
    //Expected output: 
    // 1) Tune 2
    // 2) Tune 1 
    // 3) Tune 3
    printTuneRankings("A3G5C3", "C1C7G3", "E4G4F8", "C6C8G1");

    return 0;
}

//printTuneRankings function definition

/** 
 * Algorithm: Prints the best tune rankings between three input tunes and a target tune
 * 1. Takes three tunes and one target tune as input strings
 * 2. Creates three double values which hold the similarity scores of each input string to the target string
 * 3. Runs case-by-case to determine the proper order of the tunes
 * 4. Prints the tune order
 * Parameter(s): tune1 (string), tune2 (string), tune3 (string), targetTune (string)
 * Returns: void (no return)
 */
void printTuneRankings(string tune1, string tune2, string tune3, string targetTune)
{
   
    //Each tune argument's best similarity score
    double tune1Similarity = bestSimilarity(tune1, targetTune);
    double tune2Similarity = bestSimilarity(tune2, targetTune);
    double tune3Similarity = bestSimilarity(tune3, targetTune);

    //Comparisons to determine the proper ranking

    /*List of outcomes:
    1 2 3
    1 3 2
    2 1 3 
    2 3 1
    3 1 2
    3 2 1
    */
   
    if(tune1Similarity >= tune2Similarity && tune2Similarity >= tune3Similarity)
    {
        cout << "1) Tune 1\n2) Tune 2\n3) Tune 3\n";
    }else if(tune1Similarity >= tune3Similarity && tune3Similarity > tune2Similarity)
    {
        cout << "1) Tune 1\n2) Tune 3\n3) Tune 2\n";
    }else if(tune2Similarity > tune1Similarity && tune1Similarity >= tune3Similarity)
    {
        cout << "1) Tune 2\n2) Tune 1\n3) Tune 3\n";
    }else if(tune2Similarity >= tune3Similarity && tune3Similarity > tune1Similarity)
    {
        cout << "1) Tune 2\n2) Tune 3\n3) Tune 1\n";
    }else if(tune3Similarity > tune1Similarity && tune1Similarity >= tune2Similarity)
    {
        cout << "1) Tune 3\n2) Tune 1\n3) Tune 2\n";
    }else{
        cout << "1) Tune 3\n2) Tune 2\n3) Tune 1\n";
    }
    
}

//bestSimilarity function definition

/** 
 * Algorithm: Calculates the best similarity between an input tune and a target tune
 * 1. Takes two input strings: an inputTune and a targetTune
 * 2. If the string lengths don't match, returns 0
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