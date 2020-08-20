//James Mathias
//CS 840
//Midterm
//2 of 4
//Nov 9, 2018

#include <iostream>
using namespace std;

#include "Date.h"

class hDate : public Date
{
private:
	bool holiday;
public:
	hDate(int = 1, int = 1, int = 1900, bool = false);
	~hDate();
	void operator >>(hDate&);
	void operator <<(hDate&);
};

hDate::hDate(int d, int m, int y, bool h)
{
	set(d, m, y);
	holiday = h;
}

hDate::~hDate()
{

}

void hDate:: operator >> (hDate& hd)
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

	cout << "Is this day a holiday: ";
	cin >> holiday;
}

void hDate::operator << (hDate& hd)
{
	cout << day << "/" << month << "/" << year << endl;
	cout << "holiday:" << holiday;
}