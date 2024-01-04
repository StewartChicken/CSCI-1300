
//computeScore.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 6 - Question 4b

//Includes
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cassert>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;

//function declarations
void calcOverallScore(string hikeNames[], int ratings[][4], int numHikes);
int split(string, char, string[], int);
int readHikeReviews(string, string[], int[][4], int);
bool compareStrings(string, string);


//main
int main()
{

    int ratings[4][4];
    string hikeNames[4];

    //test cases

    //
    //1
    /*Expected Output
    Continental Divide Trail overall score: 44.6
    Great Himalayan Trail overall score: 39.6
    The Appalachian Trail overall score: 33.9
    The South West Coast Path overall score: 71.0
    */
    readHikeReviews("hike_ratings.txt", hikeNames, ratings, 4);
    calcOverallScore(hikeNames, ratings, 4);

    //2
    //Expected output
    //Could not open file.
    readHikeReviews("DoesNotExist.txt", hikeNames, ratings, 4);
    calcOverallScore(hikeNames, ratings, -1);

    //3
    //Expected output
    /*
    Continental Divide Trail overall score: 44.6
    Great Himalayan Trail overall score: 39.6
    The Appalachian Trail overall score: 33.9
    The South West Coast Path overall score: 71.0
    Some cool hike overall score: 29.6
    */
    int ratings2[5][4];
    string hikeNames2[5];
    readHikeReviews("lots_of_ratings.txt", hikeNames2, ratings2, 5);
    calcOverallScore(hikeNames2, ratings2, 5);

    //4
    //Expected output
    /*
    Continental Divide Trail overall score: 44.6
    */
    readHikeReviews("one_hike.txt", hikeNames, ratings, 4);
    calcOverallScore(hikeNames, ratings, 1);

    //Return
    return 0;
}

//calcOverallScore function definition
//score = (7.3 * Avg View Rating) + (-.22 * Avg Difficulty Rating) + (3.4 * Avg Weather Rating)
//calculates the overall score using the above formula
//returns void
//parameters : array of strings, double array of ints, int number of hikes
void calcOverallScore(string hikeNames[], int ratings[][4], int numHikes)
{

    if(numHikes == -1)
    {
        cout << "Could not open file." << endl;
        return;
    }
    //will contain the score of each hike
    double score;

    //loops through each hike and calculates the score
    for(int i{}; i < numHikes; i ++)
    {
        score = ( (7.3 * (double(ratings[i][1]) / ratings[i][0])) + (-0.22 * (double(ratings[i][2]) / 
        ratings[i][0])) + (3.4 * (double(ratings[i][3])) / ratings[i][0]));

        //prints score
        cout << std::fixed << std::setprecision(1) << hikeNames[i] << " overall score: " << score << "\n";
    }
    
}

