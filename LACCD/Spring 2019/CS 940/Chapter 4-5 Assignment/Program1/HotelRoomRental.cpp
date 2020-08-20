//James Mathias
//Feb 20, 2019
//CS 940
//Chapter 4-5 Assignment: Program1
//input hotel room rental details, then output total bill

#include <iostream>
#include <string>
using namespace std;

int main()
{
	double Rate = 100;

	int Rooms;
	cout << "Enter number of rooms booked: ";
	cin >> Rooms;

	int Stay;
	cout << "Enter length of stay: ";
	cin >> Stay;

	double MSRP = Rate * Rooms * Stay;

	double Discount = 0;

	if (Rooms >= 30)
	{
		Discount = 0.3;
	}
	else if (Rooms >= 20)
	{
		Discount = 0.2;
	}
	else if (Rooms >= 10)
	{
		Discount = 0.1;
	}

	if (Stay >= 3)
	{
		Discount += 0.05;
	}
	
	double Reduction = MSRP * Discount;
	double Gross = MSRP - Reduction;
	
	double TaxRate;
	cout << "Enter the tax rate: ";
	cin >> TaxRate;

	double Tax = Gross * TaxRate;
	double Net = Gross + Tax;
	cout << endl;

	printf( "Room Rate:        $%.2f \n", Rate);
	cout << "Rooms Booked:      " << Rooms << endl;
	cout << "Stay Length:       " << Stay << endl;
	printf( "Standard Price:   $%.2f \n", MSRP);
	cout << "Discount:          " << Discount * 100 << "%" << endl;
	printf( "Price Reduction:  $%.2f \n", Reduction);
	printf( "Price before Tax: $%.2f \n", Gross);
	cout << "Tax Rate:          " << TaxRate * 100 << "%" << endl;
	printf( "Tax Amount:       $%.2f \n", Tax);
	printf( "Total Bill:       $%.2f \n", Net);
	cout << endl;

	system("PAUSE");
	return 0;
}