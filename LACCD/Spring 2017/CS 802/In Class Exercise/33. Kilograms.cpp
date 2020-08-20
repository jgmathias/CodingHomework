#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

	int num = 1;

	cout << "Kilograms   Pounds" << endl;
	cout << "------------------" << endl;
	while (num <= 50)
		{cout << setw(6) << num << setw(11) << num*2.2 << endl;
		num = num + 2;}

	return 0;
}