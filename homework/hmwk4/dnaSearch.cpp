// dnaSearch.cpp
// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 4 - Problem # 4

#include <iostream>

//dna sequence and fragment
std::string dnaSequence;
std::string fragment;

int fragmentLen, numOccurances;

//DNA characters
std::string bases[4] = {"A", "C", "G", "T"};

int main()
{

    //User prompt
    std::cout << "Enter the DNA Sequence: \n";
    std::cin >> dnaSequence;

    //Checks if user input is a valid DNA sequence
    for(int i{}; i < dnaSequence.length(); i ++)
    {
        bool validLetter = false;
        for(int j{}; j < sizeof(bases) / sizeof(bases[0]); j ++)
        {
            if(dnaSequence.substr(i, 1) == bases[j])
            {
                validLetter = true;
                break;
            }
        }
        if(!validLetter)
        {
            std::cout << "This is not a valid DNA sequence.\n";
            return 0;
        }
    }

    //User prompt for fragment to be searched
    std::cout << "Enter the DNA fragment to be searched:\n";
    std::cin >> fragment;

    //Checks if user input is a valid DNA fragment
    for(int i{}; i < fragment.length(); i ++)
    {
        bool validLetter = false;
        for(int j{}; j < sizeof(bases) / sizeof(bases[0]); j ++)
        {
            if(fragment.substr(i, 1) == bases[j])
            {
                validLetter = true;
                break;
            }
        }
        if(!validLetter)
        {
            std::cout << "This is not a valid DNA sequence.\n";
            return 0;
        }
    }

    //Counts number of sequences
    fragmentLen = fragment.length();
    numOccurances = 0;

    for(int i{}; i < dnaSequence.length() - (fragmentLen - 1); i ++)
    {
        if(dnaSequence.substr(i, fragmentLen) == fragment)
        {
            numOccurances ++;
        }
    }
    
    std::cout << "Number of occurrences: " << numOccurances << "\n";
    return 0;
}