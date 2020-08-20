#include <iostream>
using namespace std;

int main()
{
	double GallonHold = 16;
	int MilesPerTank = 312;
	double MilesPerGallon = MilesPerTank/GallonHold;

	cout << "The car gets " << MilesPerGallon << " miles per gallon." << endl;
	
	return 0;
}