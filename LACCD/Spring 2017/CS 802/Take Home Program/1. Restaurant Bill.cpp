#include <iostream>
using namespace std;

int main()
{
	double MealCost = 44.5;
	double PercentTax = 6.75/100;
	double PercentTip = 15./100;
	double Tax = MealCost*PercentTax;
	double Tip = (MealCost + Tax)*PercentTip;
	double Total = MealCost + Tax + Tip;


	cout << "Meal Cost\t$ " << MealCost << endl;
	cout << "Tax\t\t$ " << Tax << endl;
	cout << "Tip\t\t$ " << Tip << endl;
	cout << "Total\t\t$ " << Total << endl;

	return 0;
}