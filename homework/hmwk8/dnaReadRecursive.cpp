//dnaReadRecursive.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 8 - Question 2 - EC

//Inclusions
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using std::string;
using std::vector;
using std::cout;
using std::endl;

//Function declarations
string dnaReadRecursive(vector<string> &dna);
string processCodon(const vector<string> & dna, int, bool);
bool compareStrings(string a, string b);

//Main
int main()
{
    //Test cases

    //Test vectors
    vector<string> dna1{"ATG", "TCA", "TGA"};
    vector<string> dna2{"ATG", "CAT", "ACT", "GAC", "TAA", "ACT", "TAC"};
    vector<string> dna3{"CAT", "ACT", "GAC", "TAA", "ACT", "TAC"};
    vector<string> dna4{"CAT", "AT", "GAC", "TAA", "ACT", "TAC"};
    vector<string> dna5{"ACT", "TAC", "GAT", "TAG", "AGT", "GAT", "TCG", "CGT", "ACT"};
    vector<string> dna6{"ATG", "TAC", "GAT", "TAG", "AGT", "GAT", "TCG", "CGT", "ACT"};
    vector<string> dna7{"ATG", "TAC", "GAT", "TGG", "AGT", "GAT", "TCG", "CGT", "ACT"};
    vector<string> dna8{"ATG", "TVC", "GAT", "TGG", "AGT", "GAT", "TCG", "CGT", "ACT"};

    //Assertions
    assert(compareStrings(dnaReadRecursive(dna1), "TCA"));
    assert(compareStrings(dnaReadRecursive(dna2), "CATACTGAC"));
    assert(compareStrings(dnaReadRecursive(dna3), ""));
    assert(compareStrings(dnaReadRecursive(dna4), "Invalid sequence."));
    assert(compareStrings(dnaReadRecursive(dna5), ""));
    assert(compareStrings(dnaReadRecursive(dna6), "TACGAT"));
    assert(compareStrings(dnaReadRecursive(dna7), "TACGATTGGAGTGATTCGCGTACT"));
    assert(compareStrings(dnaReadRecursive(dna8), "Invalid sequence."));

    //Pass statement
    cout << "All tests passed" << endl;
    return 0;
}

//dnaReadRecursive function definition - calls the recursive function processCodon
// which will read through entire dna sequence and find the sequence between
// the start and stop codons
string dnaReadRecursive(vector<string> &dna) {

    //Call processCodon with an initial state - index = 0, start codon found = false
    return processCodon(dna, 0, false);
}

//processCodon function definition
//Recursively loops through the dna sequence and creates a string of
// dna that starts with the start codon and ends with the stop codon.
// If index is out of bounds of the dna sequence, return empty string
// If current codon is invalid - not length 3, contains incorrect characters, reeturn "Invalid sequence."
// If start codon is found, recursively call function
// If end codon is found, return empty string
// Return recursively called function that builds dna sequence string
string processCodon(const vector<string>& dna, int index, bool startCodonFound) {
    
    //Base case - reached end of dna sequence
    if (index >= dna.size()) {
        return "";
    }

    //Checks validity of current codon
    if (dna.at(index).length() != 3 || dna.at(index).find_first_not_of("ACGT") != string::npos) {
        return "Invalid sequence.";
    }

    //If the start codon has not been found and the current index is the start codon,
    //recursively calls processCodon with an index of index + 1
    if (!startCodonFound && dna.at(index) == "ATG") 
    {
        return processCodon(dna, index + 1, true);
    } 
    //If the start codon has been found
    else if (startCodonFound) 
    {
        //If the current codon is the stop codon,
        if (dna.at(index) == "TAA" || dna.at(index) == "TAG" || dna.at(index) == "TGA") 
        {
            //Return empty string
            return "";
        } 
        else 
        {
            //If the current codon is neither the start, nor the stop codon, 
            //recursively call the processCodon function with an index of index + 1
            return dna.at(index) + processCodon(dna, index + 1, true);
        }
    } 
    else 
    {
        //Start codon not found, continue searching for start codon
        return processCodon(dna, index + 1, false);
    }
}

//compareStrings function definition
bool compareStrings(string a, string b) 
{
    //Strings not same length
    if(a.length() != b.length())
    {
        return false;
    }

    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] != b[i])
        {
            return false;
        }
    }

    return true;
}