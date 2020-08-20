//James Mathias
//Mar 18, 2019
//CS 940
//Chapter 10-11 Assignment: Day of Year (2 of 2) - Class 
//create a class that takes an integer and outputs a day on the calendar

#include <iostream>
#include <string>
using namespace std;

#include "DayOfYearClass.h"

int main()
{
	cout << "Input: -5" << endl;
	DayOfYear(-5);

	cout << "\nInput: 0" << endl;
	DayOfYear(0);

	cout << "\nInput: 1" << endl;
	DayOfYear(1);

	cout << "\nInput: 185" << endl;
	DayOfYear(185);

	cout << "\nInput: 365" << endl;
	DayOfYear(365);

	cout << "\nInput: 366" << endl;
	DayOfYear(366);

	cout << "\nInput: 370" << endl;
	DayOfYear(370);

	cout << "\n";
	system("PAUSE");
	return 0;
}