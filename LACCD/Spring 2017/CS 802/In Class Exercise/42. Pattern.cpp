#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	
	for (int num = 6; num >= 1; num--)
		{for (int num2 = 1; num2 <= num; num2++)
			{cout << num2 << " ";}
		cout << endl;}

	return 0;
}