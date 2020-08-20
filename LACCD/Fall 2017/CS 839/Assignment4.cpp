//CS 839
//Assignment 4

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

enum Section
{
	ORCHESTRA,
	FRONT,
	MIDDLE,
	BACK
};

struct Date
{
	int month;
	int day;
	int year;
};

struct Seat
{
	char row;
	int column;
	Section section;
	bool assigned;
	string name;
	Date date;
};

void initialize(Seat& Seat, char Row, int Column, Section Section);

int price(Seat Seat);
string sectionName(int num);
void assign(Seat& Seat);

void display1(Seat Seat);
void displayEntireRow(Seat Seat[]);

void sort(vector <Seat>& Assigned);
int search(vector <Seat> Assigned, string Search);

int main()
{

	Seat seats[26][50];

	char row;

	for (row = 'A'; row <= 'Z'; row++)
	{
		Section section;

		if (row <= 'E')
		{
			section = ORCHESTRA;
		}
		else if (row <= 'J')
		{
			section = FRONT;
		}
		else if (row <= 'T')
		{
			section = MIDDLE;
		}
		else
		{
			section = BACK;
		}

		for (int column = 1; column <= 50; column++)
		{
			initialize(seats[row - 65][column - 1], row, column, section);
		}
	}

	char choice;

	while (true)
	{
		char rowInput;
		int columnInput;
		cout << "Choose row (A-Z): ";
		cin >> rowInput;
		cout << "Choose column (1-50): ";
		cin >> columnInput;

		display1(seats[rowInput - 65][columnInput - 1]);

		if (seats[rowInput - 65][columnInput - 1].assigned)
		{
			cout << "This seat is taken." << endl;
		}
		else
		{
			cout << "This seat is not yet taken." << endl;
			cout << "Assign this seat? (y/n) ";
			cin >> choice;
			if (choice == 'y')
			{
				assign(seats[rowInput - 65][columnInput - 1]);
			}
		}
		cout << endl;

		cout << "Pick another seat? (y/n) ";
		cin >> choice;
		if (choice == 'n')
		{
			break;
		}
	}
	cout << endl;

	cout << "Display all seats? (y/n) ";
	cin >> choice;
	if (choice == 'y')
	{
		cout << endl;
		for (row = 'A'; row <= 'Z'; row++)
		{
			displayEntireRow(seats[row - 65]);
		}
	}
	cout << endl;

	vector <Seat> assigned;
	int Price = 0;
	for (row = 'A'; row <= 'Z'; row++)
	{
		for (int column = 1; column <= 50; column++)
		{
			if (seats[row - 65][column - 1].assigned)
			{
				assigned.push_back(seats[row - 65][column - 1]);
				Price += price(seats[row - 65][column - 1]);
			}
		}
	}
	cout << "Total: $" << Price << endl;
	cout << endl;

	cout << "Display assigned seats? (y/n) ";
	cin >> choice;
	if (choice == 'y')
	{
		cout << endl;
		for (unsigned int i = 0; i < assigned.size(); i++)
		{
			display1(assigned[i]);
		}
	}
	cout << endl;

	sort(assigned);

	cout << "Display assigned seats sorted by name? (y/n) ";
	cin >> choice;
	if (choice == 'y')
	{
		cout << endl;
		for (unsigned int i = 0; i < assigned.size(); i++)
		{
			display1(assigned[i]);
		}
	}
	cout << endl;

	while (true)
	{
		string searchName;
		cout << "Enter a name to search for: ";
		cin.ignore();
		getline(cin, searchName);

		int temp = search(assigned, searchName);
		cout << endl;

		cout << "Search another name? (y/n) ";
		cin >> choice;
		if (choice == 'n')
		{
			break;
		}
	}

	cin.ignore();
	return 0;
}

void initialize(Seat& Seat, char Row, int Column, Section Section)
{
	Seat.row = Row;
	Seat.column = Column;
	Seat.section = Section;
	Seat.assigned = 0;
	Seat.name = "";
	Seat.date.month = 1;
	Seat.date.day = 1;
	Seat.date.year = 1900;
}

int price(Seat Seat)
{
	int price = 0;

	if (Seat.section == ORCHESTRA)
	{
		price = 150;
	}
	else if (Seat.section == FRONT)
	{
		price = 100;
	}
	else if (Seat.section == MIDDLE)
	{
		price = 75;
	}
	else if (Seat.section == BACK)
	{
		price = 50;
	}

	return price;
}

string sectionName(int num)
{
	string sectionName;

	if (num == 0)
	{
		sectionName = "ORCHESTRA";
	}
	else if (num == 1)
	{
		sectionName = "FRONT";
	}
	else if (num == 2)
	{
		sectionName = "MIDDLE";
	}
	else if (num == 3)
	{
		sectionName = "BACK";
	}

	return sectionName;
}

void assign(Seat& Seat)
{
	Seat.assigned = 1;

	string Name;
	cout << "Enter name: ";
	cin.ignore();
	getline(cin, Name);
	Seat.name = Name;

	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);

	Seat.date.month = newtime.tm_mon + 1;
	Seat.date.day = newtime.tm_mday;
	Seat.date.year = newtime.tm_year + 1900;

	cout << "This seat is now assigned: " << endl;
	display1(Seat);
}

void display1(Seat Seat)
{
	int Price = price(Seat);
	string SectionName = sectionName(Seat.section);

	cout << "Seat " << Seat.row << setw(2) << Seat.column << ", Section " << setw(9) << SectionName << ", Price $" << setw(3) << Price << ", ";
	if (Seat.assigned)
	{
		cout << Seat.name << ", " << Seat.date.month << "/" << Seat.date.day << "/" << Seat.date.year;
	}
	else
	{
		cout << "EMPTY";
	}

	cout << endl;
}

void displayEntireRow(Seat Seat[])
{
	for (int column = 1; column <= 50; column++)
	{
		display1(Seat[column - 1]);
	}
	cout << endl;
}

void sort(vector <Seat>& Assigned)
{
	for (unsigned int i = 0; i < Assigned.size() - 1; i++)
	{
		for (unsigned int j = i + 1; j < Assigned.size(); j++)
		{
			if (Assigned[i].name > Assigned[j].name)
			{
				Seat Temp = Assigned[i];
				Assigned[i] = Assigned[j];
				Assigned[j] = Temp;
			}
		}
	}
}

int search(vector <Seat> Assigned, string Search)
{
	int Found = -1;

	unsigned int First = 0;
	unsigned int Last = Assigned.size() - 1;
	unsigned int Middle = Last / 2;

	if (Assigned[First].name == Search)
	{
		Found = First;
	}
	else if (Assigned[Last].name == Search)
	{
		Found = Last;
	}
	else
	{
		while (Assigned[Middle].name != Search && First != Middle)
		{
			if (Assigned[Middle].name > Search)
			{
				Last = Middle;
				Middle = (First + Last) / 2;
			}
			else
			{
				First = Middle;
				Middle = (First + Last) / 2;
			}
		}

		if (Assigned[Middle].name == Search)
		{
			Found = Middle;
		}
	}

	if (Found >= 0)
	{
		display1(Assigned[Found]);
	}
	else
	{
		cout << "No such name exists." << endl ;
	}

	return Found;
}