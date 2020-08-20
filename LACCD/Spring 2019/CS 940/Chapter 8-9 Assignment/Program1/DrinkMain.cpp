//James Mathias
//Mar 10, 2019
//CS 940
//Chapter 8-9 Assignment: Drink(2 of 2) - Main
//create a class that simulates a drink machine

#include <iostream>
#include <string>
using namespace std;

#include "DrinkClass.h"

int main()
{
	cout << "-----Create Drink Machine-----" << endl;
	DrinkMachine Monday;

	cout << "\n-----Display Choices-----" << endl;
	Monday.DisplayChoices();

	cout << "\n-----Buy Drinks-----" << endl;
	Monday.BuyDrink();
	
	cout << "\n-----End of Day Report-----" << endl;
	Monday.~DrinkMachine();

	cout << "\n";
	system("PAUSE");
	return 0;
}