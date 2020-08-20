#include <iostream>
#include <string>
using namespace std;

void intro() {
	cout << "Favorite Course in Spring 17"<< endl
		 << "----------------------------" << endl;
}

string AskName() {
	string name;
	cout << endl << "What is your name? ";
	cin >> name;
	return name;
}

string AskCourse(string name) {
	string course;
	cout << endl << name << ", please enter your favorite course here at school: ";
	cin >> course;
	return course;
}

int AskHours(string name, string course) {
	int hours;
	cout << endl << name << ", please enter how many credit hours of " << course << " you are taking: ";
	cin >> hours;
	return hours;
}

void function(string name, string course, int hours) {
	cout << endl << "Hi " << name << ", your favorite course is " << course << " and it is a " << hours << " credit-hour course." << endl;
}

int main()
{
	intro();
	char again;
	string Name = AskName();
	
	do {
		string Course = AskCourse(Name);
		int Hours = AskHours(Name, Course);
		function(Name, Course, Hours);

		cout << endl << "Go again? (y/n) ";
		cin >> again;
	} while (again == 'y');

	cout << endl << "Thank You" << endl;

	return 0;
}