//James Mathias
//CS 840
//Assignment 4
//4 of 6
//Nov 11, 2018

#include <iostream>
#include <string>
using namespace std;

#include "Date.h"
#include "Time.h"
#include "Appointment.h"

class ClientSession : public Appointment
{
private:
	string client_id;
	string fname;
	string lname;
	double hourly_charge;
public:
	ClientSession();
	~ClientSession();
	void get();
	void read();
	void printsession();
	string get_id();
	string get_fname();
	string get_lname();
	double get_hourly_charge();
	double calc_charge();
};

ClientSession::ClientSession()
{

}

ClientSession::~ClientSession()
{

}

void ClientSession::get()
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
}

void ClientSession::read()
{

}

void ClientSession::printsession()
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
}

string ClientSession::get_id()
{
	return client_id;
}

string ClientSession::get_fname()
{
	return fname;
}

string ClientSession::get_lname()
{
	return lname;
}

double ClientSession::get_hourly_charge()
{
	return hourly_charge;
}

double ClientSession::calc_charge()
{
	Time length = app_length();
	double chargeh = hourly_charge * length.get_hour();
	double chargem = hourly_charge * length.get_minute() / 60;
	return (chargeh + chargem);
}