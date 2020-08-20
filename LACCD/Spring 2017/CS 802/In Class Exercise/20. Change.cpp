#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//Defining variables
	double Money;
	int Dollar = 100;
	int Quarter = 25;
	int Dime = 10;
	int Nickle = 5;
	int Penny = 1;

	//User inputs amount
	cout << "Enter an amount in double, for example 11.56: ";
	cin >> Money;

	//Calculation (since this program works with cents, we scale the amount by 100)
	int Cents = Money * 100;
	int C = Cents / Dollar;
	Cents = Cents % Dollar;
	int Q = Cents / Quarter;
	Cents = Cents % Quarter;
	int X = Cents / Dime;
	Cents = Cents % Dime;
	int V = Cents / Nickle;
	Cents = Cents % Nickle;
	int I = Cents / Penny;
	Cents = Cents % Penny;

	//Output
	cout << "Your amount " << Money << " consists of" << endl;
	cout << setw(8) << C << " dollars" << endl;
	cout << setw(8) << Q << " quarters" << endl;
	cout << setw(8) << X << " dimes" << endl;
	cout << setw(8) << V << " nickles" << endl;
	cout << setw(8) << I << " pennies" << endl;

	return 0;
}