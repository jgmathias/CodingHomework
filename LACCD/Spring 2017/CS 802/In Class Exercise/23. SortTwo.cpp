#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

	int Integer1, Integer2;

	cout << "Enter two integers: ";
	cin >> Integer1 >> Integer2;

	if (Integer1 > Integer2) { cout << "Your numbers are sorted in ascending order: " << Integer2 << "  " << Integer1 << endl; }
	else { cout << "Your numbers are already in order: " << Integer1 << "  " << Integer2 << endl; }

	return 0;
}