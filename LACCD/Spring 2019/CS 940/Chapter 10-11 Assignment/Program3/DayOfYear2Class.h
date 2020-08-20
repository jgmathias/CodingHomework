//James Mathias
//Mar 18, 2019
//CS 940
//Chapter 10-11 Assignment: Day of Year 2 (2 of 3) - Class 
//create a class that takes a string and an integer and outputs a day on the calendar, and the two days around it

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "DayOfYear2Struct.h"

class DayOfYear2
{

private:
	Date Input;
	void Print(Date);
	
	const string MonthNames[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	const int MonthSizes[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:
	DayOfYear2(string = "January", int = 1);
	~DayOfYear2();

};

DayOfYear2::DayOfYear2(string Input1, int Input2)
{
	Input.Day = Input2;
	Input.Month = 0;

	for (int i = 1; i <= 12; i++)
	{
		if (Input1 == MonthNames[i])
		{
			Input.Month = i;
			if (Input.Day <= 0 || Input.Day > MonthSizes[i])
			{
				Input.Day = 0;
			}
		}		
	}

	if (Input.Month == 0 || Input.Day == 0)
	{
		cout << "Invalid Input." << endl;
	}
	else
	{
		cout << " Input : "; Print(Input);
		cout << "--Input: "; Print(--Input);
		cout << "++Input: "; Print(++Input);
		cout << "Input++: "; Print(Input++);
		cout << "Input--: "; Print(Input--);
		cout << " Input : "; Print(Input);
	}
}

DayOfYear2::~DayOfYear2()
{

}

void DayOfYear2::Print(Date date)
{
	cout << MonthNames[date.Month] << " " << date.Day << endl;
}