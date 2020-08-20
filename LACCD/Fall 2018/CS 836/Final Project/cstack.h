//CS 836
//Final
//1 of 5

#include <iostream>
using namespace std;

const int stackMAX = 100;

class CStack
{
public:
	CStack();
	bool IsEmpty();
	bool IsFull();
	void Push(char);
	void Pop();
	char Top();

private:
	int top;
	char data[stackMAX];
};