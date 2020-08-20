//CS 836
//Assignment 5
//3 of 3

#include <iostream>
#include <string>
using namespace std;

#include "tree.h"

int displayMenu(void);
void processChoice(int, PersonTree&);

int main()
{
	int num;
	PersonTree myTree;

	do
	{
		num = displayMenu();

		if (num != 3)
		{
			processChoice(num, myTree);
		}
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

void processChoice(int choice, PersonTree& MyTree)
{
	switch (choice)
	{
	case 1:
		MyTree.AddToTree();
		break;
	case 2:
		MyTree.ViewTree();
		break;
	}
}