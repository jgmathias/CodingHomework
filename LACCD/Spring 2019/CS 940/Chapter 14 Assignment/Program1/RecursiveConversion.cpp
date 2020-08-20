//James Mathias
//Apr 22, 2019
//CS 940
//Chapter 14 Assignment: Recursive Conversion
//convert a function to use recursion

#include <iostream>
using namespace std;

void ParkAtZero(int n);

int main()
{
	int input;
	cout << "Input Number = ";
	cin >> input;

	ParkAtZero(input);
	
	system("PAUSE");
	return 0;
}

void ParkAtZero(int n)
{
	if (n == 0)
	{
		cout << "Parking!" << endl;
	}
	else
	{
		cout << "No Parking." << endl;
		ParkAtZero(n - 1);
	}
}