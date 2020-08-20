#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

	int Year;

	cout << "Enter a Year: ";
	cin >> Year;

	if (Year % 400 == 0) { cout << "In "<< Year << ", February has 29 days. This is a leap year." << endl; }
	else if (Year % 100 == 0) { cout << "In " << Year << ", February has 28 days. This is not a leap year." << endl; }
	else if (Year % 4 == 0) { cout << "In " << Year << ", February has 29 days. This is a leap year." << endl; }
	else { cout << "In " << Year << ", February has 28 days. This is not a leap year." << endl; }

	return 0;
}