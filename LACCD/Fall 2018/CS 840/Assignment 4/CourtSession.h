//James Mathias
//CS 840
//Assignment 4
//5 of 6
//Nov 11, 2018

#include <iostream>
#include <string>
using namespace std;

#include "Date.h"
#include "Time.h"
#include "Appointment.h"

class CourtSession : public Appointment
{
private:
	string client_id;
	string fname;
	string lname;
	double hourly_charge;
	string courtName;
	string location;
public:
	CourtSession();
	~CourtSession();
	void get();
	void read();
	void printsession();
	string get_id();
	string get_fname();
	string get_lname();
	double get_hourly_charge();
	string get_courtName();
	string get_location();
	double calc_charge();
};

CourtSession::CourtSession()
{

}

CourtSession::~CourtSession()
{

}

void CourtSession::get()
{
	getapp();

	cout << "Enter client's ID: ";
	cin >> client_id;

	cout << "Enter client's first name: ";
	cin >> fname;

	cout << "Enter client's last name: ";
	cin >> lname;

	cout << "Enter hourly Charge: ";
	cin >> hourly_charge;

	cout << "Enter Court Name: ";
	cin >> courtName;

	cout << "Enter location: ";
	cin >> location;
}

void CourtSession::read()
{

}

void CourtSession::printsession()
{
	print();

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
	cout << "Session length: ";
	Time length = app_length();
	cout << length.get_hour() << ":" << length.get_minute();

	cout << endl;
	cout << "Hourly Charge: ";
	cout << hourly_charge;

	cout << endl;
	cout << "Total Charge: ";
	double charge = calc_charge();
	cout << charge;

	cout << endl;
	cout << "Court name: ";
	cout << courtName;

	cout << endl;
	cout << "Location: ";
	cout << location;
}

string CourtSession::get_id()
{
	return client_id;
}

string CourtSession::get_fname()
{
	return fname;
}

string CourtSession::get_lname()
{
	return lname;
}

double CourtSession::get_hourly_charge()
{
	return hourly_charge;
}

string CourtSession::get_courtName()
{
	return courtName;
}

string CourtSession::get_location()
{
	return location;
}

double CourtSession::calc_charge()
{
	Time length = app_length();
	double chargeh = hourly_charge * length.get_hour();
	double chargem = hourly_charge * length.get_minute() / 60;
	return (chargeh + chargem);
}