//pizza.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyler Ruvane
// Homework 3 - Problem 3

#include <iostream> //Imports
#include <iomanip>

using namespace std; //Namespace

char pizzaSize; //User's pizza size
int numToppings; //User's number of toppings

const float smallPrice = 4.99; //Base prices
const float medPrice = 5.99;
const float largePrice = 6.99;

const float smallToppingPrice = 0.75; //Topping prices
const float medToppingPrice = 1.50;
const float largeToppingPrice = 2.25;

void orderSmallPizza(); //Function declarations (called within the switch statement)
void orderMedPizza();
void orderLargePizza();

int main(){

    cout << "What size pizza would you like to order?\n"; //User input for pizza size
    cin >> pizzaSize;

    //Switch statement which determines price output from user input
    switch(pizzaSize){
        case 'S':
            orderSmallPizza();
            break;
        case 'M':
            orderMedPizza();
            break;
        case 'L':
            orderLargePizza();
            break;
        default:
            cout << "Please enter a valid input.\n";
            break;
    }
    return 0;
}

//Function definitions for each case of pizza order
void orderSmallPizza(){
    cout << "How many toppings do you want?\n"; //User input for number of toppings
    cin >> numToppings;

    if(numToppings < 0){
        cout << "Please enter a valid input.\n"; //Checks invalid input for numToppings
        return;
    }

    cout << fixed << setprecision(2) << "Your total is $" << (numToppings * smallToppingPrice) + smallPrice << "\n";
}

void orderMedPizza(){
    cout << "How many toppings do you want?\n"; //User input for number of toppings
    cin >> numToppings;

    if(numToppings < 0){
        cout << "Please enter a valid input.\n"; //Checks invalid input for numToppings
        return;
    }

    cout << fixed << setprecision(2) << "Your total is $" << (numToppings * medToppingPrice) + medPrice << "\n";
}

void orderLargePizza(){
    cout << "How many toppings do you want?\n"; //User input for number of toppings
    cin >> numToppings;

    if(numToppings < 0){
        cout << "Please enter a valid input.\n"; //Checks invalid input for numToppings
        return;
    }

    cout << fixed << setprecision(2) << "Your total is $" << (numToppings * largeToppingPrice) + largePrice << "\n";
}
