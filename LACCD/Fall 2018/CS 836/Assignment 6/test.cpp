//CS 836
//Assignment 6
//3 of 3

#include <iostream>
#include <string>
using namespace std;

#include "sort.h"

int main()
{
	PersonList myList;

	for (int i = 0; i < 10; i++)
	{
		char choice;
		cout << endl;
		cout << "Do you want to enter student (Y / N) ? ";
		cin >> choice;
		
		if (choice == 'Y' || choice == 'y')
		{
			myList.AddToList();
		}
		else
		{
			break;
		}
	}

	int sort;
	cout << endl;
	cout << "Menu" << endl;
	cout << "==============================" << endl;
	cout << endl;
	cout << "1. Bubble Sort" << endl;
	cout << "2. Quick Sort" << endl;
	cout << "Please enter choice: ";
	cin >> sort;

	if (myList.AtLeastTwo())
	{
		switch (sort)
		{
		case 1:
			myList.BubbleSort();
			break;
		case 2:
			myList.QuickSort();
			break;
		}
	}

	myList.ViewList();

	return 0;
}