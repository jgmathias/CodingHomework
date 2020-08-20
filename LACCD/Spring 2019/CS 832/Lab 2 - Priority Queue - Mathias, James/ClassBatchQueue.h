//Lab 2: Mathias, James

//James Mathias
//March 24, 2019
//CS 832
//Lab #2: Priority Queue 4 of 5

#include <iostream>
#include <iomanip>
using namespace std;

#include "StructBatch.h"

class BatchQueue
{
public:
	BatchQueue(int size);
	void Enqueue(Batch newbatch);
	void Dequeue();
	void PartialDequeue(int amount);
	Batch GetBatch(int i);
	bool IsEmpty();
	bool IsFull();
	void ShowAll();

private:
	int Front = 0;
	int Rear = 0;
	int Size;
	Batch *List = new Batch[Size];
};

BatchQueue::BatchQueue(int size)
{
	Size = size + 1;
}

void BatchQueue::Enqueue(Batch newbatch)
{
	List[Rear] = newbatch;
	Rear = (Rear + 1) % Size;
}

void BatchQueue::Dequeue()
{
	Front = (Front + 1) % Size;
}

void BatchQueue::PartialDequeue(int amount)
{
	List[Front].Amount -= amount;
}

Batch BatchQueue::GetBatch(int i)
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

bool BatchQueue::IsEmpty()
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

bool BatchQueue::IsFull()
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

void BatchQueue::ShowAll()
{
	if (Rear < Front)
	{
		Rear += Size;
	}

	cout << "Batch Number      Amount       Price" << endl;
	for (int i = Front; i < Rear; i++)
	{
		Batch temp = GetBatch(i % Size);
		cout << setw(12) << right << temp.Num << setw(12) << right << temp.Amount << " $" << setw(10) << right << fixed << setprecision(2) << temp.Price << endl;
	}

	Rear = Rear % Size;
}