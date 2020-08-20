//James Mathias
//May 13, 2019
//CS 940
//Chapter 16 Assignment: Rotate Left

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class DataType>
void RotateLeft(vector <DataType>& V);

template <class DataType>
void Output(vector <DataType> V);

int main()
{
	cout << "int: enter nonzero integers to add to vector, enter zero to stop" << endl;
	vector<int> IntVector;
	int intinput;
	cin >> intinput;
	while (intinput)
	{
		IntVector.push_back(intinput);
		cin >> intinput;
	}
	for (unsigned int i = 0; i < IntVector.size(); i++)
	{
		Output(IntVector);
		RotateLeft(IntVector);
		cout << "\n";
	}
	cout << "\n";

	cout << "double: enter nonzero number to add to vector, enter zero to stop" << endl;
	vector<double> DoubleVector;
	double doubleinput;
	cin >> doubleinput;
	while (doubleinput)
	{
		DoubleVector.push_back(doubleinput);
		cin >> doubleinput;
	}
	for (unsigned int i = 0; i < DoubleVector.size(); i++)
	{
		Output(DoubleVector);
		RotateLeft(DoubleVector);
		cout << "\n";
	}
	cout << "\n";
	
	cout << "char: enter characters to add to vector, enter space to stop" << endl;
	vector<char> CharVector;
	char charinput;
	cin >> charinput;
	while (charinput != ' ')
	{
		CharVector.push_back(charinput);
		cin >> charinput;
	}
	for (unsigned int i = 0; i < CharVector.size(); i++)
	{
		Output(CharVector);
		RotateLeft(CharVector);
		cout << "\n";
	}
	cout << "\n";

	cout << "string: enter strings to add to vector, enter space to stop" << endl;
	vector<string> StringVector;
	string stringinput;
	cin >> stringinput;
	while (stringinput != " ")
	{
		StringVector.push_back(stringinput);
		cin >> stringinput;
	}
	for (unsigned int i = 0; i < StringVector.size(); i++)
	{
		Output(StringVector);
		RotateLeft(StringVector);
		cout << "\n";
	}
	cout << "\n";

	system("PAUSE");
	return 0;
}

template <class DataType>
void RotateLeft(vector <DataType>& V)
{
	DataType first = V.front();
	V.erase(V.begin());
	V.push_back(first);
}

template <class DataType>
void Output(vector <DataType> V)
{
	for (unsigned int i = 0; i < V.size(); i++)
	{
		cout << V[i] << " ";
	}
}