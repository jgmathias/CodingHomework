#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	
	string X;
	double Num1;
	double Num2;

	cout << "Enter an operator (+, -, * or /): ";
	cin >> X;
	cout << "Enter two numbers separated by a space: ";
	cin >> Num1 >> Num2;
	cout << fixed << setprecision(2);

	if (X == "+")
		{cout << Num1 << " + " << Num2 << " = " << Num1 + Num2 << endl;}
	else if (X == "-")
		{cout << Num1 << " - " << Num2 << " = " << Num1 - Num2 << endl;}
	else if (X == "*")
		{cout << Num1 << " * " << Num2 << " = " << Num1 * Num2 << endl;}
	else if (X == "/")
		{cout << Num1 << " / " << Num2 << " = " << Num1 / Num2 << endl;}
	else
		{cout << "Error!" << endl;}
	
	return 0;
}