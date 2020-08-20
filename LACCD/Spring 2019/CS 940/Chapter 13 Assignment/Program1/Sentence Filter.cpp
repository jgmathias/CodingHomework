//James Mathias
//Apr 13, 2019
//CS 940
//Chapter 13 Assignment: Sentence Filter
//create a program that accepts an input file, manipulates its contents, and then outputs to a different file

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string InputFileName;
	string OutputFileName;
	cout << "Input File Name = ";
	cin >> InputFileName;
	cout << "Output File Name = ";
	cin >> OutputFileName;

	ifstream InputFile(InputFileName);
	ofstream OutputFile(OutputFileName);

	bool first = true;
	char nextchar;

	while(InputFile.get(nextchar))
	{
		if (nextchar == '.')
		{
			first = true;
		}
		else if (!isalpha(nextchar))
		{
			
		}
		else if (first)
		{
			nextchar = toupper(nextchar);
			first = false;
		}
		else
		{
			nextchar = tolower(nextchar);
		}
		
		OutputFile << nextchar;
	}

	InputFile.close();
	OutputFile.close();

	cout << "Copied contents from \"" << InputFileName << "\" into \"" << OutputFileName << "\" in sentence case.\n" << endl;

	system("PAUSE");
	return 0;
}