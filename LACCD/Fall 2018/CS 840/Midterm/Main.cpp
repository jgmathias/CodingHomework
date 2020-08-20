//James Mathias
//CS 840
//Midterm
//4 of 4
//Nov 9, 2018

#include <iostream>
using namespace std;

#include "hDateArray.h"

int main()
{
	int size;
	cout << "Enter a size for the array of dates: ";
	cin >> size;

	hDateArray dates(size);
	
	dates.input();
	cout << endl;

	cout << "You entered: " << endl;
	dates.output();
	cout << endl;

	cout << "Press any key to continue.";
	system("PAUSE");

	return 0;
}