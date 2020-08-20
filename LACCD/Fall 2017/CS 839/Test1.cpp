// CS 839
// Test 1

#include <iostream>
//#include <iomanip>
#include <string>
//#include <cmath>
using namespace std;

bool validate(int month, int day, int year, int values[]);

int main()
{
	string Input;
	cout << "Enter a day in month/day/year format: ";
	cin >> Input;

	int FirstSlash = Input.find('/');
	string SMonth = Input.substr(0, FirstSlash);
	int Month = stoi(SMonth);
	string DayAndYear = Input.substr(FirstSlash + 1);
	int SecondSlash = DayAndYear.find('/');
	string SDay = DayAndYear.substr(0, SecondSlash);
	int Day = stoi(SDay);
	string SYear = DayAndYear.substr(SecondSlash + 1);
	int Year = stoi(SYear);
	
	int Values[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	bool Validity = validate(Month, Day, Year, Values);

	if (Validity)
	{
		cout << Input << " is a valid date." << endl;
	}
	else
	{
		cout << Input << " is an invalid date." << endl;
	}

	return(0);
}

bool validate(int month, int day, int year, int values[])
{
	
	if (month <= 0 || month >= 13 || day <= 0 || day >= 32 || year < 0)
	{
		return false;
	}

	if (month == 2)
	{
		if (year % 400 == 0)
		{
			if (day == 29)
			{
				return true;
			}
		}
		else if (year % 100 == 0)
		{
			//do nothing
		}
		else if (year % 4 == 0)
		{
			if (day == 29)
			{
				return true;
			}
		}
	}

	if (day > values[month-1])
	{
		return false;
	}

	return true;
}