//Lab 2: Mathias, James

//James Mathias
//March 24, 2019
//CS 832
//Lab #2: Priority Queue 3 of 5

#include <iostream>
#include <iomanip>
using namespace std;

#include "StructOrder.h"

class OrderQueue
{
public:
	OrderQueue(int size);
	void Enqueue(Order neworder);
	void Dequeue();
	void PartialDequeue(int amount);
	Order GetOrder(int i);
	bool IsEmpty();
	bool IsFull();
	void ShowAll();
	void BackOrderAll();

private:
	int Front = 0;
	int Rear = 0;
	int Size;
	Order *List = new Order[Size];
};

OrderQueue::OrderQueue(int size)
{
	Size = size + 1;
}

void OrderQueue::Enqueue(Order neworder)
{
	List[Rear] = neworder;
	Rear = (Rear + 1) % Size;
}

void OrderQueue::Dequeue()
{
	Front = (Front + 1) % Size;
}

 void OrderQueue::PartialDequeue(int amount)
{
	 List[Front].Amount -= amount;
}

Order OrderQueue::GetOrder(int i)
{
	if (i == -1)
	{
		return List[Front];
	}
	else
	{
		return List[i];
	}
}

bool OrderQueue::IsEmpty()
{
	if (Rear - Front == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool OrderQueue::IsFull()
{
	if ((Rear + 1) % Size == Front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void OrderQueue::ShowAll()
{
	if (Rear < Front)
	{
		Rear += Size;
	}

	cout << "Order Number      Size     Back-Ordered" << endl;
	for (int i = Front; i < Rear; i++)
	{
		Order temp = GetOrder(i % Size);
		cout << setw(12) << right << temp.Num << setw(10) << right << temp.Amount << setw(17) << right << boolalpha << temp.BackOrder << endl;
	}

	Rear = Rear % Size;
}

void OrderQueue::BackOrderAll()
{
	if (Rear < Front)
	{
		Rear += Size;
	}

	for (int i = Front; i < Rear; i++)
	{
		List[i % Size].BackOrder = true;
	}

	Rear = Rear % Size;
}