s//CS 836
//Assignment 1
//3 of 3

#include <iostream>
using namespace std;

#include "date.h"

int main()
{
	date Date;

	int Month, Day, Year;

	cout << "Enter month, day and year separated by spaces: ";
	cin >> Month >> Day >> Year;

	Date.setDate(Month, Day, Year);
	Date.printDate();

	cin.ignore();
	return 0;
}