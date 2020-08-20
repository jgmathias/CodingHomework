//CS 840
//Assignment 6
//3 of 5

#include <iostream>
using namespace std;

#include "Student.h"

class StuWorker : public Student
{
private:
	int hours;
	double hourlyRate;
	
public:
	StuWorker(string = "", string = "", int = 0, double = 0, int = 0, double = 0);
	//StuWorker(Student, int = 0, double = 0);
	void operator=(const StuWorker&);
	bool operator==(const StuWorker&) const;
	~StuWorker();
	void read();
	void print() const;
};