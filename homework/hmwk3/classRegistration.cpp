//classRegistration.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyler Ruvane
// Homework 3 - Problem 5

#include <iostream> 

using namespace std; 

int selection; //monitors user's current selection

//Department selection screen options
void CSClassSelection();
void mathClassSelection();
void scienceClassSelection();

//Array that contains all the classes
int sections[16] = {100, 200, 101, 201, 102, 202, 400, 500, 401, 501, 402, 502, 700, 800, 701, 801};

//Tracks which sections will be available depending on the user's department/class choice
int sectionTraversalTracker = 0;

//Prompts user to select a section based on the department and class chosen
//The parameters are a location (determined by the sectionTraversalTracker value)
//and the 'sections' array
void sectionSelection(int, int*);

string classSelection; //Stores the specific class name that the user selected

int main()
{
    cout << "Select a department: (1)Computer Science (2)Math (3)Science\n";
    cin >> selection;

    switch(selection)
    { //Select which department. Calls respective functions for the user's input
        case 1:
            CSClassSelection();
            break;
        case 2:
            mathClassSelection();
            break;
        case 3: 
            scienceClassSelection();
            break;
        default:
            cout << "Please enter a valid input.\n";
            break;
    }

    return 0;
}

//CSCI department class selection function
void CSClassSelection()
{ 
    
    //User prompt
    cout << "Select a class: (1)Starting Computing (2)Data Structures (3)Algorithms\n";
    cin >> selection;

    //Class selection options
    switch(selection)
    { 
        case 1:
            sectionTraversalTracker = 0;
            classSelection = "Starting Computing";
            sectionSelection(sectionTraversalTracker, sections);
            break;
        case 2:
            sectionTraversalTracker = 2;
            classSelection = "Data Structures";
            sectionSelection(sectionTraversalTracker, sections);
            break;
        case 3: 
            sectionTraversalTracker = 4;
            classSelection = "Algorithms";
            sectionSelection(sectionTraversalTracker, sections);
            break;
        default:
            cout << "Please enter a valid input.\n";
            break;
    }
}

//Math department class selection function
void mathClassSelection()
{

    //User prompt
    cout << "Select a class: (1)Calculus 1 (2)Calculus 2 (3)Linear Algebra\n";
    cin >> selection;

    //Class selection options
    switch(selection)
    {
        case 1:
            sectionTraversalTracker = 6;
            classSelection = "Calculus 1";
            sectionSelection(sectionTraversalTracker, sections);
            break;
        case 2:
            sectionTraversalTracker = 8;
            classSelection = "Calculus 2";
            sectionSelection(sectionTraversalTracker, sections);
            break;
        case 3: 
            sectionTraversalTracker = 10;
            classSelection = "Linear Algebra";
            sectionSelection(sectionTraversalTracker, sections);
            break;
        default:
            cout << "Please enter a valid input.\n";
            break;
    }
}

//Science department class selection function
void scienceClassSelection()
{

    //User prompt
    cout << "Select a class: (1)General Chemistry 1 (2)Physics 1\n";
    cin >> selection;

    //Class selection options
    switch(selection)
    {
        case 1:
            sectionTraversalTracker = 12;
            classSelection = "General Chemistry 1";
            sectionSelection(sectionTraversalTracker, sections);
            break;
        case 2:
            sectionTraversalTracker = 14;
            classSelection = "Physics 1";
            sectionSelection(sectionTraversalTracker, sections);
            break;
        default:
            cout << "Please enter a valid input.\n";
            break;
    }
}

//selection implementation. Takes in the 'sectionTraversalTracker' value and the array of section numbers as arguments
void sectionSelection(int location, int *sectionArray)
{
    //User prompt
    cout << "Select a section: (1)Section " << sectionArray[location] << " (2)Section " << sectionArray[location + 1] << "\n";
    cin >> selection;

    //You've been enrolled in Section 102 of Algorithms!
    switch(selection)
    {
        case 1:
            cout << "You've been enrolled in Section " << sectionArray[location] << " of " << classSelection << "!\n";
            break;
        case 2:
            cout << "You've been enrolled in Section " << sectionArray[location + 1] << " of " << classSelection << "!\n";
            break;
        default:
            cout << "Please enter a valid input.\n";
            break;
    }
}