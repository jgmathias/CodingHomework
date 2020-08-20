//James Mathias
//Apr 30, 2019
//CS 940
//Chapter 15 Assignment: File Filter

#include <iostream>
using namespace std;

#include "FileFilterClass.h"

int main()
{
	string InputFileName;
	cout << "Input File Name = ";
	cin >> InputFileName;

	FileFilterClass temp(InputFileName);

	temp.Encrypt();
	temp.Decrypt();
	temp.Upper();
	temp.Copy();

	system("PAUSE");
	return 0;
}