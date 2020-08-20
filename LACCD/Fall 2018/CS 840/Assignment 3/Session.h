//James Mathias
//CS 840
//Assignment 3
//4 of 5
//Nov 4, 2018

#include <iostream>
#include <typeinfo>
using namespace std;

#include "Date.h"
#include "Time.h"
#include "Appointment.h"

class Session
{
private:
	Appointment app;
	string client_id;
	string fname;
	string lname;
	double hourly_charge;
public:
	Session();
	~Session();
	void get();
	void read();
	void print();
	string get_id();
	string get_fname();
	string get_lname();
	double calc_charge();
	Appointment get_app();
};

Session::Session()
{
	
}

Session::~Session()
{

}

void Session::get()
{
	app.get();
	
	cout << "Enter client's ID: ";
	cin >> client_id;

	cout << "Enter client's first name: ";
	cin >> fname;

	cout << "Enter client's last name: ";
	cin >> lname;

	cout << "Enter hourly Charge: ";
	cin >> hourly_charge;
}

void Session::read()
{

}

void Session::print()
{
	app.print();

	cout << endl;
	cout << "Client ID: ";
	cout << client_id;

	cout << endl;
	cout << "First name: ";
	cout << fname;

	cout << endl;
	cout << "Last name: ";
	cout << lname;

	cout << endl;
	cout << "Hourly Charge: ";
	cout << hourly_charge;
}

string Session::get_id()
 {
	 return client_id;
 }

string Session::get_fname()
{
	return fname;
}

string Session::get_lname()
{
	return lname;
}

double Session::calc_charge()
{
	Time length = app.app_length();
	double chargeh = hourly_charge * length.get_hour();
	double chargem = hourly_charge * length.get_minute() / 60;
	return (chargeh + chargem);
}

Appointment Session::get_app()
{
	return app;
}

