//James Mathias
//Feb 12, 2019
//CS 940
//Chapter 1-3 Assignment: Program2
//input number of tickets sold at a theater, output gross and net profit

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string Name;
	cout << "Enter name of movie: ";
	getline(cin, Name);

	int Adult;
	cout << "Enter number of adult tickets sold: ";
	cin >> Adult;

	int Child;
	cout << "Enter number of child tickets sold: ";
	cin >> Child;

	double Gross = Adult * 6 + Child * 3;
	double Fee = Gross * .8;
	double Net = Gross - Fee;
	cout << endl;

	cout << "Movie Name:   \"" << Name << "\"" << endl;
	cout << "Adult Tickets: " << Adult << endl;
	cout << "Child Tickets: " << Child << endl;
	printf("Gross Profit:  $%.2f \n", Gross);
	printf("Distributor:  -$%.2f \n", Fee);
	printf("Net Profit:    $%.2f \n", Net);
	cout << endl;

	system("PAUSE");
	return 0;
}