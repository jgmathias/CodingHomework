//Lab 3: Mathias, James

//James Mathias
//April 21, 2019
//CS 832
//Lab #3: Deliveries and Shipments 1 of 5

using namespace std;

struct Order
{
public:
	int Num;
	int Amount;
	bool BackOrder;
	Order();
	Order(int num, int amount);
};

Order::Order()
{
	
}

Order::Order(int num, int amount)
{
	Num = num;
	Amount = amount;
	BackOrder = false;
}