//readHikeReviews function definition
//reads file of hike reviews
//skips invalid hike reviews - blank lines or invalid ratings
//creates temporary array of strings that contains all the data 
// using the split function
//adds initial hike to ratings and hikeNames arrays
//iterates through each valid line of the reviews file and 
//checks if the line contains a duplicate hike or a new hike
//if the hike is a duplicate, it adds to the previous hike's stats
//if hike is new, creates new row of hike data
//Parameters : string, array of strings, double array of ints, int
//returns int (number of unique hikes)
int readHikeReviews(string fileName, string hikeNames[], int ratings[][4], int numUniqueHikes)
{
    //Contains current line
    string line;

    //File stream
    ifstream fin;

    //Open input file
    fin.open(fileName); 

    //Number of hikes
    int numHikes = 0;

    //Tracks present location in hikeNames array to prevent doubles
    int hikeNamesIndex = 0;

    //If fails to open file
    if (fin.fail())
    {
        //cout << "Could not open file." << endl;
        return -1;
    }

    else
    {
        while (!fin.eof()) //Continues to loop while there is data in the text file
        {
            string currHikeArr[4];

            //Gets line
            getline(fin, line);

            //If line is blank
            if(line.length() == 0)
            {
                continue;
            }

            int numSplits = split(line, ',', currHikeArr, 4);

            if(numSplits != 4)
            {
                continue;
            }

            //If the hikeIndex is at the first element, meaning that nothing has been added yet
            if(hikeNamesIndex == 0)
            {
                //Assigns firstElement of hikeNames to the current hike name
                hikeNames[hikeNamesIndex] = currHikeArr[0];
                
                //Sets number of reviews to 1 for the first element
                ratings[hikeNamesIndex][0] = 1; 

                //Sets view rating initial value for first hike
                ratings[hikeNamesIndex][1] = stoi(currHikeArr[1]); 

                //Sets difficulty initial value for first hike
                ratings[hikeNamesIndex][2] = stoi(currHikeArr[2]); 

                //Sets weather initial value for first hike
                ratings[hikeNamesIndex][3] = stoi(currHikeArr[3]); 

                //Increments the number of hikes and the hike index
                numHikes ++;
                hikeNamesIndex ++;

            }
            //If the hikeNames and ratings arrays have their first elements filled
            else
            {
                //If the current hike string and the previous index are the same, meaning the
                //curren the hike and the previous one are the same
                if(compareStrings(currHikeArr[0], hikeNames[hikeNamesIndex - 1]))
                {

                    //Increments and adds to the ratings of the previous hike
                    ratings[hikeNamesIndex - 1][0] += 1;
                    ratings[hikeNamesIndex - 1][1] += stoi(currHikeArr[1]);
                    ratings[hikeNamesIndex - 1][2] += stoi(currHikeArr[2]);
                    ratings[hikeNamesIndex - 1][3] += stoi(currHikeArr[3]);
                    
                }
                else
                {

                    //If the number of hikes ever exceeds the number of unique hikes, breaks the loop
                    if(numHikes == numUniqueHikes)
                    {
                        break;
                    }
                    //Adds new hike at current hikeNamesIndex
                    hikeNames[hikeNamesIndex] = currHikeArr[0];
                    ratings[hikeNamesIndex][0] = 1;
                    ratings[hikeNamesIndex][1] = stoi(currHikeArr[1]);
                    ratings[hikeNamesIndex][2] = stoi(currHikeArr[2]);
                    ratings[hikeNamesIndex][3] = stoi(currHikeArr[3]);

                    numHikes ++;
                    hikeNamesIndex ++;
                }
            }

        }

        //Close file
        fin.close();
    }

    //Prints out each value in the ratings array
    /*for(int i{}; i < numHikes; i ++)
    {
        cout << "names[" << i << "] = " << hikeNames[i]  << endl;
    }

    for(int i{}; i < numHikes; i ++)
    {
        cout << std::fixed << std::setprecision(2) << "num reviews: " << ratings[i][0] << ", avg view: " << 
        (double(ratings[i][1]) / ratings[i][0]) << " / 10, avg difficulty: " <<
        (double(ratings[i][2]) / ratings[i][0]) << " / 100, avg weather: " <<
        (double(ratings[i][3]) / ratings[i][0]) << " / 7,\n";
    }*/
    return numHikes;
    
}

//compareStrings definition - checks if two strings are equal
//if the lengths don't match, return false
//iterates through both string and compares each character
//if any pair of characters don't match, return false
//by default, return true
//Parameters : string a and string b
//Return : bool
bool compareStrings(string a, string b)
{
    //If length isn't the same, return false
    if(a.length() != b.length())
    {
        return false;
    }

    //Iterates both strings and checks if each character is the same
    for(int i{}; i < a.length(); i ++)
    {
        if(a[i] != b[i])
        {
            return false;
        }
    }

    //If false hasn't already been returned, returns true
    return true;
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

    //Number of splitters
    int numSplitters = 0;
    
    for(int i{}; i < mainString.length(); i ++)
    {
        if(mainString[i] == splitter)
        {
            numSplitters ++;
        }
    }
    
    if(numSplitters >= size)
    {
        return -1;
    }

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


    //Returns split
    return split;
}
