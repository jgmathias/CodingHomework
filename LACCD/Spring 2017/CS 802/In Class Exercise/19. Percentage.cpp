#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//Defining variables
	string Name;
	int NumQuestions;
	int NumCorrect;

	//User inputs values for the variables
	cout << "Enter student's first and last name: ";
	getline(cin, Name);
	cout << "Number of questions on the test: ";
	cin >> NumQuestions;
	cout << "Number of answers the student got correct: ";
	cin >> NumCorrect;

	//Calculating (since we are displaying the percent value, we need to scale by 100)
	double Percent = (float)NumCorrect / (float)NumQuestions * 100.;

	//Output
	cout << endl;
	cout << fixed << setprecision(1);
	cout << Name << "\t " << Percent << "%" << endl;

	return 0;
}