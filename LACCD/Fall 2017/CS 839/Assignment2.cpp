// CS 839
// Assignment 2

#include <iostream>
//#include <iomanip>
//#include <string>
#include<string.h>
//#include <cmath>
using namespace std;

void search(char string[]);

void change(char string[]);

void first(char string[]);

void last(char string[]);

void inbetween(char string[]);

char null(char string[]);

int main()
{
	char choice = 0;

	do
	{

		char cstring[100];
		cout << "Please enter a string: ";
		cin >> cstring;

		cout << "Make a selection:" << endl;
		cout << "1. Search for a character in the string." << endl;
		cout << "2. Change a character within the string." << endl;
		cout << "3. Display the first n characters of the string." << endl;
		cout << "4. Display the last n character of the string." << endl;
		cout << "5. Display all characters that lie between two given indices." << endl;
		cout << "6. Null the string." << endl;
		cout << "7. Exit." << endl;
		
		cout << "Choice: ";
		cin >> choice;

		while (choice < '1' || choice > '7')
		{
			cout << "Invalid selection. Try again. ";
			cin >> choice;
		}
		
		switch (choice)
		{
			case '1': search(cstring); break;
			case '2': change(cstring); break;
			case '3': first(cstring); break;
			case '4': last(cstring); break;
			case '5': inbetween(cstring); break;
			case '6': cstring[0] = null(cstring); break;
			case '7': cout << "Thank You. Goodbye." << endl;
		}

		//cout << cstring << endl;
		cout << endl;

	} while (choice != '7');

	return 0;
}

void search(char string[])
{
	char character;
	cout << "Please enter the character to search for: ";
	cin >> character;

	int count = 0;
	for (unsigned int i = 0; i < strlen(string); i++)
	{
		if (string[i] == character)
		{
			count++;
		}
	}

	if (count == 0)
	{
		cout << "There are no " << character << "'s in \"" << string << "\"." << endl;
	}
	else
	{
		unsigned int j;
		for (j = 0; j < strlen(string); j++)
		{
			if (string[j] == character)
			{
				break;
			}
		}
		cout << "There are " << count << " " << character << "'s in \"" << string << "\" with the 1st one at index " << j << "." << endl;
	}
}

void change(char string[])
{
	unsigned int index;
	cout << "What is the index of the character you want to change? ";
	cin >> index;
	
	while (index < 0 || index >= strlen(string))
	{
		cout << "That position is outside the bounds of the string. Try again." << endl;
		cout << "What is the index of the character you want to change? ";
		cin >> index;
	}

	char character;
	cout << "What character do you want in that position? ";
	cin >> character;

	string[index] = character;
	cout << "The new string is \"" << string << "\"." << endl;
}

void first(char string[])
{
	unsigned int index;
	cout << "How many characters from the beginning of the string do you want to display? ";
	cin >> index;

	while (index < 0 || index >= strlen(string))
	{
		cout << "That position is outside the bounds of the string. Try again." << endl;
		cout << "How many characters from the beginning of the string do you want to display? ";
		cin >> index;
	}

	for (unsigned int i = 0; i < index; i++)
	{
		cout << string[i];
	}
	cout << endl;
}

void last(char string[])
{
	unsigned int index;
	cout << "How many characters from the end of the string do you want to display? ";
	cin >> index;

	while (index < 0 || index >= strlen(string))
	{
		cout << "That position is outside the bounds of the string. Try again." << endl;
		cout << "How many characters from the end of the string do you want to display? ";
		cin >> index;
	}

	for (unsigned int i = strlen(string) - index; i < strlen(string); i++)
	{
		cout << string[i];
	}
	cout << endl;
}

void inbetween(char string[])
{
	unsigned int index1, index2;
	cout << "Please enter the beginning index: ";
	cin >> index1;
	cout << "Please enter the ending index: ";
	cin >> index2;

	while (index1 < 0 || index2 >= strlen(string) || index2 < index1)
	{
		cout << "One or both of these indices is out of the bounds of the array. Try Again." << endl;
		cout << "Please enter the beginning index: ";
		cin >> index1;
		cout << "Please enter the ending index: ";
		cin >> index2;
	}

	for (unsigned int i = index1; i <= index2; i++)
	{
		cout << string[i];
	}
	cout << endl;
}

char null(char string[])
{
	if (string[0] == NULL)
	{
		cout << "The string was already Null. Nothing was changed." << endl;
	}

	return NULL;
}