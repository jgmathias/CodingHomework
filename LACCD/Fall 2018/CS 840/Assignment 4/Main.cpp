//James Mathias
//CS 840
//Assignment 4
//6 of 6
//Nov 11, 2018

#include <iostream>
#include <string>
using namespace std;

#include "Date.h"
#include "Time.h"
#include "Appointment.h"
#include "ClientSession.h"
#include "CourtSession.h"

bool conflict(Appointment *, Appointment *[], int, int&);

int main()
{
	Appointment *ap[100], *temp;
	int choice = 0, count = 0, index, i;

	do
	{
		cout << endl;
		cout << "Session Management program by James Mathias" << endl;
		cout << "Choose one of the following: " << endl;
		cout << "------------------------------" << endl;
		cout << "1. Create a new Client Session." << endl;
		cout << "2. Create a new Court Session." << endl;
		cout << "3. View all sessions and then Quit." << endl;
		cout << "----------------------------->";

		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
			temp = new ClientSession;
			temp->get();

			if (conflict(temp, ap, count, index))
			{
				cout << endl;
				cout << "This will conflict with: ";
				ap[index]->print();

				cout << endl << endl;
				cout << "Client Session not entered." << endl;
			}
			else
			{
				ap[count] = temp;
				count++;
			}

			break;

		case 2:
			temp = new CourtSession;
			temp->get();

			if (conflict(temp, ap, count, index))
			{
				cout << endl;
				cout << "This will conflict with: ";
				ap[index]->print();

				cout << endl << endl;
				cout << "Court Session not entered." << endl;
			}
			else
			{
				ap[count] = temp;
				count++;
			}

			break;

		case 3:
			for (i = 0; i < count; i++)
			{
				ap[i]->print();
				cout << endl;
			}

			system("PAUSE");

			break;

		default:
			cout << endl;
			cout << "Invalid entry - please, enter a number between 1 and 3." << endl;
		}
	} while (choice != 3);
}

bool conflict(Appointment *p, Appointment *ap[], int size, int& i)
{
	Date date = p->get_date();
	Time start = p->get_start_time();
	Time end = p->get_end_time();

	for (i = 0; i < size; i++)
	{
		if (date == ap[i]->get_date())
		{
			if (
				(start == ap[i]->get_start_time())
				|| ((start < ap[i]->get_start_time()) && (end > ap[i]->get_start_time()))
				|| ((start > ap[i]->get_start_time()) && (start < ap[i]->get_end_time()))
				)
			{
				return true;
			}
		}
	}

	return false;
}