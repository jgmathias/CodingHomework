#include <iostream>
using namespace std;

void printDescription()
{
	cout << "**************************************************************************" << endl;
	cout << "This program takes two numbers (pay rate and hours) and outputs gross pay." << endl;
	cout << "**************************************************************************" << endl;
}


void pay(float rate, int hours)
{
	cout << "The pay is $" << hours * rate << "." << endl;
}


int main()
{
	float num1;
	int num2;
	
	printDescription();
	
	cout << "Please input the pay per hour: ";
	cin >> num1;
	cout << "Please input the number of hours worked: ";
	cin >> num2;

	pay(num1, num2);

	cout << "We hope you enjoyed this program."<< endl;

	return 0;
}