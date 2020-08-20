//James Mathias
//Mar 18, 2019
//CS 940
//Chapter 10-11 Assignment: Day of Year (1 of 2) - Class 
//create a class that takes an integer and outputs a day on the calendar

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class DayOfYear
{

private:
	int Day;
	int Month;
	void Print();
	const string MonthNames[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	const int MonthSizes[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:
	DayOfYear(int = 1);
	~DayOfYear();
	
};

DayOfYear::DayOfYear(int Input)
{
	Day = Input;
	Month = 0;

	for (int i = 0; i <=12; i++)
	{
		if (Day > MonthSizes[i])
		{
			Month++;
			Day -= MonthSizes[i];
		}
		else
		{
			break;
		}
	}

	Print();
}

DayOfYear::~DayOfYear()
{
	
}

void DayOfYear::Print()
{
	if (Month == 0 || Month == 13)
	{
		cout << "Invalid Input." << endl;
	}
	else
	{
		cout << MonthNames[Month] << " " << Day << endl;
	}
}