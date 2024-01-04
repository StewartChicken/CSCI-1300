// potionCrafting.cpp
// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Homework 4 - Problem # 3

#include <iostream>

int priority; //User priority potion: 1 = Minor Mana, 2 = Minor Healing
int honeyComb, dandelions, coal, toadStools; //Ingredients

//Minor Healing: 5 0 2 3
//Minor Mana: 5 3 1 0

//Healing potion requirements
const int HEALING_HONEY_REC = 5; 
const int HEALING_COAL_REC = 2;
const int HEALING_TOAD_REC = 3;

//Mana potion requirements
const int MANA_HONEY_REC = 5;
const int MANA_DAND_REC = 3;
const int MANA_COAL_REC = 1;

//Final number of each potion
int numHealingPotions;
int numManaPotions;

//Function calculates how many mana potions can be made
int makeMana(int &honey, int &dand, int &coal); 

//Function calculates how many healing potions can be made
int makeHealing(int &honey, int &coal, int &toad);

int main()
{

    //User prompt for priority
    while(1)
    {
        std::cout << "Select a potion crafting priority:\n1. Minor Mana\n2. Minor Healing\n";
        std::cin >> priority;

        if(priority == 1 || priority == 2)
        {
            break;
        }else{
            std::cout << "Invalid input.\n";
        }
    }

    //User prompts for the amount of each ingredient they have

    //Honeycomb prompt
    while(1)
    {
        std::cout << "How many Honeycombs do you have?\n";
        std::cin >> honeyComb;

        if(honeyComb < 0)
        {
            std::cout << "Invalid input. ";
        }else{
            break;
        }
    }

    //Dandelion prompt
    while(1)
    {
        std::cout << "How many Dandelions do you have?\n";
        std::cin >> dandelions;

        if(dandelions < 0)
        {
            std::cout << "Invalid input. ";
        }else{
            break;
        }
    }

    //Coal prompt
    while(1)
    {
        std::cout << "How many Coal do you have?\n";
        std::cin >> coal;

        if(coal < 0)
        {
            std::cout << "Invalid input. ";
        }else{
            break;
        }
    }

    //Toadstool prompt
    while(1)
    {
        std::cout << "How many Toadstools do you have?\n";
        std::cin >> toadStools;

        if(toadStools < 0)
        {
            std::cout << "Invalid input. ";
        }else{
            break;
        }
    }

    //Output depending on priority
    if(priority == 1)
    {   
        //Function calls to calculate number of each potion
        numManaPotions = makeMana(honeyComb, dandelions, coal);
        numHealingPotions = makeHealing(honeyComb, coal, toadStools);
        
        //Output
        std::cout << "You can make " << numManaPotions << " Mana potion(s) and " << numHealingPotions << " Healing potion(s).\n";

    }else{

        //Function calls to calculate number of each potion
        numHealingPotions = makeHealing(honeyComb, coal, toadStools);
        numManaPotions = makeMana(honeyComb, dandelions, coal);

        //Output
        std::cout << "You can make " << numHealingPotions << " Healing potion(s) and " << numManaPotions << " Mana potion(s).\n";
    }

    return 0;
}

//Calculates how many mana potions can be made
int makeMana(int &honey, int &dand, int &coal)
{
    int numPotions; //Number of mana potions user can make

    //These variables allows this function to determine the limiting ingredient
    int honeyFactor = honey / MANA_HONEY_REC;
    int dandFactor = dand / MANA_DAND_REC;
    int coalFactor = coal / MANA_COAL_REC;
    
    //Find limiting ingredient
    numPotions = honeyFactor;

    if(dandFactor < numPotions)
    {
        numPotions = dandFactor;
    }

    if(coalFactor < numPotions)
    {
        numPotions = coalFactor;
    }

    //Reassigns new values of each ingredient
    honey = honey - MANA_HONEY_REC * numPotions;
    dand = dand - MANA_DAND_REC * numPotions;
    coal = coal - MANA_COAL_REC * numPotions;

    return numPotions; 
}

//Calculates how many healing potions can be made
int makeHealing(int &honey, int &coal, int &toad)
{
    int numPotions; //Number of mana potions user can make

    //These variables allows this function to determine the limiting ingredient
    int honeyFactor = honey / HEALING_HONEY_REC;
    int coalFactor = coal / HEALING_COAL_REC;
    int toadFactor = toad / HEALING_TOAD_REC;

    //Find limiting ingredient
    numPotions = honeyFactor;

    if(coalFactor < numPotions)
    {
        numPotions = coalFactor;
    }

    if(toadFactor < numPotions)
    {
        numPotions = toadFactor;
    }

    honey = honey - HEALING_HONEY_REC * numPotions;
    coal = coal - HEALING_COAL_REC * numPotions;
    toad = toad - HEALING_TOAD_REC * numPotions;
  
    return numPotions;
}