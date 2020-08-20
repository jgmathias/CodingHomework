//James Mathias
//CS 840
//Midterm
//1 of 4
//Nov 9, 2018

#include <iostream>
using namespace std;

class Date
{
private:

public:
	int day;
	int month;
	int year;
	Date(int = 1, int = 1, int = 1900);
	~Date();
	void set(int = 1, int = 1, int = 1900);
	void operator <<(Date&);
	void operator >>(Date&);
	bool operator <(Date&);
	bool operator >(Date&);
	bool operator ==(Date&);
};

Date::Date(int d, int m, int y)
{
	set(d, m, y);
}

Date::~Date()
{

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
	if (d >= 1 && d <= Values[month - 1])
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

void Date:: operator >> (Date& d)
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

bool Date::operator<(Date& d)
{
	if (year < d.year)
	{
		return true;
	}
	else if (year > d.year)
	{
		return false;
	}
	else
	{
		if (month < d.month)
		{
			return true;
		}
		else if (month > d.month)
		{
			return false;
		}
		else
		{
			if (day < d.day)
			{
				return true;
			}
			else if (day > d.day)
			{
				return false;
			}
			else
			{
				return false;
			}
		}
	}
}

bool Date::operator>(Date& d)
{
	if (year > d.year)
	{
		return true;
	}
	else if (year < d.year)
	{
		return false;
	}
	else
	{
		if (month > d.month)
		{
			return true;
		}
		else if (month < d.month)
		{
			return false;
		}
		else
		{
			if (day > d.day)
			{
				return true;
			}
			else if (day < d.day)
			{
				return false;
			}
			else
			{
				return false;
			}
		}
	}
}

void Date::operator << (Date& d)
{
	cout << day << "/" << month << "/" << year;
}

bool Date::operator==(Date& d)
{
	return (day == d.day && month == d.month && year == d.year);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//James Mathias
//CS 840
//Midterm
//2 of 4
//Nov 9, 2018

#include <iostream>
using namespace std;

//#include "Date.h"

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

////////////////////////////////////////////////////////////////////////////////////////////////////

//James Mathias
//CS 840
//Midterm
//3 of 4
//Nov 9, 2018

#include <iostream>
using namespace std;

//#include "hDate.h"

class hDateArray
{
private:
	int size;
	hDate* DateArray[100];
	hDate* ptr;
public:
	hDateArray(int = 1);
	~hDateArray();
	void input();
	void output();
};

hDateArray::hDateArray(int s)
{
	for (int i = 0; i < s; i++)
	{
		hDate* hd = new hDate;
		DateArray[i] = hd;
	}
}

hDateArray::~hDateArray()
{

}

void hDateArray::input()
{
	for (int i = 0; i < size; i++)
	{
		DateArray[i] >> DateArray[i];
	}
}

void hDateArray::output()
{
	for (int i = 0; i < size; i++)
	{
		DateArray[i] << DateArray[i];
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//James Mathias
//CS 840
//Midterm
//4 of 4
//Nov 9, 2018

#include <iostream>
using namespace std;

//#include "hDateArray.h"

int main()
{
	int size;
	cout << "Enter a size for the array of dates: ";
	cin >> size;

	hDateArray dates(size);

	dates.input();
	cout << endl;

	cout << "You entered: " << endl;
	dates.output();
	cout << endl;

	cout << "Press any key to continue.";
	system("PAUSE");

	return 0;
}