/*
Homework #2
Author: James Mathias
Email: jgmathias@g.ucla.edu
Course: PIC 10A Summer 2017
Collaborators: N/A

Honesty Pledge:
I, James Mathias, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.

User inputs: employee data
Output: 2 emails using the employee data
List of known bugs: none
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	cout << "===== PLEASE COMPLETE THE FOLLOWING FORM =====" << endl;		//heading of form
	cout << endl;
	
	string name;									//defining variables
	int year;
	string month;
	int day;
	string phone;
	string email;
	double wage;
	
	cout << "What is your full name (First Last)? ";				//getting values for variables from user
	getline (cin, name);
	cout << endl;	cout << "What year were you born? ";
	cin >> year;
	cout << endl;	cout << "What is your birth month? ";
	cin >> month;
	cout << endl;	cout << "What day of the month were you born in? ";
	cin >> day;
	cout << endl;	cout << "What is your telephone number? ";
	cin >> phone;
	cout << endl;	cout << "What is your email? ";
	cin >> email;
	cout << endl;	cout << "Write your desired hourly wage: $";
	cin >> wage;
	cout << endl;
	
	char finitial = name[0];							//first initial (position 0)
	int spacepos = name.find(" ");							//finding position of space after first name
	char linitial = name[spacepos + 1];						//last initial (position one more than space)
	string binitials = "";								//concatenating both initials with periods
		binitials += finitial;
		binitials += ".";
		binitials += linitial;
		binitials += ".";
	int age = 2018 - year;
	
	cout << "* * * * * * * * * * * * * * * * * * * *" << endl;			//first email
	cout << "TO: ALL CURRENT EMPLOYEES" << endl;
	cout << endl;
	cout << endl;
	cout << "Please join me in welcoming " << name << " to our company!" << endl;
	cout << endl;
	cout << setw(15) << "Name: " << name << endl;
	cout << setw(15) << "Initials: " << binitials << endl;
	cout << setw(15) << "EMail: " << email << endl;
	cout << endl;
	cout << "Because " << binitials << " will be " << age << " years young, we will celebrate by going out to lunch next year during " << binitials << "'s birthday on " << month << " " << day << "." << endl;
	cout << endl;
	cout << endl;
	
	string fname = name.substr(0, spacepos);					//first name (substring whose length is the position of the space)
	int phonelength = phone.length();						//getting length of phone number
	string id = "";									//concatenating initials and part of phone number
		id += finitial;
		id += linitial;
		id += phone.substr(phonelength - 4);					//last 4 digits of phone number
	int salary = wage * 40 * 52;							//salary in an unformatted number
		int salary_k = salary / 1000;						//how many thousands in salary
		int salary_1 = salary % 1000;						//how much without thousands
	string zeros;									//how many zeros are needed after comma in formatted number
		if(salary_1 < 10){zeros = "00";}
		else if(salary_1 < 100){zeros = "0";}
		else{zeros = "";}
	
	cout << "* * * * * * * * * * * * * * * * * * * *" << endl;			//second email
	cout << "TO: " << email << endl;
	cout << endl;
	cout << endl;
	cout << "Dear " << fname << "," << endl;
	cout << endl;
	cout << "Please review your new employee information:" << endl;
	cout << endl;
	cout << setw(15) << "Name: " << name << endl;
	cout << setw(15) << "ID #: " << id << endl;
	cout << setw(15) << "DOB: " << month << " " << day << ", " << year << endl;
	cout << setw(16) << "Salary: $" << salary_k << "," << zeros << salary_1 << endl;
	cout << endl;
	cout << "Welcome to our company!" << endl;
	
	return 0;
}