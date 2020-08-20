//CS 836
//Final
//3 of 5

#include <iostream>
using namespace std;

const int queueMAX = 100;

class CQueue
{
public:
	CQueue();
	void Enqueue(char);
	void Dequeue();
	char getChar(int);
	bool IsEmpty();
	bool IsFull();
	void ShowAll();

private:
	int front;
	int rear;
	char list[queueMAX];
};