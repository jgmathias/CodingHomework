//James Mathias
//Apr 30, 2019
//CS 940
//Chapter 15 Assignment: File Filter

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileFilterClass
{
public:
	FileFilterClass(string InputFileName);
	void Encrypt();
	void Decrypt();
	void Upper();
	void Copy();

private:
	string InputName;
};

FileFilterClass::FileFilterClass(string InputFileName)
{
	InputName = InputFileName;
}

void FileFilterClass::Encrypt()
{
	ifstream InputFile(InputName);
	ofstream OutputFile("Encrypted" + InputName);

	char nextchar;

	while (InputFile.get(nextchar))
	{
		int value = nextchar;
		nextchar = value + 1;
		OutputFile << nextchar;
	}

	InputFile.close();
	OutputFile.close();
}

void FileFilterClass::Decrypt()
{
	ifstream InputFile(InputName);
	ofstream OutputFile("Decrypted" + InputName);

	char nextchar;

	while (InputFile.get(nextchar))
	{
		int value = nextchar;
		nextchar = value - 1;
		OutputFile << nextchar;
	}

	InputFile.close();
	OutputFile.close();
}

void FileFilterClass::Upper()
{
	ifstream InputFile(InputName);
	ofstream OutputFile("Upper" + InputName);

	char nextchar;

	while (InputFile.get(nextchar))
	{
		nextchar = toupper(nextchar);
		OutputFile << nextchar;
	}

	InputFile.close();
	OutputFile.close();
}

void FileFilterClass::Copy()
{
	ifstream InputFile(InputName);
	ofstream OutputFile("Copied" + InputName);

	char nextchar;

	while (InputFile.get(nextchar))
	{
		OutputFile << nextchar;
	}

	InputFile.close();
	OutputFile.close();
}