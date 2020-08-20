#include <iostream>
using namespace std;

int main()
{

	int Pints;
	
	cout << "How many pints?\t ";
	cin >> Pints;

	int Gallons = Pints / 8;
	Pints = Pints - (Gallons*8);
	int Quarts = Pints / 2;
	Pints = Pints - (Quarts * 2);

	cout << "Gallons:\t " << Gallons << endl;
	cout << "Quarts:\t\t " << Quarts << endl;
	cout << "Pints:\t\t " << Pints << endl;

	return 0;
}
