//tubing.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyler Ruvane
// Homework 3 - Problem 1

#include <iostream> //Import

using namespace std; //Namespace

int rate;
const int MAXRATE = 250; //Max flow rate


int main(){ //Main function
	cout << "What is the flowrate of Boulder Creek?\n"; //Request and assign user input
	cin >> rate;

	//Conditionals (is it safe to tube)
	if(rate <= 0){
		cout << "Please enter a valid input.\n";
		return 0;
	}else if(rate <= MAXRATE){
		cout << "It is safe to go tubing. Have fun!\n";
		return 0;
	}else{
		cout << "The river is flowing too fast to go tubing.\n";
	}

	return 0; //Main return
}
