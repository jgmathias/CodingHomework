#include <iostream>
using namespace std;

int main()
{

	const int PINTS_per_GALLON = 8;
	const int PINTS_per_QUART = 2;
	int Pints;

	cout << "How many pints?\t ";
	cin >> Pints;

	int Gallons = Pints / PINTS_per_GALLON;
	Pints = Pints % PINTS_per_GALLON;
	int Quarts = Pints / PINTS_per_QUART;
	Pints = Pints % PINTS_per_QUART;

	cout << "Gallons:\t " << Gallons << endl;
	cout << "Quarts:\t\t " << Quarts << endl;
	cout << "Pints:\t\t " << Pints << endl;

	return 0;
} 