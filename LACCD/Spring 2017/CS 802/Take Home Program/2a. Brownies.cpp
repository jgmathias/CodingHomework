#include <iostream>
using namespace std;

int main()
{

	int Length;
	int Width;

	cout << "How long is the brownie tray in inches?\t  ";
	cin >> Length;
	cout << "How wide is the brownie tray in inches?\t  ";
	cin >> Width;

	int Brownies1 = Length * Width;
	int Length2 = Length / 2;
	int Width2 = Width / 2;
	int Brownies2 = Length2 * Width2;

	cout << "A " << Length << " X " << Width << " inch pan can hold " << Brownies1 << " small brownies or " << Brownies2 << " large brownies." << endl;

	return 0;
}