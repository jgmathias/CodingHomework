//James Mathias
//Mar 18, 2019
//CS 940
//Chapter 10-11 Assignment: Day of Year 2 (1 of 3) - Class 
//create a class that takes a string and an integer and outputs a day on the calendar, and the two days around it

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Date
{
public:
	int Month;
	int Day;
	Date();
	Date(int month, int day);
	Date operator++();
	Date operator++(int);
	Date operator--();
	Date operator--(int);
	const int MonthSizes[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
};

 Date::Date()
{
	 Month = 1;
	 Day = 1;
}

Date::Date(int month, int day)
{
	Month = month;
	Day = day;
}

Date Date::operator++()
{
	++Day;
	if (Day > MonthSizes[Month])
	{
		++Month;
		if (Month == 13)
		{
			Month = 1;
		}
		Day = 1;
	}
	return Date(Month, Day);
}

Date Date::operator++(int)
{
	Date Input(Month, Day);
	++Day;
	if (Day > MonthSizes[Month])
	{
		++Month;
		if (Month == 13)
		{
			Month = 1;
		}
		Day = 1;
	}
	return Input;
}

Date Date::operator--()
{
	--Day;
	if (Day == 0)
	{
		--Month;
		if (Month == 0)
		{
			Month = 12;
		}
		Day = MonthSizes[Month];
	}
	return Date(Month, Day);
}

Date Date::operator--(int)
{
	Date Input(Month, Day);
	--Day;
	if (Day == 0)
	{
		--Month;
		if (Month == 0)
		{
			Month = 12;
		}
		Day = MonthSizes[Month];
	}
	return Input;
}