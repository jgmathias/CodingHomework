#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int Choice;
	double Height;
	double Width;

	cout << "Geometry Calculator" << endl << endl
		<< "1. Calculate the area of a Circle" << endl
		<< "2. Calculate the area of a Rectangle" << endl
		<< "3. Calculate the area of a Triangle" << endl
		<< "4. Quit" << endl
		<< "Enter your choice (1-4): ";
	cin >> Choice;

	switch (Choice)
		{case 1:
			cout << endl << "Enter the radius of the circle: ";
			cin >> Height;
			cout << "The area is " << 3.14 * Height * Height << "." << endl;
			break;
		case 2:
			cout << endl << "Enter the height of the rectangle: ";
			cin >> Height;
			cout << "Enter the width of the rectangle: ";
			cin >> Width;
			cout << "The area is " << Height * Width << "." << endl;
			break;
		case 3:
			cout << endl << "Enter the height of the triangle: ";
			cin >> Height;
			cout << "Enter the width of the triangle: ";
			cin >> Width;
			cout << "The area is " << 0.5 * Height * Width << "." << endl;
			break;
		case 4:
			break;
		default:
			cout << endl << "The choice must be 1, 2, 3, or 4." << endl;
	}
	return 0;
}