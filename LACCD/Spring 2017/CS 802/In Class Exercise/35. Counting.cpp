#include <iostream>
#include <iomanip>
//#include <cstdlib>
//#include <ctime>
using namespace std;

int main()
{

	double num;
	int pcount = 0;
	int ncount = 0;
	double sum = 0;
	double ave;

	cout << "Enter several numeric values, the program exits if the input is 0: " << endl;
	cin >> num;

	while (num != 0)
	{
		if (num > 0)
			{pcount++;}
		else if (num < 0)
			{ncount++;}
		sum += num;
		cin >> num;
	}

	ave = sum / (pcount + ncount);
	cout << "The number of positives is " << pcount << "." << endl;
	cout << "The number of negatives is " << ncount << "." << endl;
	cout << "The total is " << sum << "." << endl;
	cout << "The average is " << ave << "." << endl;

	return 0;
}