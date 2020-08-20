#include <iostream>
using namespace std;

int main()
{
	const int INCHES_per_FEET = 12;
	int Inches;

	cout << "Enter the number of inches:\t ";
	cin >> Inches;

	int Feet = Inches / INCHES_per_FEET;
	Inches = Inches % INCHES_per_FEET;

	cout << "Feet:\t\t\t\t " << Feet << endl;
	cout << "Inches:\t\t\t\t " << Inches << endl;

	return 0;
}