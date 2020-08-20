#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	//Define veriables
	int Books;
	int Points;

	//Input
	cout << "How many books did you purchase through the book club this month? ";
	cin >> Books;

	//Processing
	if (Books <=0 ) { Points = 0; }
	else if (Books == 1) { Points = 5; }
	else if (Books == 2) { Points = 15; }
	else if (Books == 3) { Points = 30; }
	else { Points = 50; }

	//Output
	cout << "You earned " << Points << " points this month." << endl;

	return 0;
}