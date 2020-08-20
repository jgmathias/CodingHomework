//CS 836
//Assignment 4
//3 of 3

#include <iostream>
#include <string>
using namespace std;

#include "personlist.h"

int displayMenu(void);
void processChoice(int, PersonList&);

int main()
{
	int num;
	PersonList myList;
	do
	{
		num = displayMenu();
		if (num != 3)
			processChoice(num, myList);
	} while (num != 3);
	return 0;
}

int displayMenu(void)
{
	int choice;
	cout << endl;
	cout << "Menu" << endl;
	cout << "==============================" << endl << endl;
	cout << "1. Add student to waiting list" << endl;
	cout << "2. View waiting list" << endl;
	cout << "3. Exit program" << endl << endl;
	cout << "Please enter choice: ";
	cin >> choice;
	cin.ignore();
	return choice;
}

void processChoice(int choice, PersonList& personlist)
{
	switch (choice)
	{
	case 1: personlist.AddToList();
		break;
	case 2: personlist.ViewList();
		break;
	}
}