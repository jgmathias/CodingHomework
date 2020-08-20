//CS 816
//HW3 - Binary Addition Calculator

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int CellSize = 6;
bool C = false;

bool BitAdd(bool b1, bool b2);
string BoolToString(bool b);
bool CharToBool(char c);

int main()
{
	string binA, binB, binC;
	
	cout << "Enter two "<< CellSize <<"-digit binary numbers to add:" << endl;
	cin >> binA;
	cin >> binB;

	binC = "";

	for (int i = CellSize-1; i >= 0; i--)
	{
		bool Ba = CharToBool(binA[i]);
		bool Bb = CharToBool(binB[i]);

		bool Bc = BitAdd(Ba, Bb);

		string temp = BoolToString(Bc);
		binC.insert(0, temp);
	}

	cout << endl;
	cout << binC << endl;
	cout << "C = " << C << endl;

	cout << endl;
	system("pause");
	return 0;
}

bool BitAdd(bool b1, bool b2)
{

	if (b1 == true && b2 == true)
	{
		if (C == true)
		{
			C = true;
			return true;
		}
		else
		{
			C = true;
			return false;
		}
	}

	if ((b1 == false && b2 == true) || (b1 == true && b2 == false))
	{
		if (C == true)
		{
			C = true;
			return false;
		}
		else
		{
			C = false;
			return true;
		}
	}

	if (b1 == false && b2 == false)
	{
		if (C == true)
		{
			C = false;
			return true;
		}
		else
		{
			C = false;
			return false;
		}
	}

}

string BoolToString(bool b)
{
	if (b == true)
	{
		return "1";
	}
	else
	{
		return "0";
	}
}

bool CharToBool(char c)
{
	if (c == '1')
	{
		return true;
	}
	else
	{
		return false;
	}
}