
//emails.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 6 - Question 2

//Includes
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;

//Function declarations
int split(string, char, string[], int);
int readEmails(string);

//Main
int main()
{
    //Test cases

    //Expected output 
    //Number of emails: 3
    assert(readEmails("emails.txt") == 3);

    //Expected output
    //Number of emails: 0
    assert(readEmails("shakespeare_sonnet.txt") == 0);

    //Expected output
    //Could not open file.
    assert(readEmails("nonExistant.txt") == -1);

    //Expected output
    //Number of emails: 4
    assert(readEmails("Lots_of_emails.txt") == 9);

    //Return
    return 0;
}

//readEmails definition
//Reads a list of emails and detects which ones are valid
//An email is valid if it contains the correct number of splits
//Uses split function to determine the validity of the email
//Returns number of valid emails
//Parameters : string (input file)
//Return type : int (num valid emails)
int readEmails(string file)
{
    //Current line
    string line;

    //File input stream
    ifstream fin;   

    int numEmails = 0;

    //Open input file
    fin.open(file); 

    //Stores parts of the email
    string arr[4];

    if (fin.fail())
    {
        cout << "Could not open file." << endl;
        return -1;
    }
    else
    {
        while (!fin.eof()) //Continues to loop while there is data in the text file
        {
            //Gets line
            getline(fin, line);
            if(split(line, '~', arr, 4) == 4)
            {   
                //Increments number of emails if it finds a valid email
                numEmails ++;
            }

        } 
    
        //Close file
        fin.close();
    }
    
    cout << "Number of emails: " << numEmails << "." << endl;
    return numEmails;
    
}

//split function definition
//Splits each string at a given splitter character and stores each part in a new array
//Will iterate through each string in search of the splitter character and split
//the string/add the substring to the new array until the array is full
//If the length of the initial string is 0, returns 0
//If there are more splits than can be stored in the array, returns -1
//parameters: string input, char splitter, string array, int size
//returns int (number of splits)
int split(string mainString, char splitter, string array[], int size)
{

    //Number of splits
    int split = 1;

    //Current index of traversal for array of strings
    int currIndex = 0;

    //If empty string, return 0
    if(mainString.length() == 0)
    {
        return 0;
    }

    //Loops through each character of the mainString for the same number of times as the "size" parameter
    for(int i{}; i < size; i ++)
    {
        for(int j = 0; j < mainString.length(); j ++)
        {
            //If character is delimiter
            if(mainString[j] == splitter)
            {
                //Adds sliced section of string to array
                array[i] = mainString.substr(0, j);
                //Modfies mainString
                mainString = mainString.substr(j + 1, mainString.length() - j);
                //Incrememnts number of splits and current index
                split ++;
                currIndex ++;
                break;
            }

        }

    }

    //Last element is equal to remainder of mainString
    array[currIndex] = mainString;

    //If there are mores splits than the size of the array, return -1
    if(split > size){
        return -1;
    }

    //Returns split
    return split;
}
