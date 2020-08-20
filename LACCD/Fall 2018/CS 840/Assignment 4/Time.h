//James Mathias
//CS 840
//Assignment 4
//2 of 6
//Nov 11, 2018

#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int minute;
public:
	Time(int = 0, int = 0);
	void set(int = 0, int = 0);
	void get();
	void print() const;
	int get_hour() const;
	int get_minute() const;
	Time operator-(const Time &) const;
	bool operator==(const Time &) const;
	bool operator<(const Time &) const;
	bool operator>(const Time &) const;
};

Time::Time(int h, int m)
{
	set(h, m);
}

void Time::set(int h, int m)
{
	if (h >= 0 && h <= 24)
	{
		hour = h;
	}
	else
	{
		cout << endl;
		cout << "Invalid hour" << endl;
		cout << "Press any key to continue." << endl;;
		system("pause");
		exit(1);
	}

	if (m >= 0 && m <= 60)
	{
		minute = m;
	}
	else
	{
		cout << endl;
		cout << "Invalid minute" << endl;;
		cout << "Press any key to continue." << endl;;
		system("pause");
		exit(1);
	}
}

void Time::get()
{
	char ch = ':';

	cout << "Enter time in military [hour:minute] format: ";
	cin >> hour >> ch >> minute;

	while (hour < 0 || hour > 24 || minute < 0 || minute > 60)
	{
		cout << endl;
		cout << "Invalid time entered" << endl;
		cout << "Enter time in military [hour:minute] format: ";
		cin >> hour >> ch >> minute;
	}
}

void Time::print() const
{
	cout << hour << ":" << minute;
}

int Time::get_hour() const
{
	return hour;
}

int Time::get_minute() const
{
	return minute;
}

Time Time::operator-(const Time &t) const
{
	if (minute >= t.minute)
	{
		return Time(hour - t.hour, minute - t.minute);
	}
	else
	{
		return Time(hour - t.hour - 1, minute + 60 - t.minute);
	}
}

bool Time::operator==(const Time &t) const
{
	return hour == t.hour && minute == t.minute;
}

bool Time::operator<(const Time &t) const
{
	if (hour < t.hour)
	{
		return true;
	}
	else if ((hour == t.hour) && (minute < t.minute))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Time::operator>(const Time &t) const
{
	return (!(*this == t) && !(*this < t));
}