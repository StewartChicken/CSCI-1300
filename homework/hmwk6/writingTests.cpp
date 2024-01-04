//writingTests.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 6 - Question 1

//Includes
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

//Function declarations
int countWord(string, string);
bool readFile(string, string);

int main()
{
    // write at least 6 additional test cases to test countWord()

    //Edge case 1 - counts empty string
    assert(countWord("Hello World", "") == 0);

    //Edge case 2 - counts number of capitalized versions of a word
    //This assertion fails because the last 'And' is not counted by the function
    //assert(countWord("And, and and And", "And") == 2);

    //Edge case 3 - counts number of non-word appearances
    assert(countWord("Using, too, many, commas", ",") == 3);
    
    //Test case 4
    //Find number of occurances of "a"
    //This assertion fails because the function counts every appearance of a 
    //letter 'a' and not the appearances of the word 'a'
    //assert(countWord("A dog ran away to a far place", "a") == 1);
    
    //Test case 5
    //Finds the number of accurances of "fairest"
    assert(countWord("From fairest creatures we desire increase", "fairest") == 1);

    //Test case 6
    //Finds the number of accurances of "five"
    assert(countWord("One 1 two 3 four five 5", "five") == 1);


    // write at least 6 additional test cases to test readFile()
 
    assert(readFile("shakespeare_sonnet.txt", "to") == true);

    //Edge case 1 - checks if the number of "To's" is less than three since the number
    //of "to's" is greater
    assert(readFile("shakespeare_sonnet.txt", "To") == false);

    //Edge case 2 - checks number of non-word characters ","
    assert(readFile("shakespeare_sonnet.txt", ",") == true);

    //Test case 3 "thou"
    assert(readFile("shakespeare_sonnet.txt", "thou") == false);

    //Test case 4 - word that doesn't appear
    assert(readFile("shakespeare_sonnet.txt", "vibe") == false);

    //Test case 5 - number
    assert(readFile("shakespeare_sonnet.txt", "4") == false);

    //Test case 6 - "Thy"
    assert(readFile("shakespeare_sonnet.txt", "to") == true);

    return 0;
}

/*
    Counts the number of a given word
    found in the given input string. 
    Returns 0 if word's length is 0.
*/
int countWord(string input, string word)
{
    int count = 0;
    int word_length = word.length();
    
    // special case for words of length 0
    if (word_length == 0)
    {
        return 0;
    }

    // loop through the input string to check every possible match
    for (int i = 0; i < input.length() - word_length; i++)
    {
        if (input.substr(i, word_length) == word) // add one to total count if it matches desired word
            count += 1;
    }

    return count;
}

/*
    Takes a given file name and reads the contents. 
    Counts the occurences of a specific word on each line.
    Prints the line number and the number of occurences for each line.
    At the end, prints the total number of occurences.
    Returns true if the total number of occurences was greater than 3.
*/
bool readFile(string file_name, string word)
{
    bool result = false;  // final result to return at end
    int total_count = 0;  // counts total occurrences of letter
    int line_count = 0;   // count of occurrences of letter for a single line

    string line;    // variable for storing each line as we read it
    ifstream fin;   // file input stream

    fin.open(file_name); // Open input file
    
    if (fin.fail())
    {
        cout << "File couldn't be opened!" << endl;
        result = false;
    }
    else
    {
        // read every line of file, count number of matches on each line
        int line_number = 0;
        while (!fin.eof()) // continue looping as long as there is data to be processed in the file
        {
            line_number += 1;
            getline(fin, line);

            line_count = countWord(line, word);
            total_count += line_count;

            cout << "Line: " << line_number << ", Occurences: " << line_count << endl;
        } 
    
        // print the total count to user
        cout << "Total occurences: " << total_count << endl;

        // update result of function -- is true if total count greater than 3
        result = total_count > 3;

        // close files
        fin.close();
    }

    return result;
}
