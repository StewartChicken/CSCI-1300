//vacation.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyler Ruvane
// Homework 3 - Problem 2

#include <iostream> //Import

using namespace std; //Namespace

double budget; //User's budget
char transport; //User's preferred method of transport

const float busCost = 175.25; //Ticket prices
const float trainCost = 240.66;
const float planeCost = 350.93;

void checkBusBudget(float budget); //Function declarations
void checkTrainBudget(float budget);
void checkPlaneBudget(float budget);

int main(){ //Main funcetion

	//budget input
	cout << "What is your budget?\n";
	cin >> budget;

	if(budget < 0){
		cout << "Please enter a valid input.\n";
		return 0;
	}

	//transport method input
	cout << "What mode of transportation would you like to take (B, T, or A)?\n";
	cin >> transport;

	//switch to determine which ticket price to compare the budget to depending on
	//the desired method of travel
	switch(transport){
		case 'A':
			checkPlaneBudget(budget);
			break;
		case 'B':
			checkBusBudget(budget);
			break;
		case 'T':
			checkTrainBudget(budget);
			break;
		default:
			cout << "Please enter a valid input.\n";
			break;
	}
	
	return 0; //Main return
}

//Budget comparison methods: compares the budget to the cost of the desired method of travel
void checkBusBudget(float budget){
	if(budget < busCost){
		cout << "Sorry, this vacation is outside your budget.\n";
	}else{
		cout << "Yes, this vacation is within your budget!\n";
	}
}

void checkTrainBudget(float budget){
	if(budget < trainCost){
		cout << "Sorry, this vacation is outside your budget.\n";
	}else{
		cout << "Yes, this vacation is within your budget!\n";
	}
}

void checkPlaneBudget(float budget){
	if(budget < planeCost){
		cout << "Sorry, this vacation is outside your budget.\n";
	}else{
		cout << "Yes, this vacation is within your budget!\n";
	}
}



