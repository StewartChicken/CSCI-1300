
//hikeStats.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 6 - Question 3

//Includes
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <iomanip>

using std::cout;
using std::string;
using std::ifstream;
using std::getline;
using std::endl;

//Function declarations
int split(string, char, string[], int);
void printHikeStats(string);

//Main
int main()
{

    //Test cases

    //1
    //Expected output:
    /*
    Number of lines read: 6.
    Longest hike: Continental Divide Trail at 3100 miles.
    Shortest hike: The Colorado Trail at 578 miles.
    Steepest hike: The Pacific Crest Trail at 311.1 feet gained per mile.
    */
    printHikeStats("long_hikes.txt");

    //2
    //Expected output:
    //Could not open file. 
    printHikeStats("does-not-exist.txt");

    //3
    //Expected output:
    /*
    Number of lines read: 3.
    Longest hike: Continental Divide Trail at 3100 miles.
    Shortest hike: The South West Coast Path at 630 miles.
    Steepest hike: Great Himalayan Trail at 273.7 feet gained per mile.
    */
    printHikeStats("long_hikes2.txt");
    
    //4
    //Expected output
    /*
    Number of lines read: 1.
    Longest hike: The South West Coast Path at 630 miles.
    Shortest hike: The South West Coast Path at 630 miles.
    Steepest hike: The South West Coast Path at 182.5 feet gained per mile.
    */
    printHikeStats("single_hike.txt");

    //Return
    return 0;
}

//printHikeStats function definition
//Will read a file of hike statistics and print longest, shortest, and steepest hike
//Checks to see if each line is a valid hike stat line, if not skips it
//Splits each valid line of the text file into a temporary array of strings
//Checks each hike against the current longest, steepest, and shortest hike
//If hike is longer, steeper, or shorter than the current hike, replaces it
//Parameters : string fileName 
//Return type : void
void printHikeStats(string fileName)
{

    //Contains current line
    string line;

    //File stream
    ifstream fin;

    //Open input file
    fin.open(fileName); 

    //Number of valid lines
    int numLines = 0;

    //Longest hike and its length
    string longestHike;
    int longestLength = 0;

    //Shortest hike and its length
    string shortestHike;
    int shortestLength = 99999999;

    //Steepest hike and its elevation gain
    string steepestHike;
    double elevationGain = 0;

    //If fails to open file
    if (fin.fail())
        {
            cout << "Could not open file." << endl;
            return;
        }
    else
    {
        while (!fin.eof()) //Continues to loop while there is data in the text file
        {
            string currHikeArr[3];

            //Gets line
            getline(fin, line);

            //If line is blank
            if(line.length() == 0)
            {
                continue;
            }

            //Increments number of lines
            numLines ++;

            //Splits current line into array of three strings containing the
            //hike name, length, and elevation gain
            split(line, '|', currHikeArr, 3);

            //Checks for new longest hike
            if(std::stoi(currHikeArr[1]) > longestLength)
            {
                longestHike = currHikeArr[0];
                longestLength = std::stoi(currHikeArr[1]);
            }

            //Checks for new shortest hike
            if(std::stoi(currHikeArr[1]) < shortestLength)
            {
                shortestHike = currHikeArr[0];
                shortestLength = std::stoi(currHikeArr[1]);
            }

            //Checks for new steepest hike
            if(std::stod(currHikeArr[2]) / std::stod(currHikeArr[1]) > elevationGain) 
            {
                steepestHike = currHikeArr[0];
                elevationGain = std::stod(currHikeArr[2]) / std::stod(currHikeArr[1]);
            }

        } 
    
        //Close file
        fin.close();
    }

    //Print stats

    cout <<  "Number of lines read: " << numLines << ".\n";

    cout << "Longest hike: " << longestHike << " at " << longestLength << " miles.\n";

    cout << "Shortest hike: " << shortestHike << " at " << shortestLength << " miles.\n";

    cout << std::fixed << std::setprecision(1) << "Steepest hike: " << steepestHike << " at " << elevationGain << " feet gained per mile.\n";
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
