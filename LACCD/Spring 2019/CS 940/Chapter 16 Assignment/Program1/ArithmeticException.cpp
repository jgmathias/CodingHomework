//James Mathias
//May 13, 2019
//CS 940
//Chapter 16 Assignment: Arithmetic Exceptions

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

int SQRT(int X);

int main()
{
	int x;
	cout << "x = ";
	cin >> x;

	try
	{
		int n = SQRT(x);
		cout << "sqrt(x) = " << n << endl;
	}
	catch(const invalid_argument & e)
	{
		cout << "Error: " << e.what() << endl;
	}
	
	system("PAUSE");
	return 0;
}

int SQRT(int X)
{
	for (int i = 0; i <= X; i++)
	{
		if (i * i == X)
		{
			return i;
		}
	}

	throw invalid_argument("received value that is not a perfect square");
}