//scientificPitch.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project 1 - Question 7

//Import(s)
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;

//Menu interaction function declarations
//These functions prompt the user and 
//interact with the user's input
void printMainMenu();
void twoTuneSimilarity();
void twoTuneBestSimilarity();
void tuneRankingPrompt();

//Program logical function declarations
//these functions run the logic of the program and
//don't directly interact with the user
bool isValidNote(string);
bool isValidTune(string);
int numValidNotes(string);
double tuneSimilarity(string, string);
double bestSimilarity(string, string);
void printTuneRankings(string, string, string, string);

//Main
int main()
{

    //User's input
    int input;
    
    //Active until broken by user
    while(1)
    {
        printMainMenu();
        cin >> input;

        //Launches new menus based on the user entry
        switch(input){
            case 1: 
                twoTuneSimilarity();
                break;
            case 2:
                twoTuneBestSimilarity();
                break;
            case 3:
                tuneRankingPrompt();
                break;
            case 4:
                //Exits program
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid input.\n";
                break;
        }
    }
    
    return 0;
}

//tuneRankingPrompt functin definition

/**
 * Takes four user inputs, three tunes and one target tune, and prints the tunes in order
 * of their best similarities to the target
 * Parameter(s): none
 * Returns: void (no return)
 */
void tuneRankingPrompt()
{
    //Three input tunes and a target tune
    string tune1, tune2, tune3, target;
 
    //Prompt for first tune
    cout << "Please enter the first tune:\n";
    cin >> tune1;    

    //tune1 validity check
    while(!isValidTune(tune1))
    {
        cout << "Invalid input. Please enter a tune in valid SPN:\n";
        cin >> tune1;
    }

    //second tune prompt
    cout << "Please enter the seconed tune:\n";
    cin >> tune2;

    //tune2 validity check
    while(!isValidTune(tune2))
    {
        cout << "Invalid input. Please enter a tune in valid SPN:\n";
        cin >> tune2;
    }

    //third tune prompt
    cout << "Please enter the third tune:\n";
    cin >> tune3;

    //tune3 validity check
    while(!isValidTune(tune3))
    {
        cout << "Invalid input. Please enter a tune in valid SPN:\n";
        cin >> tune3;
    }

    //Target tune prompt
    cout << "Please enter the target tune:\n";
    cin >> target;

    //Target tune validity check
    while(!isValidTune(target))
    {
        cout << "Invalid input. Please enter a tune in valid SPN:\n";
        cin >> target;

    }

    //Outputs rankings of tunes - which one has highest similarity score with target
    printTuneRankings(tune1, tune2, tune3, target);

}

//twoTuneBestSimilarity functin definition

/**
 * Prints the best tune similarity between an input tune and a target tune
 * If the user inputs invalid tunes, they are prompted for a new tune which is in SPN format
 * Parameter(s): none
 * Returns: void (no return)
 */
void twoTuneBestSimilarity()
{

    //Input tune, target tune, and best similarity score
    string input, target;
    double similarity;

    //User prompt for input tune
    cout << "Please enter the input tune:\n";
    cin >> input;

    //Checks validity of input tune
    while(!isValidTune(input))
    {
        cout << "Invalid input. Please enter a tune in valid SPN:\n";
        cin >> input;
    }

    //User prompt for target tune
    cout << "Please enter the target tune:\n";
    cin >> target;

    //Checks validity of target tune
    while(!isValidTune(target))
    {
        cout << "Invalid input. Please enter a tune in valid SPN:\n";
        cin >> target;

    }

    //Calculates best similarity score between input and target tune
    similarity = bestSimilarity(input, target);

    //Output
    cout << std::fixed << std::setprecision(2) << "The best similarity score is: " << similarity << "\n";
}

//twoTuneSimilarity functin definition

/**
 * Prompts the user for entry of the first and second tunes. If either entry is invalid,
 * asks user to re-enter the tune in valid SPN format.
 * Parameter(s): none
 * Returns: void (no return)
 */
void twoTuneSimilarity()
{

    //Local variables - two tunes and their similarity score
    string tune1, tune2;
    double similarity;

    //User prompt for first tune
    cout << "Please enter the first tune:\n";
    cin >> tune1;
    
    //Checks for invalid input
    while(!isValidTune(tune1))
    {
        cout << "Invalid input. Please enter a tune in valid SPN:\n";
        cin >> tune1;

    }

    //User prompt for second tune
    cout << "Please enter the second tune:\n";
    cin >> tune2;

    //Checks for invalid input
    while(!isValidTune(tune2))
    {
        cout << "Invalid input. Please enter a tune in valid SPN:\n";
        cin >> tune2;

    }
   
    //Similarity score
    similarity = tuneSimilarity(tune1, tune2);

    //Output
    cout << "The similarity score is: " << similarity << "\n";
    
}

//printMainMenu functin definition

/**
 * Prints the main menu prompt each time it is requested by the main function
 * Parameter(s): none
 * Returns: void (no return)
 */
void printMainMenu()
{
    cout << "--- Menu ---\n1. Calculate similarity between two tunes.\n" <<
    "2. Calculate best similarity between two tunes of potentially different lengths.\n" <<
    "3. Print three input tunes in order from most to least similar to the target tune.\n4. Exit.\n" <<
    "Please enter your choice (1 - 4):\n";
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
        cout << "1) Tune 1, 2) Tune 2, 3) Tune 3\n";
    }else if(tune1Similarity >= tune3Similarity && tune3Similarity > tune2Similarity)
    {
        cout << "1) Tune 1, 2) Tune 3, 3) Tune 2\n";
    }else if(tune2Similarity > tune1Similarity && tune1Similarity >= tune3Similarity)
    {
        cout << "1) Tune 2, 2) Tune 1, 3) Tune 3\n";
    }else if(tune2Similarity >= tune3Similarity && tune3Similarity > tune1Similarity)
    {
        cout << "1) Tune 2, 2) Tune 3, 3) Tune 1\n";
    }else if(tune3Similarity > tune1Similarity && tune1Similarity >= tune2Similarity)
    {
        cout << "1) Tune 3, 2) Tune 1, 3) Tune 2\n";
    }else{
        cout << "1) Tune 3, 2) Tune 2, 3) Tune 1\n";
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

    //If input lengths don't match, similarity is 0
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

    //Returns double according to the specified formula - calculates similarity
    return double(numMatchingNotes) / double(totalNotes) + numMatchingNotesPitches - numDifferentNotesPitches;

}


//numValidNotes function definition

/** 
 * Algorithm: Counts the number of valid notes within a given input tune
 * 1. Input tune is passed into a function as a string
 * 2. Number of valid notes initially set to 0
 * 3. If the length of input is less than 2, return 0 (can't contain valid notes)
 * 4. Iterate through the input tune and increment the number of valid notes
 *    each time one is found
 * Parameter(s): input (string)
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
