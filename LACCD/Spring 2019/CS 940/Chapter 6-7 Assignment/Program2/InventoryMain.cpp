//James Mathias
//Mar 2, 2019
//CS 940
//Chapter 6-7 Assignment: Inventory(2 of 2) - Main
//create a class that can hold information for an item in a retail store’s inventory

#include <iostream>
#include <string>
using namespace std;

#include "InventoryClass.h"

int main()
{
	cout << "Create Default Class" << endl;
	Inventory Default;

	cout << "\nDisplay Default Class\n"
		 << "Item Number:  " << Default.getItemNumber() << "\n"
		 << "Quantity:     " << Default.getQuantity() << "\n";
		printf("Cost:        $%.2f \n", Default.getCost());
		printf("Total Cost:  $%.2f \n", Default.getTotalCost());
		cout << endl;

	cout << "Create Test Class with variables (1, 2, 3)" << endl;
	Inventory Test123(1, 2, 3);

	cout << "\nDisplay Test Class\n"
		 << "Item Number:  " << Test123.getItemNumber() << "\n"
		 << "Quantity:     " << Test123.getQuantity() << "\n";
		printf("Cost:        $%.2f \n", Test123.getCost());
		printf("Total Cost:  $%.2f \n", Test123.getTotalCost());
		cout << endl;

	cout << "Create Negative Class with variables (-1, -2, -3)" << endl;
	Inventory Negative(-1, -2, -3);

	cout << "\nDisplay Negative Class\n"
		 << "Item Number:  " << Negative.getItemNumber() << "\n"
		 << "Quantity:     " << Negative.getQuantity() << "\n";
		printf("Cost:        $%.2f \n", Negative.getCost());
		printf("Total Cost:  $%.2f \n", Negative.getTotalCost());
		cout << endl;

	system("PAUSE");
	return 0;
}