//CS 836
//Assignment 3
//1 of 3

#include <string>

const int MAX = 4;

struct Passenger
{
	string name;
};

class CQueue
{
public:
	CQueue();
	void Enqueue(Passenger);
	void Dequeue();
	Passenger getPass(int);
	bool IsEmpty();
	bool IsFull();
	void ShowAll();

private:
	int front;
	int rear;
	Passenger list[MAX];
};