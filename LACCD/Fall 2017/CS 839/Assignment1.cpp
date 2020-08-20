// CS 839
// Assignment 1

#include <iostream>
//#include <iomanip>
//#include <string>
//#include <cmath>
using namespace std;

int numDivs(int n)
{
	int count = 0;

	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
		{
			count++;
		}
	}

	return count;
}

int maxDivs(int min, int max)
{
	int div = 0;
	int num = 0;

	for (int i = min; i <= max; i++)
	{
		int temp = numDivs(i);
		if (temp > num)
		{
			num = temp;
			div = i;
		}
	}

	return div;
}

int main()
{
	int low, high;
	cout << "Enter low number: ";
	cin >> low;
	cout << "Enter high number: ";
	cin >> high;

	int temp = maxDivs(low, high);

	cout << "Number with most divisors: " << temp << endl;
	cout << "It has this many divisors: " << numDivs(temp) << endl;
	cout << endl;

	return 0;
}