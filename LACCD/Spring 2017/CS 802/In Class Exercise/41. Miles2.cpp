#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	cout << "Miles   Kilometers" << endl;
	cout << "------------------" << endl;
	for (int num = 1; num <= 10; num++)
		{cout << setw(4) << num << setw(11) << num*1.609 << endl;}

	return 0;
}