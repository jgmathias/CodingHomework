//James Mathias
//CS 840
//Assignment 5
//3 of 3
//Dec 2, 2018

#include <iostream>
#include <string>
using namespace std;

#include "Date.h"
#include "List.h"

int main()
{
	List<int> numbers(10);
	for (int i = 0; i < 10; i++)
	{
		//numbers[i] = i + 1;
		cout << numbers[i] << ' ';
	}

	cout << endl;

	List<Date> dates(3);
	for (int i = 0; i < 3; i++)
	{
		dates[i].set(i + 1, 12, 2016);
		cout << dates[i] << endl;
	}

	cout << endl;
	system("PAUSE");
}