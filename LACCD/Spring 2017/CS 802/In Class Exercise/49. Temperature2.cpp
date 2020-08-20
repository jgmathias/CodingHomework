#include <iostream>
#include <iomanip>
using namespace std;

void header()
{
	cout << "Temperature Conversion Table" << endl;
	cout << "    Fahrenheit   Celsius" << endl;
	cout << "    ____________________" << endl;
}

double Celcius(int F)
{
	double C = (F-32.)*5./9.;
	return C;
}

int main()
{
	header();
	for (int F = 0; F <= 20; F++)
	{
		double C = Celcius(F);
		cout << fixed << setw(9) << F << "    " << setw(10) << C << endl;
	}

	return 0;
}