//CS 840
//Assignment 6
//5 of 5

#include <iostream>
#include <vector>
using namespace std;

#include "StuWorker.h"

void sort(vector<Student*>);
int search(vector<Student*>, string);

int main()
{
	cout << "---------- Creating List of Students ----------" << endl;
	cout << endl;
	
	vector<Student*> StudentList;

	char choice = ' ';

	for (int i = 1; i <= 20; i++)
	{
		while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
		{
			cout << "Add student #" << i << "? (Y/N) ";
			cin >> choice;
		}

		if (choice == 'y' || choice == 'Y')
		{
			choice = ' ';

			while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
			{
				cout << "Is student #" << i << " a worker? (Y/N) ";
				cin >> choice;
			}
			
			if (choice == 'y' || choice == 'Y')
			{
				StuWorker* temp = new StuWorker;
				temp->read();
				StudentList.push_back(temp);
			}
			else
			{
				Student* temp = new Student;
				temp->read();
				StudentList.push_back(temp);
			}

			cout << endl;
		}
		else
		{
			cout << endl;
			break;
		}

		choice = ' ';
	}

	cout << endl;

	cout << "---------- Printing Unsorted List of Students ----------" << endl;
	cout << endl;

	for (unsigned int j = 1; j <= StudentList.size(); j++)
	{
		cout << "Student #" << j << endl;
		StudentList[j - 1]->print();
		cout << endl;
	}

	cout << endl;

	cout << "---------- Printing Sorted List of Students ----------" << endl;
	cout << endl;

	sort(StudentList);

	for (unsigned int k = 1; k <= StudentList.size(); k++)
	{
		cout << "Student #" << k << endl;
		StudentList[k - 1]->print();
		cout << endl;
	}

	cout << endl;

	cout << "---------- Display Average GPA of All Students ----------" << endl;
	cout << endl;

	double total = 0;

	for (unsigned int l = 1; l <= StudentList.size(); l++)
	{
		total += StudentList[l - 1]->Get_GPA();
	}

	double average = total / StudentList.size();

	cout << "Average GPA: " << average << endl;

	cout << endl;
	cout << endl;

	cout << "---------- Search for a student by Name ----------" << endl;
	cout << endl;

	string Name = "";
	cout << "Enter a student to search for: ";
	cin >> Name;
	
	int index = search(StudentList, Name);

	if (index == -1)
	{
		cout << "No student with that name found." << endl;
	}
	else
	{
		cout << "That student is #" << index + 1 << " in the sorted list." << endl;
		StudentList[index]->print();
	}

	cout << endl;
	cout << endl;

	system("PAUSE");
	return 0;
}

void sort(vector<Student*> studentlist)
{
	int n1 = studentlist.size();
	Student* temp = NULL;

	do
	{
		int n2 = 0;

		for (int i = 1; i <= n1 - 1; i++)
		{
			bool swap = false;
			
			for (int j = 0; j < studentlist[i - 1]->Get_Name().length(); j++)
			{
				if (studentlist[i - 1]->Get_Name()[j] > studentlist[i]->Get_Name()[j])
				{
					swap = true;
					break;
				}
				else if (studentlist[i - 1]->Get_Name()[j] < studentlist[i]->Get_Name()[j])
				{
					break;
				}
			}
			
			if (swap)
			{
				temp = studentlist[i - 1];
				studentlist[i - 1] = studentlist[i];
				studentlist[i] = temp;

				n2 = i;
			}
		}

		n1 = n2;
	} while (n1 > 1);
}

int search(vector<Student*> studentlist, string name)
{
	int Found = -1;

	unsigned int First = 0;
	unsigned int Last = studentlist.size() - 1;
	unsigned int Middle = Last / 2;

	if (studentlist[First]->Get_Name() == name)
	{
		Found = First;
	}
	else if (studentlist[Last]->Get_Name() == name)
	{
		Found = Last;
	}
	else
	{
		while (studentlist[Middle]->Get_Name() != name && First != Middle)
		{
			if (studentlist[Middle]->Get_Name() > name)
			{
				Last = Middle;
			}
			else
			{
				First = Middle;
			}

			Middle = (First + Last) / 2;
		}

		if (studentlist[Middle]->Get_Name() == name)
		{
			Found = Middle;
		}
	}

	return Found;
}