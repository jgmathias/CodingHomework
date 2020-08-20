//Lab 2: Mathias, James

//James Mathias
//March 24, 2019
//CS 832
//Lab #2: Priority Queue 2 of 5

using namespace std;

struct Batch
{
public:
	int Num;
	int Amount;
	double Price;
	Batch();
	Batch(int num, int amount, double price);
};

Batch::Batch()
{
	
}

Batch::Batch(int num, int amount, double price)
{
	Num = num;
	Amount = amount;
	Price = price;
}