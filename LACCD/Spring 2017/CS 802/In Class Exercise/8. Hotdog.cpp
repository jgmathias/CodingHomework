#include <iostream>
using namespace std;

int main()
{

	int DogNum;

	cout << "How many hot dogs?\t  ";
	cin >> DogNum;

	double DogPrice = 1.5;
	double PercentTax = 9.25 / 100;

	double MealCost = DogNum * DogPrice;
	double Tax = MealCost * PercentTax;
	double Total = MealCost + Tax ;

	cout << "Cost of " << DogNum <<" hot dogs:\t$ "<< MealCost << endl;
	cout << "Sales Tax\t\t$ " << Tax << endl;
	cout << "Price after tax\t\t$ " << Total << endl;

	return 0;
}