#include <iostream>
using namespace std;

void menu() {
		cout << "1. Square" << endl
		<< "2. Rectangle" << endl
		<< "3. Right Triangle" << endl
		<< "4. Quit" << endl
		<< "Enter your choice (1-4): ";
}

int Choice(){
	int choice;
	cin >> choice;
	return choice;
}

double square() {
	double Height;
	cout << endl << "Length of Square's side: ";
	cin >> Height;
	double area = Height * Height;
	return area;
}

double rectangle() {
	double Height, Width;
	cout << endl << "Enter the height of the rectangle: ";
	cin >> Height;
	cout << "Enter the width of the rectangle: ";
	cin >> Width;
	double area = Height * Width;
	return area;
}

double triangle() {
	double Height, Width;
	cout << endl << "Enter the height of the triangle: ";
	cin >> Height;
	cout << "Enter the width of the triangle: ";
	cin >> Width;
	double area = 0.5* Height * Width;
	return area;
}

int main()
{
	cout << "Geometry Calculator" << endl << endl;
	int choice;
	do {
		menu();
		choice = Choice();

		if (choice == 1) {
			double Area = square();
			cout << "The area is " << Area << "." << endl << endl;
		}
		else if (choice == 2) {
			double Area = rectangle();
			cout << "The area is " << Area << "." << endl << endl;
		}
		else if (choice == 3) {
			double Area = triangle();
			cout << "The area is " << Area << "." << endl << endl;
		}
		else if (choice == 4) {
			cout << endl << "Thank You!" << endl;
		}
		else { cout << "The choice must be 1, 2, 3, or 4." << endl << endl; }
	} while (choice != 4);

	return 0;
}