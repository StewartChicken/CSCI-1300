//fullClass.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 5 - Question 4
#include <iostream>

using std::cout;

//Function declarations
void fullClass(bool seating[][4], int rows, int waitlistSize);

int main()
{
    /*Test1, expected output
        1111    
        1111
        1110
        0101
        Remaining Studends: 0
    */
    bool classroom1[4][4] = {{0, 1, 1, 1},
			{0, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 0, 1}};
    int waitlist1 = 6;
    fullClass(classroom1, 4, waitlist1);

    /*Test1, expected output
        1111    
        1111
        1111
        Remaining Studends: 1
    */
    bool classroom2[3][4] = {{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0}};
    int waitlist2 = 9;
    fullClass(classroom2, 3, waitlist2);

    return 0;
}

//fullClass definition
void fullClass(bool seating[][4], int rows, int waitlistSize)
{
    //new waitlist size
    int newWaitlist = waitlistSize;

    //Loops through every member of the waitlist and every column/row in the class
    for(int i{}; i < waitlistSize; i ++)
    {
        for(int j{}; j < rows; j ++)
        {
            for(int k{}; k < 4; k ++)
            {
                //If a seat is available and there are individuals on the waitlist
                //fill that seat and decrease the waitlist size
                if(!seating[j][k] && newWaitlist > 0)
                {
                    seating[j][k] = true;
                    newWaitlist --;
                }
            }
        }
    }

    //Prints every row/column of new seating arrangement
    for(int i{}; i < rows; i ++)
    {
        for(int j{}; j < 4; j ++)
        {
            cout << seating[i][j];
        }
        //New line
        cout << "\n";
    }

    //Prints remaining students on waitlist
    cout << "Remaining Students: " << newWaitlist << "\n";

}