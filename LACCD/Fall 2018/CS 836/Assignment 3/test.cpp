//CS 836
//Assignment 3
//3 of 3

#include <iostream>
#include <string>
using namespace std;

#include "cqueue.h"

int Menu(void);
void Add(CQueue*);
void Delete(CQueue*);
void Show(CQueue*);

int main(void)
{
	CQueue lists[2];
	int x;
	do
	{
		x = Menu();
		switch (x)
		{
		case 1: Add(lists);
			break;
		case 2: Delete(lists);
			break;
		case 3: Show(lists);
			break;
		case 4:
			break;
		default:
			cout << "Invalid entry" << endl;
		}
	} while (x != 4);
	return 0;
}

int Menu(void)
{
	int select;

	cout << "Menu" << endl;
	cout << "========" << endl;
	cout << "1. Add Passenger" << endl;
	cout << "2. Delete Passenger" << endl;
	cout << "3. Show Passengers" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter choice: ";
	cin >> select;
	return select;
}

void Add(CQueue* Lists)
{
	if (Lists[1].IsFull())
	{
		cout << "Sorry. Plane and waiting list fully booked. Try later" << endl;
	}
	else if (Lists[0].IsFull())
	{
		Passenger p;
		cout << "Enter name: ";
		cin >> p.name;
		Lists[1].Enqueue(p);
		cout << "Sorry. Plane fully booked. Adding " << p.name << " to waiting list" << endl;
	}
	else
	{
		Passenger p;
		cout << "Enter name: ";
		cin >> p.name;
		Lists[0].Enqueue(p);
		cout << "Booking " << p.name << " on flight" << endl;
	}
}

void Delete(CQueue* Lists)
{
	if (Lists[0].IsEmpty())
	{
		cout << "No passengers to delete" << endl;
	}
	else
	{
		Passenger p = Lists[0].getPass(-1);
		Lists[0].Dequeue();
		cout << "Removing " << p.name << " from booked passengers" << endl;
		if (Lists[1].IsEmpty())
		{

		}
		else
		{
			p = Lists[1].getPass(-1);
			Lists[0].Enqueue(p);
			Lists[1].Dequeue();
			cout << "Adding " << p.name << " from waiting list" << endl;
		}
	}
}

void Show(CQueue* Lists)
{
	if (Lists[0].IsEmpty())
	{
		cout << "No passengers" << endl;
	}
	else if (Lists[1].IsEmpty())
	{
		cout << "Booked Passengers" << endl;
		cout << "=================" << endl;
		Lists[0].ShowAll();
		cout << "No passengers on waiting list" << endl;
	}
	else
	{
		cout << "Booked Passengers" << endl;
		cout << "=================" << endl;
		Lists[0].ShowAll();
		cout << "Waiting list" << endl;
		cout << "=================" << endl;
		Lists[1].ShowAll();
	}
}