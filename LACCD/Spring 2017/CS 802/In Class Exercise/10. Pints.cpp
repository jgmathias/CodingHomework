#include <iostream>
using namespace std;

int main()
{

	const int PINTS_Per_GALLON = 8;
	const int PINTS_Per_QUART = 2;
	int Pints;

	cout << "How many pints?\t ";
	cin >> Pints;

	int Gallons = Pints / PINTS_Per_GALLON;
	Pints = Pints - (Gallons * PINTS_Per_GALLON);
	int Quarts = Pints / PINTS_Per_QUART;
	Pints = Pints - (Quarts * PINTS_Per_QUART);

	cout << "Gallons:\t " << Gallons << endl;
	cout << "Quarts:\t\t " << Quarts << endl;
	cout << "Pints:\t\t " << Pints << endl;

	return 0;
}