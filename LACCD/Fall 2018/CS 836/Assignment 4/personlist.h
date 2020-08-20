//CS 836
//Assignment 4
//1 of 3

#include <string>

struct PersonRec
{
	string name;
	int bribe;
	PersonRec* next;
};

class PersonList
{

public:
	PersonList();
	~PersonList();
	void ViewList();
	void AddToList();

private:
	PersonRec* head;
};