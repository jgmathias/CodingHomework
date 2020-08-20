#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

	int start;
	int inc;
	int count;
	int steps = 15;
	char again;

	do {
		cout << endl << "Please enter a number: ";
		cin >> start;
		cout << endl << "Please enter the increment value (step): ";
		cin >> inc;
		cout << endl << "Increment results" << endl;
		cout << start;
		count = 1;
		while (count < steps)
			{cout << ", " << start + count*inc;
			count++;}

		cout << endl << endl << "Go again? (Y/N) ";
		cin >> again;
	} while (toupper(again) == 'Y');

	cout << endl << "Goodbye for now" << endl;

	return 0;
}