//convertCurrency.cpp

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyler Ruvane
// Homework 2 - 5

#include <iostream> //import

using namespace std; //using the std namespace

int totalBolts; //total number of bolts (input by user)

int numBolts; //remainder bolts after conversions
int numCoins; //number of gold coins
int numGems; //number of gems

int main(){ //main method

    cout << "Enter the number of Bolts: " << endl;
    cin >> totalBolts;

    numBolts = totalBolts % 23; //number of residual bolts

    numCoins = totalBolts / 23; //number of residual gold coins
    numCoins %= 13;

    numGems = totalBolts / 299; //number of gems

    //Prints out how many gems, gold coins, and bolts the user has
    cout << numGems << " Gem(s) " << numCoins << " GoldCoin(s) " << numBolts << " Bolt(s)" << endl;

    return 0; //returns 0 if main executes successfully
}