#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

	int Grade;

	cout << "Enter your numeric test score and" << endl;
	cout << "I will tell you the letter grade you earned:";
	cin >> Grade;

	if (Grade > 100) { cout << "Grade cannot be greater than 100." << endl; }
	else if (Grade >= 90) { cout << "Your grade is A." << endl; }
	else if (Grade >= 80) { cout << "Your grade is B." << endl; }
	else if (Grade >= 70) { cout << "Your grade is C." << endl; }
	else if (Grade >= 60) { cout << "Your grade is D." << endl; }
	else if (Grade >= 0) { cout << "Your grade is F." << endl; }
	else { cout << "Your score cannot be below zero." << endl; }

	return 0;
}