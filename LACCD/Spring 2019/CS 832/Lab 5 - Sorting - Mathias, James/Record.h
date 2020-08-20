//Lab 5: Mathias, James

//James Mathias
//June 2, 2019
//CS 832
//Lab #5: Sorting 1 of 3

#include <string>
using namespace std;

struct Record
{
private:
	string fname;
	string lname;
	double gpa;
	int idnum;
	string email;

public:
	Record();
	Record(string FName, string LName, double GPA, int IDNum, string EMail);
	string FName();
	string LName();
	double GPA();
	int IDNum();
	string EMail();
};

Record::Record()
{

}

Record::Record(string FName, string LName, double GPA, int IDNum, string EMail)
{
	fname = FName;
	lname = LName;
	gpa = GPA;
	idnum = IDNum;
	email = EMail;
}

string Record::FName()
{
	return fname;
}

string Record::LName()
{
	return lname;
}

double Record::GPA()
{
	return gpa;
}

int Record::IDNum()
{
	return idnum;
}

string Record::EMail()
{
	return email;
}