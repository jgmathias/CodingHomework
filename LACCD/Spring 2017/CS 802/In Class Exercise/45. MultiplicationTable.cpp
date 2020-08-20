#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int x = 20;
	int y = 20;
	
	cout << fixed << "    |";
	for (int countx = 1; countx <= x; countx++)
		{cout << setw(5)<< countx;}
	cout << endl;

	cout << "-----";
	for (int countx = 1; countx <= x; countx++)
		{cout << "-----";}
	cout << endl;

	for (int county = 1; county <= y; county++)
		{
		cout << setw(3) << county << " |";
		for (int countx = county; countx <= county*x; countx += county)
			{cout << setw(5) << countx;}
		cout << endl;
		}

	return 0;
}