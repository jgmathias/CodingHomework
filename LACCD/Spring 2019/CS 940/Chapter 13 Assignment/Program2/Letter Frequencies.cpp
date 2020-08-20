//James Mathias
//Apr 13, 2019
//CS 940
//Chapter 13 Assignment: Letter Frequencies
//create a program that accepts an input file, counts the frequencies of different characters, and prints the results

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string InputFileName;
	cout << "Input File Name = ";
	cin >> InputFileName;
	
	char nextchar;
	int table[128];
	for (int i = 0; i < 128; i++)
	{
		table[i] = 0;
	}
	
	ifstream InputFile(InputFileName);

	while (InputFile.get(nextchar))
	{
		int value = nextchar;
		table[value]++;
	}

	InputFile.close();

	cout << "Character Frequency" << endl;
	for (int i = 32; i <= 126; i++)
	{
		cout << setw(9) << right << char(i) << setw(10) << right << table[i] << endl;
	}
	cout << endl;

	system("PAUSE");
	return 0;
}