//James Mathias
//Feb 12, 2019
//CS 940
//Chapter 1-3 Assignment: Program1
//input pay rate and hours worked, output income and amount spent on items

#include <iostream>
#include <string>
using namespace std;

int main()
{
	double Rate;
	cout << "Enter pay rate: ";
	cin >> Rate;

	double Hours;
	cout << "Enter number of hours worked per week: ";
	cin >> Hours;

	double Gross = Rate * Hours * 5;
	double Net = Gross * .86;
	double Clothes = Net * .1;
	double Supplies = Net * .01;
	double Bonds = (Net - Clothes - Supplies) * .25;
	double MoreBonds = Bonds * .5;
	cout << endl;

	printf("Gross Income: $%.2f \n", Gross);
	printf("Net Income:   $%.2f \n", Net);
	printf("Clothes:      $%.2f \n", Clothes);
	printf("Supplies:     $%.2f \n", Supplies);
	printf("Bonds:        $%.2f \n", Bonds);
	printf("More Bonds:   $%.2f \n", MoreBonds);
	cout << endl;

	system("PAUSE");
	return 0;
}