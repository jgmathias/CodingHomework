#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

	cout << "Kilograms   Pounds" << endl;
	cout << "------------------" << endl;
	for (int num = 1; num <= 50; num += 2)
		{cout << setw(6) << num << setw(11) << num*2.2 << endl;}

	return 0;
}