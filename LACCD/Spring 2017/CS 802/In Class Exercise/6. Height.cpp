#include <iostream>
using namespace std;

int main()
{
	int Height = 74;

	int Feet = Height / 12;
	int Inches = Height - (Feet * 12);

		cout << "A " << Height << "-inch tall basketball player is " << Feet << " feet " << Inches << " inches tall." << endl;

	return 0;
}