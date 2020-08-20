#include <iostream>
#include <iomanip>
#include <locale>
using namespace std;

int main()
{
	int Cookies;

	cout << "Number of cookies you want to make: ";
	cin >> Cookies;

	double Scale = Cookies / 48.;
	double Sugar = 1.5;
	double Butter = 1;
	double Flour = 2.75;

	double Sugar2 = Scale * Sugar;
	double Butter2 = Scale * Butter;
	double Flour2 = Scale * Flour;

	cout << "To make " << Cookies << " cookies, you should use" << endl;
	cout << Sugar2 << " cups of sugar, " << Butter2 << " cups of butter, and " << Flour2 << " cups of flour." << endl;

	return 0;
}