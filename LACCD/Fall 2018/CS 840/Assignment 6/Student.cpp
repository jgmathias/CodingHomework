//CS 840
//Assignment 6
//2 of 5

#include <iostream>
using namespace std;

#include "Student.h"

Student::Student(string Name, string ID, int Units, double GPA)
{
	name = Name;
	id = ID;
	units = Units;
	gpa = GPA;
}

void Student::operator=(const Student& NewStudent)
{
	name = NewStudent.name;
	id = NewStudent.id;
	units = NewStudent.units;
	gpa = NewStudent.gpa;
}

bool Student::operator==(const Student& NewStudent) const
{
	return (id == NewStudent.id);
}

Student::~Student()
{
	name = "";
	id = "";
	units = 0;
	gpa = 0;
}

void Student::read()
{
	cout << "Enter student name: ";
	cin >> name;

	cout << "Enter student ID: ";
	cin >> id;

	cout << "Enter student units: ";
	cin >> units;

	cout << "Enter student GPA: ";
	cin >> gpa;
}

void Student::print() const
{
	cout << "Student name: " << name << endl;
	cout << "Student ID: " << id << endl;
	cout << "Student units: " << units << endl;
	cout << "Student GPA: " << gpa << endl;
}

string Student::Get_Name()
{
	return name;
}

double Student::Get_GPA()
{
	return gpa;
}