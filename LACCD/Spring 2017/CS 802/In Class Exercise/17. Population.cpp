#include <iostream>
#include <iomanip>
#include <locale>
using namespace std;

int main()
{
	int Years;

	cout << "Enter the number of years: ";
	cin >> Years;

	int Pop = 324310011;
	int BirthSec = 7;
	int DeathSec = 13;
	int ImmSec = 45;

	int SecPerYear = 60 * 60 * 24 * 365;
	double BirthPerYear = SecPerYear / (float) BirthSec;
	double DeathPerYear = SecPerYear / (float) DeathSec;
	double ImmPerYear = SecPerYear / (float) ImmSec;
	Pop = Pop + Years * (BirthPerYear - DeathPerYear + ImmPerYear);

	cout << "The population in " << Years << " is ";
	cout.imbue(locale(""));
	cout << Pop << endl;

	return 0;
}