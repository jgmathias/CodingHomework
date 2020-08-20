//CS 836
//Assignment 3
//2 of 3

#include <iostream>
using namespace std;

#include "cqueue.h"

CQueue :: CQueue()
{
	front = 0;
	rear = 0;
}

void CQueue :: Enqueue(Passenger p)
{
	list[rear] = p;
	rear = (rear + 1) % MAX;
}

void CQueue :: Dequeue()
{
	front = (front + 1) % MAX;
}
  
Passenger CQueue :: getPass(int i)
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

bool CQueue :: IsEmpty()
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

bool CQueue :: IsFull()
{
	if ((rear + 1) % MAX == front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CQueue :: ShowAll()
{
	if (rear < front)
	{
		rear += MAX;
	}

	for (int i = front; i < rear; i++)
	{
		cout << getPass(i % MAX).name << endl;
	}

	rear = rear % MAX;
}