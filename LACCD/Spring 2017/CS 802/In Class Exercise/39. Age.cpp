#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

	int num;
	int rem;
	char b;
	string x;
	int age;
	char again;

	do {
		cout << endl << "Please enter the year that you were born: ";
		cin >> num;
		cout << "Have you had your birthday this year? (Y/N) ";
		cin >> b;

		if (toupper(b) == 'Y')
			{x = "have";
			age = 2017 - num;}
		else 
			{x = "have not";
			age = 2017 - num - 1;}

		cout << endl << "If you were born in " << num << " years old and " << x << " had your birthday yet, you must be " << age << " years old.";

		cout << endl << endl << "Do another year calculation? (Y/N) ";
		cin >> again;
	} while (toupper(again) == 'Y');

	cout << endl << "Goodbye for now." << endl;

	return 0;
}