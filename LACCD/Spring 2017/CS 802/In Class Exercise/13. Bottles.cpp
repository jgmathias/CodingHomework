//This Program calculates the final price of a number of objects after a discount.

#include <iostream>
using namespace std;

int main()
{
	//Assign values.
	int Bottles;
	const double Price = 1.25;
	const double DiscountPercent = .1;

	//Ask user how many bottles.
	cout << "How many bottles:\t\t  ";
	cin >> Bottles;

	//Calculate
	double RegTotal = Bottles * Price;
	double Discount = RegTotal * DiscountPercent;
	double DiscountPrice = RegTotal - Discount;

	//Display output.
	cout << "Total price before discount:\t$ " << RegTotal  << endl;
	cout << "Discount amount:\t\t$ " << Discount << endl;
	cout << "Total price after discount:\t$ " << DiscountPrice << endl;

	return 0;
}
