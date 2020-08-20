//CS 836
//Final
//4 of 5

#include <iostream>
using namespace std;

#include "cqueue.h"

CQueue::CQueue()
{
	front = 0;
	rear = 0;
}

void CQueue::Enqueue(char c)
{
	list[rear] = c;
	rear = (rear + 1) % queueMAX;
}

void CQueue::Dequeue()
{
	front = (front + 1) % queueMAX;
}

char CQueue::getChar(int i)
{
	if (i == -1)
	{
		return list[front];
	}
	else
	{
		return list[i];
	}
}

bool CQueue::IsEmpty()
{
	if (rear - front == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CQueue::IsFull()
{
	if ((rear + 1) % queueMAX == front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CQueue::ShowAll()
{

}
