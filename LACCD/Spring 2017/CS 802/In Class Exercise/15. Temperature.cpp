#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int degreesC;

	cout << "Enter a Celsius temperature: ";
	cin >> degreesC;

	double degreesF = 9 / 5. * degreesC + 32;

	cout << degreesC << " degrees Celsius is equal to " << fixed << setprecision(1) << degreesF << " degrees Fahrenheit." << endl;

	return 0;
}