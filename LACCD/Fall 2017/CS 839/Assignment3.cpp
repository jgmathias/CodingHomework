//CS 839
//Assignment 3

#include <iostream>
#include <string>
using namespace std;

struct Class
{
	string name;
	int units;
	char grade;
};

struct Student
{
	int id;
	string name;
	int num;
	double gpa;
	Class classes[20];
};

double Get_GPA(Class Classes[], int NumOfClasses);
int Get_Info(Student Students[]);

void Display1(Student Student);
void DisplayAll(Student Students[], int NumOfStudents);

void Sort_ID(Student Students[], int NumOfStudents);
int Search_ID(Student Students[], int NumOfStudents, int SearchID);

void Sort_Name(Student Students[], int NumOfStudents);
int Search_Name(Student Students[], int NumOfStudents, string SearchName);

void Sort_GPA(Student Students[], int NumOfStudents);
int Search_GPA(Student Students[], int NumOfStudents, double SearchGPA);

int main()
{
	Student students[100];
	
	int numOfStudents = Get_Info(students);
	
	cout << endl;
	cout << "List of students entered:" << endl << endl;
	DisplayAll(students, numOfStudents);
	
	cout << endl;
	cout << "List of students sorted by ID: " << endl << endl;
	Sort_ID(students, numOfStudents);
	DisplayAll(students, numOfStudents);
	
	cout << endl;
	cout << "List of students sorted by name: " << endl << endl;
	Sort_Name(students, numOfStudents);
	DisplayAll(students, numOfStudents);
	
	cout << endl;
	cout << "List of students sorted by GPA: " << endl << endl;
	Sort_GPA(students, numOfStudents);
	DisplayAll(students, numOfStudents);
	
	int temp = 0;

	cout << endl;
	int searchID;
	cout << "Enter an ID to search for: ";
	cin >> searchID;
	cout << endl;
	temp = Search_ID(students, numOfStudents, searchID);
	
	cout << endl;
	string searchName;
	cout << "Enter an name to search for: ";
	cin.ignore();
	getline(cin, searchName);
	cout << endl;
	temp = Search_Name(students, numOfStudents, searchName);
	
	cout << endl;
	double searchGPA;
	cout << "Enter an GPA to search for: ";
	cin >> searchGPA;
	cout << endl;
	temp = Search_GPA(students, numOfStudents, searchGPA);
	
	return 0;
}

double Get_GPA(Class Classes[], int NumOfClasses)
{
	double GPA = 0;
	double GPASum = 0;
	double CreditSum = 0;
	
	for (int ClassCount = 0; ClassCount < NumOfClasses; ClassCount++)
	{
		int Points = 0;
		
		switch (Classes[ClassCount].grade)
		{
			case 'A': Points = 4; break;
			case 'B': Points = 3; break;
			case 'C': Points = 2; break;
			case 'D': Points = 1; break;
			case 'F': Points = 0; break;
		}
		
		GPASum += Classes[ClassCount].units * Points;
		CreditSum += Classes[ClassCount].units;
	}
	
	GPA = GPASum / CreditSum;
	
	return GPA;
}

int Get_Info(Student Students[])
{
	int StudentCount = 0;
	
	while(StudentCount < 100)
	{
		cout << "Enter student ID: ";
		int InputID;
		cin >> InputID;
		if (InputID == -99)
		{
			cout << endl;
			return StudentCount;
		}
		Students[StudentCount].id = InputID;
		
		cout << "Enter student name: ";
		cin.ignore();
		getline(cin, Students[StudentCount].name);
		
		cout << "Enter number of classes taken by " << Students[StudentCount].name << ": ";
		cin >> Students[StudentCount].num;
		
		for (int ClassCount = 0; ClassCount < Students[StudentCount].num; ClassCount++)
		{
			cout << "Enter name of class " << ClassCount + 1 << ": ";
			cin.ignore();
			getline(cin, Students[StudentCount].classes[ClassCount].name);
			cout << "Enter units for " << Students[StudentCount].classes[ClassCount].name << ": ";
			cin >> Students[StudentCount].classes[ClassCount].units;
			cout << "Enter letter grade received for " << Students[StudentCount].classes[ClassCount].name << ": ";
			cin >> Students[StudentCount].classes[ClassCount].grade;
		}
		
		Students[StudentCount].gpa = Get_GPA(Students[StudentCount].classes, Students[StudentCount].num);
		
		StudentCount++;
		cout << endl;
	}

	return StudentCount;
}

