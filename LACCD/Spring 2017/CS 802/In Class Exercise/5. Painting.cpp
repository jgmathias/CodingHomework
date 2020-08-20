#include <iostream>
using namespace std;

int main()
{
	double SqFeetPerGallon = 340;
	int Height = 6;
	int Width = 100;
	int Coats = 2;

	int SqFeetPainted = Height*Width*Coats;
	double Gallons = SqFeetPainted / SqFeetPerGallon;

	cout << Gallons <<" gallons of paint are needed to paint " << Coats << " coats on a " << Height << " x " << Width << " foot fence." << endl;
	
	return 0;
}