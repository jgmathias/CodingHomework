//James Mathias
//Mar 18, 2019
//CS 940
//Chapter 10-11 Assignment: Day of Year 2 (3 of 3) - Class 
//create a class that takes a string and an integer and outputs a day on the calendar, and the two days around it

#include <iostream>
#include <string>
using namespace std;

#include "DayOfYear2Class.h"

int main()
{
	cout << "Input: jan 5" << endl;
	DayOfYear2("jan", 5);

	cout << "\nInput: January -5" << endl;
	DayOfYear2("January", -5);

	cout << "\nInput: February 29" << endl;
	DayOfYear2("February", 29);

	cout << "\nInput: January 1" << endl;
	DayOfYear2("January", 1);

	cout << "\nInput: June 30" << endl;
	DayOfYear2("June", 30);

	cout << "\nInput: July 1" << endl;
	DayOfYear2("July", 1);

	cout << "\nInput: December 31" << endl;
	DayOfYear2("December", 31);

	cout << "\n";
	system("PAUSE");
	return 0;
}