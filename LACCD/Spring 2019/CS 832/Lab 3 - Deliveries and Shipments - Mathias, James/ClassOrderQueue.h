//Lab 3: Mathias, James

//James Mathias
//April 21, 2019
//CS 832
//Lab #3: Deliveries and Shipments 3 of 5

#include <iostream>
#include <iomanip>
using namespace std;

#include "StructOrder.h"

class OrderQueue
{
public:
	OrderQueue(int size);
	void Enqueue(Order neworder);
	void Dequeue(bool fifo);
	void PartialDequeue(int amount, bool fifo);
	Order GetOrder(int i);
	Order GetOrder(bool fifo);
	bool IsEmpty();
	bool IsFull();
	void ShowAll();
	void BackOrderAll();

	int OrderAmountTotal = 0;

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
	OrderAmountTotal += neworder.Amount;
}

void OrderQueue::Dequeue(bool fifo)
{
	if (fifo)
	{
		OrderAmountTotal -= List[Front].Amount;
		Front = (Front + 1) % Size;
	}
	else
	{
		OrderAmountTotal -= List[(Rear + Size - 1) % Size].Amount;
		Rear = (Rear + Size - 1) % Size;
	}
}

void OrderQueue::PartialDequeue(int amount, bool fifo)
{
	if (fifo)
	{
		List[Front].Amount -= amount;
	}
	else
	{
		List[(Rear + Size - 1) % Size].Amount -= amount;
	}
	OrderAmountTotal -= amount;
}

Order OrderQueue::GetOrder(int i)
{
	return List[i];
}

Order OrderQueue::GetOrder(bool fifo)
{
	if (fifo)
	{
		return List[Front];
	}
	else
	{
		return List[(Rear + Size - 1) % Size];
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