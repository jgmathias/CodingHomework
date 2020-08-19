/*
Homework # 1
Author: James Mathias
Email: jgmathias@g.ucla.edu
Course: PIC 10A Summer 2017
Collaborators: N/A

Honesty Pledge:
I, James Mathias, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.

User inputs: state postal code
Output: message saying I <3 (input state) -\\_(-__-)_/-
List of known bugs: none
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
 	string state_code;
	cout << "STATE CODE = ";
	cin >> state_code;

	cout << endl;
	cout << "***************" << endl;
	cout << "** I <3 \"" << state_code << "\" **    -\\_(-__-)_/-" << endl;
	cout << "***************" << endl;

    return 0;
}