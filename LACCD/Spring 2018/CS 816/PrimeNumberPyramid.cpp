//CS 816
//HW1 - Prime Number Pyramid

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool isPrime(int number);
int nextPrime(int lastPrime);

int main()
{
	int lines;
	cout << "How many lines of prime numbers? ";
	cin >> lines;
	while (lines <= 0)
	{
		cout << "Please enter a positive integer. ";
		cin >> lines;
	}
	cout << endl;

	int lastPrime = 2;
	cout << lastPrime << endl;

	for (int i = 2; i <= lines; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			lastPrime = nextPrime(lastPrime);
			cout << lastPrime << " ";
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}

bool isPrime(int number)
{
	if (number%2 == 0)
	{
		return false;
	}
	
	for (int i = 3; i*i <= number; i += 2)
	{
		if (number%i == 0)
		{
			return false;
		}
	}
	return true;
}

int nextPrime(int lastPrime)
{
	do
	{
		lastPrime++;
	}
	while (isPrime(lastPrime) == false);
	return lastPrime;
}