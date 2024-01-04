// printMelody.cpp
// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 4 - Problem # 6 - EC

#include <iostream> //imports
#include <cmath>
#include <vector>
#include <string>

//User input frequency
double frequency;

//Piano note number and octave from user input frequency
int noteNumber;

//Contains all base notes
std::string baseNotes[12] = {"C", "d", "D", "e", "E", "F", "g", "G", "a", "A", "b", "B"};

std::vector<std::string> melody; //Contains melody 

//Inputs a note number and returns a note with its octave
std::string getNoteOctave(int);

//Incrememnts the noteNumber to the proper note of the melody
void incrementMelody(int &noteNumber);

int main()
{

    //User prompt
    std::cout << "What is your frequency?\n";   
    std::cin >> frequency;

    //Note validity check
    if(frequency < 32.7 || frequency > 4186)
    {
        std::cout <<  "Your note is not on a piano.\n";
        return 0;
    }

    //Finds note and octave from frequency input
    noteNumber = round(12 * log2(frequency / 32.7));

    //Note prompt
    std::cout << "Your note is: " << getNoteOctave(noteNumber) << ".\n";
   
   //Creates melody and appends each note to the melody vector
    while(1)
    {
        if(noteNumber < 0)
        {
            break;
        }
        melody.push_back(getNoteOctave(noteNumber));
        incrementMelody(noteNumber);
    }

    std::cout << "Your melody is: ";

    //Prints each note from the melody
    for(auto i = melody.begin(); i != melody.end(); i ++)
    {
        std::cout << *i << ", ";
    }

    std::cout << "\n";


    return 0;
}

//returns a string containing a note number's note and octave
std::string getNoteOctave(int noteNumber)
{
    std::string returnString = baseNotes[noteNumber % 12];
    returnString.append(std::to_string(noteNumber / 12 + 1));

    return returnString;
}

//Progresses melody by altering the actual noteNumber
void incrementMelody(int &noteNumber)
{
    if(noteNumber % 12 == 1 || noteNumber % 12 == 3 || noteNumber % 12 == 6 || noteNumber % 12 == 8 || noteNumber % 12 == 10)
    {
        noteNumber += 4;
    }
    else
    {
        noteNumber -= 7;
    }
}
