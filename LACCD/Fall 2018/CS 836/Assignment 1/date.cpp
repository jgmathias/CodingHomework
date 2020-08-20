//CS 836
//Assignment 1
//2 of 3

#include <iostream>
using namespace std;

#include "date.h"

date::date(int Month, int Day, int Year)
{

}

void date::setDate(int Month, int Day, int Year)
{
	month = 9;
	day = 1;
	year = 2018;
	
	if (Month < 1 || Month > 12 || Day < 1 || Year < 1900 || Year > 2018)
	{
		return;
	}

	if (Month == 2 && Day == 29)
	{
		if ( (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0))
		{
			month = 2;
			day = 29;
			year = Year;
			return;
		}
		else
		{
			return;
		}
	}
	
	int Values[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (Day > Values[Month - 1])
	{
		return;
	}
	
	month = Month;
	day = Day;
	year = Year;
}

void date::printDate()
{
	cout << month << "/" << day << "/" << year << endl;
}