#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

	int num = 0;

	cout << "Miles   Kilometers" << endl;
	cout << "------------------" << endl;
	while (num++ < 10)
	{
		cout << setw(4) << num << setw(11) << num*1.609 << endl;
	}

	return 0;
}