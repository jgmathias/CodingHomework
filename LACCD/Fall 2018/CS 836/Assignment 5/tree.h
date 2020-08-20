//CS 836
//Assignment 5
//1 of 3

#include <string>

struct PersonRec
{
	string name;
	int bribe;
	PersonRec* childLess;
	PersonRec* childMore;
};

class PersonTree
{

public:
	PersonTree();
	~PersonTree();
	void ViewTree();
	int recursion(PersonRec*, int);
	void AddToTree();

private:
	PersonRec* root;
};