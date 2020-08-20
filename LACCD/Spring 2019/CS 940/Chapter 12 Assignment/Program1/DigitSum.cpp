//James Mathias
//Mar 26, 2019
//CS 940
//Chapter 12 Assignment: Sum of Digits in a String
//create a program that accepts a string of digits and outputs the sum

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int GetNum();

int main()
{
	int sum = GetNum();
	cout << "Sum of Digits = " << sum << endl;

	cout << "\n";
	system("PAUSE");
	return 0;
}

int GetNum()
{
	string A;
	int B = 0;
	bool Valid = true;

	cout << "Input = ";
	getline(cin, A);

	for (unsigned int i = 0; i < A.size(); i++)
	{
		if (!isdigit(A[i]))
		{
			cout << "Invalid input! Please input a non-negative integer." << endl;
			Valid = false;
			break;
		}
		else
		{
			B += (A[i] - '0');
		}
	}

	if (!Valid)
	{
		B = GetNum();
	}

	return B;
}