#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

	int num;
	int rem;
	char again;

	do {
		cout << endl << "Enter an integer number: ";
		cin >> num;
		cout << endl << "Reversed number: ";
		
		if (num < 0)
			{num = num*(-1);
			cout << "-";}
		
		do 
			{rem = num % 10;
			cout << rem;
			num = num / 10;}
		while (num != 0);
		
		cout << endl << endl << "Go again? (Y/N) ";
		cin >> again;
	} while (toupper(again) == 'Y');

	cout << endl << "Goodbye for now" << endl;

	return 0;
}