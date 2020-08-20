//CS 836
//Assignment 6
//1 of 3

#include <string>

struct PersonRec
{
	string name;
	int bribe;
};

class PersonList
{
public:
	PersonList();
	~PersonList();
	void ViewList();
	void BubbleSort();
	void QuickSort();
	void QS(PersonRec*[], int, int);
	int Partition(PersonRec*[], int, int);
	void AddToList();
	bool AtLeastTwo();

private:
	int size;
	PersonRec* list[10];
};