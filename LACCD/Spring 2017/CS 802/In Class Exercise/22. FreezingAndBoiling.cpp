#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

	int Integer;

	cout << "This program indicates which substances freeze" << endl
		<< "and which boil at a specified temperature." << endl
		<< endl
		<< "Enter a Fahrenheit temperature: ";
	cin >> Integer;
	cout << endl;

	if (Integer <= -173) { cout << "Alcohol will freeze at " << Integer << " temperature." << endl; }
	if (Integer >= 172) { cout << "Alcohol will boil at " << Integer << " temperature." << endl; }
	if (Integer <= -38) { cout << "Mercury will freeze at " << Integer << " temperature." << endl; }
	if (Integer >= 676) { cout << "Mercury will boil at " << Integer << " temperature." << endl; }
	if (Integer <= -362) { cout << "Oxygen will freeze at " << Integer << " temperature." << endl; }
	if (Integer >= -306) { cout << "Oxygen will boil at " << Integer << " temperature." << endl; }
	if (Integer <= 32) { cout << "Water will freeze at " << Integer << " temperature." << endl; }
	if (Integer >= 212) { cout << "Water will boil at " << Integer << " temperature." << endl; }

	return 0;
}