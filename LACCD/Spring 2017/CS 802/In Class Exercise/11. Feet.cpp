#include <iostream>
using namespace std;

int main()
{

	const double METER_per_FOOT = 0.3048;
	const int INCHES_per_FOOT = 12;
	int Feet;

	cout << "This program converts feet to meters and inches." << endl;
	cout << "Enter a value for feet:\t ";
	cin >> Feet;

	double Meters = Feet * METER_per_FOOT;
	int Inches = Feet * INCHES_per_FOOT;


	cout << "Meters = \t\t " << Meters << endl;
	cout << "Inches = \t\t " << Inches << endl;

	return 0;
}