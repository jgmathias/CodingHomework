//James Mathias
//Apr 22, 2019
//CS 940
//Chapter 14 Assignment: Recursive Conversion
//create a recursive function to multiply two numbers

#include <iostream>
using namespace std;

int Multiply(int x, int y);

int main()
{
	int x, y;
	cout << "Input x = ";
	cin >> x;
	cout << "Input y = ";
	cin >> y;

	int z = Multiply(x, y);
	cout << x << " * " << y << " = " << z << endl;

	system("PAUSE");
	return 0;
}

int Multiply(int x, int y)
{
	if (x == 1)
	{
		return y;
	}
	else
	{
		return (Multiply(x - 1, y) + y);
	}
}