void Display1(Student Student)
{
	cout << "Student: "<< Student.id << " " << Student.name << endl;

	for (int classCount = 0; classCount < Student.num; classCount++)
	{
		cout << Student.classes[classCount].name <<", "<< Student.classes[classCount].units << " units, Grade " << Student.classes[classCount].grade << endl;
	}
	
	cout << "GPA: " << Student.gpa << endl;
	
	cout << endl;
}

void DisplayAll(Student Students[], int NumOfStudents)
{
	for (int StudentCount = 0; StudentCount < NumOfStudents; StudentCount++)
	{
		Display1(Students[StudentCount]);
	}
}

void Sort_ID(Student Students[], int NumOfStudents)
{
	for (int StudentCount = 0; StudentCount < NumOfStudents - 1; StudentCount++)
	{
		for (int StudentCount2 = StudentCount + 1; StudentCount2 < NumOfStudents; StudentCount2++)
		{
			if (Students[StudentCount].id > Students[StudentCount2].id)
			{
				Student Temp = Students[StudentCount];
				Students[StudentCount] = Students[StudentCount2];
				Students[StudentCount2] = Temp;
			}
		}
	}
}

int Search_ID(Student Students[], int NumOfStudents, int SearchID)
{
	Sort_ID(Students, NumOfStudents);
	
	int Found = -1;
	
	int First = 0;
	int Last = NumOfStudents - 1;
	int Middle = Last / 2;

	if (Students[First].id == SearchID)
	{
		Found = First;
	}
	else if (Students[Last].id == SearchID)
	{
		Found = Last;
	}
	else
	{
		while (Students[Middle].id != SearchID && First != Middle)
		{
			if (Students[Middle].id > SearchID)
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

		if (Students[Middle].id == SearchID)
		{
			Found = Middle;
		}
	}

	if (Found >= 0)
	{
		Display1(Students[Found]);
	}
	else
	{
		cout << "No such ID exists." << endl << endl;
	}

	return Found;
}

void Sort_Name(Student Students[], int NumOfStudents)
{
	for (int StudentCount = 0; StudentCount < NumOfStudents - 1; StudentCount++)
	{
		for (int StudentCount2 = StudentCount + 1; StudentCount2 < NumOfStudents; StudentCount2++)
		{
			if (Students[StudentCount].name > Students[StudentCount2].name)
			{
				Student Temp = Students[StudentCount];
				Students[StudentCount] = Students[StudentCount2];
				Students[StudentCount2] = Temp;
			}
		}
	}
}

int Search_Name(Student Students[], int NumOfStudents, string SearchName)
{
	Sort_Name(Students, NumOfStudents);

	int Found = -1;
	
	int First = 0;
	int Last = NumOfStudents - 1;
	int Middle = Last / 2;

	if (Students[First].name == SearchName)
	{
		Found = First;
	}
	else if (Students[Last].name == SearchName)
	{
		Found = Last;
	}
	else
	{
		while (Students[Middle].name != SearchName && First != Middle)
		{
			if (Students[Middle].name > SearchName)
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

		if (Students[Middle].name == SearchName)
		{
			Found = Middle;
		}
	}
	
	if (Found >= 0)
	{
		Display1(Students[Found]);
	}
	else
	{
		cout << "No such name exists." << endl << endl;
	}

	return Found;
}

void Sort_GPA(Student Students[], int NumOfStudents)
{
	for (int StudentCount = 0; StudentCount < NumOfStudents - 1; StudentCount++)
	{
		for (int StudentCount2 = StudentCount + 1; StudentCount2 < NumOfStudents; StudentCount2++)
		{
			if (Students[StudentCount].gpa > Students[StudentCount2].gpa)
			{
				Student Temp = Students[StudentCount];
				Students[StudentCount] = Students[StudentCount2];
				Students[StudentCount2] = Temp;
			}
		}
	}
}

int Search_GPA(Student Students[], int NumOfStudents, double SearchGPA)
{
	Sort_GPA(Students, NumOfStudents);
	
	int Found = -1;
	
	int First = 0;
	int Last = NumOfStudents - 1;
	int Middle = Last / 2;

	if (Students[First].gpa == SearchGPA)
	{
		Found = First;
	}
	else if (Students[Last].gpa == SearchGPA)
	{
		Found = Last;
	}
	else
	{
		while (Students[Middle].gpa != SearchGPA && First != Middle)
		{
			if (Students[Middle].gpa > SearchGPA)
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

		if (Students[Middle].gpa == SearchGPA)
		{
			Found = Middle;
		}
	}
	
	if (Found >= 0)
	{
		Display1(Students[Found]);
	}
	else
	{
		cout << "No such GPA exists." << endl << endl;
	}

	return Found;
}