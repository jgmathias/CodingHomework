//CS 840
//Assignment 1

#include <iostream>
#include <string>
using namespace std;

class Course
{
private:
	string name;
	int units;
	char grade;

public:
	Course(string = "", int = 0, char = NULL);

	void Add_Course();
	void Edit_Course();
	void Display_Course();
	void Delete_Course();

	int Get_Units();
	char Get_Grade();
	
};

int Menu();
int Get_Number(int Size);

int main()
{
	const int size = 10;

	Course List[size];
	
	Course* pointer_list = List;
	
	int choice = 0;
	int number = 0;
	double GPA = 0;
	double earned = 0;
	double attempted = 0;

	do
	{
		choice = Menu();

		switch (choice)
		{
		case 1:
			number = Get_Number(size);
			pointer_list[number].Add_Course();
			break;

		case 2:
			number = Get_Number(size);
			pointer_list[number].Edit_Course();
			break;

		case 3:
			number = Get_Number(size);
			pointer_list[number].Display_Course();
			break;

		case 4:
			for(int i = 0; i < size; i++)
			{
				pointer_list[i].Display_Course();
			}
			break;

		case 5:
			GPA = 0;
			earned = 0;
			attempted = 0;
			for (int i = 0; i < size; i++)
			{
				double points = 0;

				switch (pointer_list[i].Get_Grade())
				{
				case 'A':
					points = 4;
					break;
				case 'B':
					points = 3;
					break;
				case 'C':
					points = 2;
					break;
				case 'D':
					points = 1;
					break;
				case 'F':
					points = 0;
					break;
				}

				earned += pointer_list[i].Get_Units() * points;
				attempted += pointer_list[i].Get_Units();
			}
			if (earned == 0)
			{
				GPA = 0;
			}
			else
			{
				GPA = earned / attempted;
			}
			cout << "GPA: " << GPA << endl;
			break;

		case 6:
			for (int i = 0; i < size; i++)
			{
				pointer_list[i].Delete_Course();
			}
			cout << "All courses are now deleted." << endl;
			break;

		case 7:
			cout << "Thank You. Goodbye." << endl;
		}

		cout << endl;

	} while (choice != 7);

	cin.ignore();
	return 0;
}

int Menu()
{
	int Choice = 0;

	cout << "Select one of the following actions:" << endl;
	cout << "1. Add new course." << endl;
	cout << "2. Edit an existing course." << endl;
	cout << "3. Display a course." << endl;
	cout << "4. List all courses." << endl;
	cout << "5. Display GPA." << endl;
	cout << "6. Delete all courses." << endl;
	cout << "7. Exit." << endl;

	cout << "Choice: ";
	cin >> Choice;

	while (Choice < 1 || Choice > 7)
	{
		cout << "Invalid selection. Try again: ";
		cin >> Choice;
	}

	return Choice;
}

int Get_Number(int Size)
{
	int Number;

	cout << "Which course would you like to add, edit, or view? Choose a number between 1 and " << Size << ": ";
	cin >> Number;

	while (Number < 1 || Number > Size)
	{
		cout << "Invalid selection. Try again: ";
		cin >> Number;
	}

	return Number-1;
}

Course::Course(string Name, int Units, char Grade)
{
}

void Course::Add_Course()
{
	cout << "Course Name:  ";
	cin >> name;
	cout << "Course Units: ";
	cin >> units;
	cout << "Course Grade: ";
	cin >> grade;

	grade = toupper(grade);
}

void Course::Edit_Course()
{
	Display_Course();
	Add_Course();
}

void Course::Display_Course()
{
	cout << "Course Name:  " << name << endl;
	cout << "Course Units: " << units << endl;
	cout << "Course Grade: " << grade << endl;
}

void Course::Delete_Course()
{
	name = "";
	units = 0;
	grade = NULL;
}

int Course::Get_Units()
{
	return units;
}

char Course::Get_Grade()
{
	return grade;
}