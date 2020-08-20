#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

	int Integer;

	cout << "Enter a number between 0 and 1000: ";
	cin >> Integer;

	if (Integer <= 0 ) { cout << "Number must be positive, try again!" << endl; }
	else { int I = Integer % 10;
		Integer = Integer / 10;
		int X = Integer % 10;
		Integer = Integer / 10;
		int C = Integer % 10;
		Integer = Integer / 10;
		int Sum = I + X + C;
		cout << "The sum of the digits is "<< Sum << endl;
		}

	return 0;
}