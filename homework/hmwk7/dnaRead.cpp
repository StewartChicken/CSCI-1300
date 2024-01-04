//dnaRead.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 7 - Question 2

//Inclusions
#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
using std::cout;
using std::endl;
using std::string;

//Function definitions
string dnaRead(vector<string>);
bool compareStrings(string, string);

//Main function
int main()
{

    //Test cases
    vector<string> dna1{"ATG", "TCA", "TGA"};
    assert(compareStrings(dnaRead(dna1), "TCA"));

    vector<string> dna2{"ATG", "CAT", "ACT", "GAC", "TAA", "ACT", "TAC"};
    assert(compareStrings(dnaRead(dna2), "CATACTGAC"));

    vector<string> dna3{"CAT", "ACT", "GAC", "TAA", "ACT", "TAC"};
    assert(compareStrings(dnaRead(dna3), ""));

    vector<string> dna4{"CAT", "AT", "GAC", "TAA", "ACT", "TAC"};
    assert(compareStrings(dnaRead(dna4), "Invalid sequence."));

    	
    vector<string> dna5{"ACT", "TAC", "GAT", "TAG", "AGT", "GAT", "TCG", "CGT", "ACT"};
    assert(compareStrings(dnaRead(dna5), ""));

    cout << "All tests passed!" << endl;

    //Return value
    return 0;
}

//dnaRead function definition
/**
 * @brief 
 * Given an input of vector strings, determines the valid DNA sequence
 * If any of the codons are not of length 3, returns invalid sequence
 * If any of the codons do not contain valid letters, returns invalid sequence
 * Creates new DNA string from input vector of strings
 *  between start and stop codons
 * 
 * @param dna 
 * @return string 
 */
string dnaRead(vector<string> dna)
{
    //Checks for string validity
    for(int i = 0; i < dna.size(); i++)
    {
        //Checks if string is less than 3
        if(dna.at(i).length() != 3)
        {
            return "Invalid sequence.";
        }

        //Checks if string contains invalid codons
        for(int j = 0; j < 3; j++)
        {
            if(dna.at(i)[j] != 'A' && dna.at(i)[j] != 'C' && dna.at(i)[j] != 'G' && dna.at(i)[j] != 'T')
            {
                return "Invalid sequence.";
            }
        }
    }

    //Creates new DNA string
    string newString = "";

    //Determines if string is between the start and stop codons
    bool activeRead = false;

    //Appens new codons to new string so long as they are in between the start and stop codons
    for(int i{}; i < dna.size(); i++)
    {
        //If start codon is found
        if(dna.at(i) == "ATG")
        {
            activeRead = true;
            continue;
        }

        //If end codon is reachec
        if(dna.at(i) == "TAA" || dna.at(i) == "TAG" || dna.at(i) == "TGA")
        {
            activeRead = false;
            break;
        }

        //If inbetween start and stop codons, append to new string
        if(activeRead)
        {
            newString += dna.at(i);
        }
    }

    //return newString
    return newString;
}


//compareStrings function definition
//if the string lengths are not equal, return false
//iterate through strings - if one character doesn't match, return false
//otherwise, return true
//Parameters: string, string
//Return type: boolean
bool compareStrings(string a, string b)
{
    if(a.length() != b.length())
    {
        return false;
    }

    for(int i{}; i < a.length(); i ++)
    {
        if(a[i] != b[i])
        {
            return false;
        }
    }

    return true;
}

