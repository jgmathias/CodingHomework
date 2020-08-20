//CS 840
//Assignment 6
//1 of 5

#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
	string name;
	string id;
	int units;
	double gpa;

public:
	Student(string = "", string = "", int = 0, double = 0);
	void operator=(const Student&);
	bool operator==(const Student&) const;
	~Student();
	void read();
	void print() const;
	string Get_Name();
	double Get_GPA();
};