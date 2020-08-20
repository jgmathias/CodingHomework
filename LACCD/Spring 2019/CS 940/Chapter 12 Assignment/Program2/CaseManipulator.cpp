//James Mathias
//Mar 26, 2019
//CS 940
//Chapter 12 Assignment: Case Manipulator
//create a program that accepts an alphabetic string and manipulates the case of the characters

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string GetAlpha();
string Upper(string input);
string Lower(string input);
string Flip(string input);

int main()
{
	string Input1 = GetAlpha();
	string Output1 = Upper(Input1);
	cout << "Upper Case = " << Output1 << "\n" << endl;

	string Input2 = GetAlpha();
	string Output2 = Lower(Input2);
	cout << "Lower Case = " << Output2 << "\n" << endl;

	string Input3 = GetAlpha();
	string Output3 = Flip(Input3);
	cout << "Flipped Case = " << Output3 << "\n" << endl;

	system("PAUSE");
	return 0;
}

string GetAlpha()
{
	string A;
	bool Valid = true;

	cout << "Input = ";
	getline(cin, A);

	for (unsigned int i = 0; i < A.size(); i++)
	{
		if (!isalpha(A[i]))
		{
			cout << "Invalid input! Please input a string of alphabetic characters." << endl;
			Valid = false;
			break;
		}	
	}

	if (!Valid)
	{
		A = GetAlpha();
	}

	return A;
}

string Upper(string input)
{
	string output = input;
	
	for (unsigned int i = 0; i < output.size(); i++)
	{
		output[i] = toupper(output[i]);
	}

	return output;
}

string Lower(string input)
{
	string output = input;

	for (unsigned int i = 0; i < output.size(); i++)
	{
		output[i] = tolower(output[i]);
	}

	return output;
}

string Flip(string input)
{
	string output = input;

	for (unsigned int i = 0; i < output.size(); i++)
	{
		if (isupper(output[i]))
		{
			output[i] = tolower(output[i]);
		}
		else
		{
			output[i] = toupper(output[i]);
		}
	}

	return output;
}