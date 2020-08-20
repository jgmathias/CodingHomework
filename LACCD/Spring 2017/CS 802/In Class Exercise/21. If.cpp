#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	
	int Integer;

	cout << "Enter an integer: ";
	cin >> Integer;

	if (Integer % 2 == 0) { cout << "HiEven" << endl; }
	if (Integer % 5 == 0) { cout << "HiFive" << endl; }

	return 0;
}