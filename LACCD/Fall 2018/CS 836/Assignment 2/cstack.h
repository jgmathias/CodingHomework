//CS 836
//Assignment 2
//1 of 3

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
	char data[20];

};