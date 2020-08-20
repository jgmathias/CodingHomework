#include <iostream>
using namespace std;

int main()
{

	const int SMALLSIZE = 2;
	const int LARGESIZE = 3;
	int Length;
	int Width;

	cout << "How long is the brownie tray in inches?\t  ";
	cin >> Length;
	cout << "How wide is the brownie tray in inches?\t  ";
	cin >> Width;

	int Area = Length * Width;
	int SmallBrownies = Area / SMALLSIZE;
	int LargeBrownies = Area / LARGESIZE;

	cout << "A " << Length << " X " << Width << " inch pan can hold " << SmallBrownies << " small brownies or " << LargeBrownies << " large brownies." << endl;
	
	return 0;
}