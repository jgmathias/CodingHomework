#include <iostream>
using namespace std;

int main()
{
	
	double MealCost;
	
	cout << "What is the Meal Cost?\t$ ";
	cin >> MealCost;

	double PercentTax = 6.75 / 100;
	double PercentTip10 = 10. / 100;
	double PercentTip15 = 15. / 100;
	
	double Tax = MealCost*PercentTax;
	double Tip10 = (MealCost + Tax)*PercentTip10;
	double Tip15 = (MealCost + Tax)*PercentTip15;
	double Total10 = MealCost + Tax + Tip10;
	double Total15 = MealCost + Tax + Tip15;

	cout << "Meal Cost\t\t$ " << MealCost << endl;
	cout << "Tax\t\t\t$ " << Tax << endl;
	cout << "Tip (10%)\t\t$ " << Tip10 << endl;
	cout << "Tip (15%)\t\t$ " << Tip15 << endl;
	cout << "Your total bill is $ " << Total10 << " after 10% gratuity." << endl;
	cout << "or" << endl;
	cout << "Your total bill is $ " << Total15 << " after 15% gratuity." << endl;
	
	return 0;
}