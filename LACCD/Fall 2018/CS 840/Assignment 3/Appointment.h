//James Mathias
//CS 840
//Assignment 3
//3 of 5
//Nov 4, 2018

#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

#include "Date.h"
#include "Time.h"

class Appointment
{
private:
	Date date;
	Time start_time;
	Time end_time;
	string description;
	string location;
public:
	Appointment();
	void get();
	void print() const;
	Date get_date() const;
	Time get_start_time() const;
	Time get_end_time() const;
	Time app_length();
};

Appointment::Appointment() : date(), start_time(), end_time()
{
	description = "";
	location = "";
}

void Appointment::get()
{
	char c;

	date.get();

	do
	{
		cout << "Start time - ";
		start_time.get();

		cin.ignore(20, '\n');

		cout << "End time - ";
		end_time.get();

		cin.ignore(20, '\n');

		if (start_time > end_time)
		{
			cout << endl;
			cout << "End time cannot be earlier than start time" << endl;
		}

	} while (start_time > end_time);

	cout << "Enter description: ";
	cin >> description;

	cout << "Enter location: ";
	cin >> location;
}

void Appointment::print() const
{
	cout << endl;
	cout << "Appointment Date: ";
	date.print();

	cout << endl;
	cout << "Start time: ";
	start_time.print();

	cout << endl;
	cout << "End time: ";
	end_time.print();

	cout << endl;
	cout << "Description: " << description << endl;
	cout << "Location: " << location << endl;
}

Date Appointment::get_date() const
{
	return date;
}

Time Appointment::get_start_time() const
{
	return start_time;
}

Time Appointment::get_end_time() const
{
	return end_time;
}

Time Appointment::app_length()
{
	return (end_time - start_time);
}
