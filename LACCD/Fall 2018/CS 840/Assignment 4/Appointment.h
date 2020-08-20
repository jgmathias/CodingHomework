//James Mathias
//CS 840
//Assignment 4
//3 of 6
//Nov 11, 2018

#include <iostream>
#include <string>
using namespace std;

#include "Date.h"
#include "Time.h"

class Appointment
{
protected:
	Date date;
	Time start_time;
	Time end_time;
	string description;
public:
	Appointment();
	void getapp();
	void print() const;
	Date get_date() const;
	Time get_start_time() const;
	Time get_end_time() const;
	Time app_length();
};

Appointment::Appointment() : date(), start_time(), end_time()
{
	description = "";
}

void Appointment::getapp()
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
