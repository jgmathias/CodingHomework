//CS 840
//Assignment 6
//4 of 5

#include <iostream>
using namespace std;

#include "StuWorker.h"

StuWorker::StuWorker(string Name, string ID, int Units, double GPA, int Hours, double HourlyRate)
{
	name = Name;
	id = ID;
	units = Units;
	gpa = GPA;
	hours = Hours;
	hourlyRate = HourlyRate;
}

/*
StuWorker::StuWorker(Student NewStudent, int Hours, double HourlyRate)
{
	name = NewStudent.name;
	id = NewStudent.id;
	units = NewStudent.units;
	gpa = NewStudent.gpa;
	hours = Hours;
	hourlyRate = HourlyRate;
}
*/

void StuWorker::operator=(const StuWorker& NewStuWorker)
{
	name = NewStuWorker.name;
	id = NewStuWorker.id;
	units = NewStuWorker.units;
	gpa = NewStuWorker.gpa;
	hours = NewStuWorker.hours;
	hourlyRate = NewStuWorker.hourlyRate;
}

bool StuWorker::operator==(const StuWorker& NewStuWorker) const
{
	return (id == NewStuWorker.id);
}

StuWorker::~StuWorker()
{
	name = "";
	id = "";
	units = 0;
	gpa = 0;
	hours = 0;
	hourlyRate = 0;
}

void StuWorker::read()
{
	cout << "Enter student name: ";
	cin >> name;

	cout << "Enter student ID: ";
	cin >> id;

	cout << "Enter student units: ";
	cin >> units;

	cout << "Enter student GPA: ";
	cin >> gpa;

	cout << "Enter student weekly hours: ";
	cin >> hours;

	cout << "Enter student hourly rate: ";
	cin >> hourlyRate;
}

void StuWorker::print() const
{
	cout << "Student name: " << name << endl;
	cout << "Student ID: " << id << endl;
	cout << "Student units: " << units << endl;
	cout << "Student GPA: " << gpa << endl;
	cout << "Student weekly hours: " << hours << endl;
	cout << "Student hourly rate: " << hourlyRate << endl;
}