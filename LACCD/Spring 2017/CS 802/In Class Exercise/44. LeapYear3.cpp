#include <iostream>
using namespace std;

int main()
{
	int start = 1999;
	int end = 2100;
	int count = 0;
	
	int shift = 4 - (start % 4);
	if (shift == 4) {shift = 0;}

	int year = start + shift;

	while (year <= end)
	{
		if (year % 400 == 0)
			{count++;
			cout << year << endl;}
		else if (year % 100 == 0)
			{}
		else
			{count++;
			cout << year << endl;}
		year += 4;
	}

	cout << "There are " << count << " leap years from " << start << " to " << end << "." << endl;

	return 0;
}