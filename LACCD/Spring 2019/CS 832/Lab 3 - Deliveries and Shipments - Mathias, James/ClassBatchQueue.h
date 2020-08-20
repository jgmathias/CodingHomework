//Lab 3: Mathias, James

//James Mathias
//April 21, 2019
//CS 832
//Lab #3: Deliveries and Shipments 4 of 5

#include <iostream>
#include <iomanip>
using namespace std;

#include "StructBatch.h"

class BatchQueue
{
public:
	BatchQueue(int size);
	void Enqueue(Batch newbatch);
	void Dequeue(bool fifo);
	void PartialDequeue(int amount, bool fifo);
	Batch GetBatch(int i);
	Batch GetBatch(bool fifo);
	bool IsEmpty();
	bool IsFull();
	void ShowAll();

	int BatchAmountTotal = 0;
	double BatchPriceTotal = 0;

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
	BatchAmountTotal += newbatch.Amount;
	BatchPriceTotal += (newbatch.Amount * newbatch.Price);
}

void BatchQueue::Dequeue(bool fifo)
{
	if (fifo)
	{
		BatchAmountTotal -= List[Front].Amount;
		BatchPriceTotal -= (List[Front].Amount * List[Front].Price);
		Front = (Front + 1) % Size;
	}
	else
	{
		BatchAmountTotal -= List[(Rear + Size - 1) % Size].Amount;
		BatchPriceTotal -= (List[(Rear + Size - 1) % Size].Amount * List[(Rear + Size - 1) % Size].Price);
		Rear = (Rear + Size - 1) % Size;
	}	
}

void BatchQueue::PartialDequeue(int amount, bool fifo)
{
	if (fifo)
	{
		List[Front].Amount -= amount;
		BatchPriceTotal -= (amount * List[Front].Price);
	}
	else
	{
		List[(Rear + Size - 1) % Size].Amount -= amount;
		BatchPriceTotal -= (amount * List[(Rear + Size - 1) % Size].Price);
	}
	BatchAmountTotal -= amount;
}

Batch BatchQueue::GetBatch(int i)
{
	return List[i];
}

Batch BatchQueue::GetBatch(bool fifo)
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