#include <iostream>
using namespace std;

void displayMessage()
{
	cout << "This program allows you to calculate the sum of numbers from a lower to a higher value in a range." << endl;
}

int getNum1()
{
	cout << "Enter the first number: ";
	int num;
	cin >> num;
	return num;
}

int getNum2()
{
	cout << "Enter the second number: ";
	int num;
	cin >> num;
	return num;
}

void sum(int a, int b)
{
	int sum = 0;
	for (int x = a; x <= b; x++)
		{sum +=x;}
	cout << "Sum of numbers from " << a << " to " << b << " is " << sum << endl;
}

int main()
{
	displayMessage();
	int a = getNum1();
	int b = getNum2();
	if (a < b)
		{sum(a, b);}
	else if (a > b)
		{sum(b, a);}
	else
		{cout << "Don't enter the same number!" << endl;}

	return 0;
} 