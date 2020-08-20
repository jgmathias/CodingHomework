//This program adds up the total value of the change presented.

#include <iostream>
using namespace std;

int main()
{
	//Assign values for each coin.
	const int QValue = 25;
	const int DValue = 10;
	const int NValue = 5;
	int Quarters;
	int Dimes;
	int Nickles;

	//Ask user how many of each coin.
	cout << "How many quarters?\t ";
	cin >> Quarters;
	cout << "How many dimes?\t\t ";
	cin >> Dimes;
	cout << "How many nickles?\t ";
	cin >> Nickles;

	//Calculate total amount.
	int Total = Quarters * QValue + Dimes * DValue + Nickles * NValue;

	//Output answer.
	cout << "The monetary value of your coins is " << Total << " cents." << endl;

	return 0;
}