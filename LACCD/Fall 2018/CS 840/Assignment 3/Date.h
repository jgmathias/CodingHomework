//James Mathias
//CS 840
//Assignment 3
//1 of 5
//Nov 4, 2018

#include <iostream>
#include <typeinfo>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int = 1, int = 1, int = 1900);
	void set(int = 1, int = 1, int = 1900);
	void get();
	void print() const;
	bool operator==(const Date &) const;
};

Date::Date(int d, int m, int y)
{
	set(d, m, y);
}

void Date::set(int d, int m, int y)
{
	
	if (m >= 1 && m <= 12)
	{
		month = m;
	}
	else
	{
		cout << endl;
		cout << "Invalid month" << endl;
		cout << "Press any key to continue." << endl;
		system("pause");
		exit(1);
	}

	int Values[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (d >= 1 && d <= Values[month-1])
	{
		day = d;
	}
	else
	{
		cout << endl;
		cout << "Invalid day" << endl;
		cout << "Press any key to continue." << endl;
		system("pause");
		exit(1);
	}

	if (y >= 1900 && y <= 3000)
	{
		year = y;
	}
	else
	{
		cout << endl;
		cout << "Invalid year" << endl;
		cout << "Press any key to continue." << endl;
		system("pause");
		exit(1);
	}

	if (month == 2 && day == 29)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		{

		}
		else
		{
			cout << endl;
			cout << "Invalid leap day" << endl;
			cout << "Press any key to continue." << endl;
			system("pause");
			exit(1);
		}
	}
}

void Date::get()
{
	char ch = '/';

	cout << "Enter date in mm/dd/yyyy format: ";
	cin >> month >> ch >> day >> ch >> year;

	int Values[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	while (month < 1 || month > 12 || day < 1 || day > Values[month - 1] || year < 1900 || year > 3000)
	{
		if (month == 2 && day == 29)
		{
			if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			{
				break;
			}
		}

		cout << endl;
		cout << "Invalid date" << endl;
		cout << "Enter date in mm/dd/yyyy format: ";
		cin >> day >> ch >> month >> ch >> year;
	}
}

void Date::print() const
{
	cout << day << "/" << month << "/" << year;
}

bool Date::operator==(const Date &d) const
{
	return (day == d.day && month == d.month && year == d.year);
}