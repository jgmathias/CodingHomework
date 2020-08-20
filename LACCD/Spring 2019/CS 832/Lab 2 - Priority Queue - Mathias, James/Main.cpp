//Lab 2: Mathias, James

//James Mathias
//March 24, 2019
//CS 832
//Lab #2: Priority Queue 5 of 5

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "ClassOrderQueue.h"
#include "ClassBatchQueue.h"

int Menu();													//display menu 
double GetNum(bool IsInteger, string Question, int Max);	//get integer if "IsInteger" is true, get double if "IsInteger" is false
															//if "Max" > 0, limit output by "Max"

int main()
{
	cout << "Welcome to the Widget Company\n"
		<< "Place an order and we will fulfill it as soon as possible.\n"
		<< "Also, our production is limited so your order may be back-ordered.\n"
		<< "For an added charge, you may have your order rushed.\n"
		<< "The price of a Widget may vary with each batch we receice." << endl;
	
	int Choice = 0;
	
	int BatchNum = 0;
	BatchQueue Inventory(100);								//queue that holds up to 100 batches of widgets
	
	int OrderNum = 0;
	OrderQueue Priority1(100);								//queue that holds up to 100 high-priority orders
	OrderQueue Priority2(100);								//queue that holds up to 100 medium-priority orders
	OrderQueue Priority3(100);								//queue that holds up to 100 low-priority orders
	
	int DailyOrdersProcessed = 0;							//initialize daily and total counters
	int TotalOrdersProcessed = 0;
	
	int DailyBatchesProcessed = 0;
	int TotalBatchesProcessed = 0;

	double DailyCosts = 0;
	double TotalCosts = 0;
	
	double DailySales = 0;
	double TotalSales = 0;

	double DailyProfits = 0;
	double TotalProfits = 0;

	int Day = 1;											//first day
	cout << "\n"
		<< "     -----Day " << Day << "-----" << endl;

	do
	{
		Choice = Menu();

		switch (Choice)
		{
		case 1:
		{
			if (Inventory.IsFull())
			{
				cout << "There is no space for any more batches of inventory." << endl;
			}
			else
			{												//create new "Batch" and add it to "Inventory" queue
				BatchNum++;
				int Amount = int(GetNum(true, "How many Widgits are in this batch?", 0));
				double Price = GetNum(false, "What is the base price of each Widget in this batch?", 0);
				Batch NewBatch(BatchNum, Amount, Price);
				Inventory.Enqueue(NewBatch);
				cout << "Batch " << BatchNum << " is created with " << Amount << " Widgets at a cost of $" << fixed << setprecision(2) << Price << " each." << endl;
				DailyCosts += (Amount * Price);
			}
			break;
		}
		case 2:
		{
			if (Priority1.IsFull() && Priority2.IsFull() && Priority3.IsFull())
			{
				cout << "There is no space for any more orders." << endl;
			}
			else
			{
				if (Priority1.IsFull())
				{
					cout << "Priority 1 is full. " << endl;
				}

				if (Priority2.IsFull())
				{
					cout << "Priority 2 is full. " << endl;
				}

				if (Priority3.IsFull())
				{
					cout << "Priority 3 is full. " << endl;
				}

				int Priority = int(GetNum(true, "What is the priority of this order?", 3));
															//ask user for the priority of the order, and then order will be sorted into the appropriate queue
				if (Priority == 1)
				{
					if (Priority1.IsFull())
					{
						cout << "There is no space for more priority 1 orders." << endl;
					}
					else
					{										//create new "Order" and add it to "Priority1" queue
						OrderNum++;
						int Size = int(GetNum(true, "How many Widgits is this order for?", 0));
						Order NewOrder(OrderNum, Size);
						Priority1.Enqueue(NewOrder);
						cout << "Order " << OrderNum << " is created with a size of " << Size << " Widgets with a priority of " << Priority << "." << endl;
					}
				}
				else if (Priority == 2)
				{
					if (Priority2.IsFull())
					{
						cout << "There is no space for more priority 2 orders." << endl;
					}
					else
					{										//create new "Order" and add it to "Priority2" queue
						OrderNum++;
						int Size = int(GetNum(true, "How many Widgits is this order for?", 0));
						Order NewOrder(OrderNum, Size);
						Priority2.Enqueue(NewOrder);
						cout << "Order " << OrderNum << " is created with a size of " << Size << " Widgets with a priority of " << Priority << "." << endl;
					}
				}
				else if (Priority == 3)
				{
					if (Priority3.IsFull())
					{
						cout << "There is no space for more priority 3 orders." << endl;
					}
					else
					{										//create new "Order" and add it to "Priority3" queue
						OrderNum++;
						int Size = int(GetNum(true, "How many Widgits is this order for?", 0));
						Order NewOrder(OrderNum, Size);
						Priority3.Enqueue(NewOrder);
						cout << "Order " << OrderNum << " is created with a size of " << Size << " Widgets with a priority of " << Priority << "." << endl;
					}
				}
			}
			break;
		}
		case 3:
		{
			if (Inventory.IsEmpty())
			{
				cout << "There is no more remaining inventory." << endl;
			}
			else
			{												//display all remaining inventory
				cout << "   ---Remaining Inventory---" << endl;
				Inventory.ShowAll();
			}
			break;
		}
		case 4:
		{
			if (Priority1.IsEmpty() && Priority2.IsEmpty() && Priority3.IsEmpty())
			{
				cout << "There are no pending orders." << endl;
			}
			else
			{
				if (!Priority1.IsEmpty())
				{											//display all remaining priority 1 orders
					cout << "   ---Priority 1 Orders---" << endl;
					Priority1.ShowAll();
				}

				if (!Priority2.IsEmpty())
				{											//display all remaining priority 2 orders
					cout << "   ---Priority 2 Orders---" << endl;
					Priority2.ShowAll();
				}

				if (!Priority3.IsEmpty())
				{											//display all remaining priority 3 orders
					cout << "   ---Priority 3 Orders---" << endl;
					Priority3.ShowAll();
				}
			}
			break;
		}
		case 5:
		{
			if (Priority1.IsEmpty() && Priority2.IsEmpty() && Priority3.IsEmpty())
			{
				cout << "There are no pending orders." << endl;
			}
			else if(Inventory.IsEmpty())
			{
				Priority1.BackOrderAll();
				Priority2.BackOrderAll();
				Priority3.BackOrderAll();
				cout << "There is no remaining inventory. All pending orders have been back-ordered." << endl;
			}
			else
			{
				cout << "   ---Fulfilled Order Report---\n"
					<< "Order Num     Batch Num     Fulfilled Amount     Base Cost     Priority     Back-Ordered     This Sale" << endl;
								
				while (!Priority1.IsEmpty())
				{											//process priority 1 orders
					if (Inventory.IsEmpty())
					{										//mark remaining orders as back-ordered
						Priority1.BackOrderAll();
						break;
					}

					Order ProcessOrder = Priority1.GetOrder(-1);
					Batch ProcessBatch = Inventory.GetBatch(-1);
					int FulfilledAmount;

					if (ProcessOrder.Amount < ProcessBatch.Amount)
					{
						FulfilledAmount = ProcessOrder.Amount;
						Priority1.Dequeue();
						DailyOrdersProcessed++;
						Inventory.PartialDequeue(FulfilledAmount);
					}
					else if (ProcessOrder.Amount > ProcessBatch.Amount)
					{
						FulfilledAmount = ProcessBatch.Amount;
						Priority1.PartialDequeue(FulfilledAmount);
						Inventory.Dequeue();
						DailyBatchesProcessed++;
					}
					else
					{
						FulfilledAmount = ProcessOrder.Amount;
						Priority1.Dequeue();
						DailyOrdersProcessed++;
						Inventory.Dequeue();
						DailyBatchesProcessed++;
					}

					double BaseCost = ProcessBatch.Price;
					bool IsBackOrder = ProcessOrder.BackOrder;
					double ThisSale = (FulfilledAmount * BaseCost) * (1.8 - (0.2 * IsBackOrder));
					cout << setw(9) << right << ProcessOrder.Num << setw(14) << right << ProcessBatch.Num << setw(21) << right << FulfilledAmount << " $" << setw(12) << right << fixed << setprecision(2) << BaseCost << setw(13) << right << 1 << setw(17) << right << boolalpha << IsBackOrder << " $" << setw(12) << right << fixed << setprecision(2) << ThisSale << endl;
				
					DailySales += ThisSale;
				}

				while (!Priority2.IsEmpty())
				{											//process priority 2 orders
					if (Inventory.IsEmpty())
					{										//mark remaining orders as back-ordered
						Priority2.BackOrderAll();
						break;
					}

					Order ProcessOrder = Priority2.GetOrder(-1);
					Batch ProcessBatch = Inventory.GetBatch(-1);
					int FulfilledAmount;

					if (ProcessOrder.Amount < ProcessBatch.Amount)
					{
						FulfilledAmount = ProcessOrder.Amount;
						Priority2.Dequeue();
						DailyOrdersProcessed++;
						Inventory.PartialDequeue(FulfilledAmount);
					}
					else if (ProcessOrder.Amount > ProcessBatch.Amount)
					{
						FulfilledAmount = ProcessBatch.Amount;
						Priority2.PartialDequeue(FulfilledAmount);
						Inventory.Dequeue();
						DailyBatchesProcessed++;
					}
					else
					{
						FulfilledAmount = ProcessOrder.Amount;
						Priority2.Dequeue();
						DailyOrdersProcessed++;
						Inventory.Dequeue();
						DailyBatchesProcessed++;
					}

					double BaseCost = ProcessBatch.Price;
					bool IsBackOrder = ProcessOrder.BackOrder;
					double ThisSale = (FulfilledAmount * BaseCost) * (1.6 - (0.2 * IsBackOrder));
					cout << setw(9) << right << ProcessOrder.Num << setw(14) << right << ProcessBatch.Num << setw(21) << right << FulfilledAmount << " $" << setw(12) << right << fixed << setprecision(2) << BaseCost << setw(13) << right << 2 << setw(17) << right << boolalpha << IsBackOrder << " $" << setw(12) << right << fixed << setprecision(2) << ThisSale << endl;

					DailySales += ThisSale;
				}

				while (!Priority3.IsEmpty())
				{											//process priority 3 orders
					if (Inventory.IsEmpty())
					{										//mark remaining orders as back-ordered
						Priority3.BackOrderAll();
						break;
					}

					Order ProcessOrder = Priority3.GetOrder(-1);
					Batch ProcessBatch = Inventory.GetBatch(-1);
					int FulfilledAmount;

					if (ProcessOrder.Amount < ProcessBatch.Amount)
					{
						FulfilledAmount = ProcessOrder.Amount;
						Priority3.Dequeue();
						DailyOrdersProcessed++;
						Inventory.PartialDequeue(FulfilledAmount);
					}
					else if (ProcessOrder.Amount > ProcessBatch.Amount)
					{
						FulfilledAmount = ProcessBatch.Amount;
						Priority3.PartialDequeue(FulfilledAmount);
						Inventory.Dequeue();
						DailyBatchesProcessed++;
					}
					else
					{
						FulfilledAmount = ProcessOrder.Amount;
						Priority3.Dequeue();
						DailyOrdersProcessed++;
						Inventory.Dequeue();
						DailyBatchesProcessed++;
					}

					double BaseCost = ProcessBatch.Price;
					bool IsBackOrder = ProcessOrder.BackOrder;
					double ThisSale = (FulfilledAmount * BaseCost) * (1.4 - (0.1 * IsBackOrder));
					cout << setw(9) << right << ProcessOrder.Num << setw(14) << right << ProcessBatch.Num << setw(21) << right << FulfilledAmount << " $" << setw(12) << right << fixed << setprecision(2) << BaseCost << setw(13) << right << 3 << setw(17) << right << boolalpha << IsBackOrder << " $" << setw(12) << right << fixed << setprecision(2) << ThisSale << endl;

					DailySales += ThisSale;
				}

				if (Priority1.IsEmpty() && Priority2.IsEmpty() && Priority3.IsEmpty())
				{
					cout << "\n"
						<<"All orders are fulfilled." << endl;
				}
				else
				{
					cout << "\n"
						<< "Inventory has run out. Remaining orders have been back-ordered." << endl;
				}
			}

			DailyProfits = DailySales - DailyCosts;

			cout << "\n"									//display daily report
				<< "   ---Daily Report---\n"
				<< "Orders Processed: " << DailyOrdersProcessed << "\n"
				<< "Batches Processed: " << DailyBatchesProcessed << "\n" 
				<< "Costs:  $" << setw(10) << right << fixed << setprecision(2) << DailyCosts << "\n"
				<< "Sales:  $" << setw(10) << right << fixed << setprecision(2) << DailySales << "\n"
				<< "Profit: $" << setw(10) << right << fixed << setprecision(2) << DailyProfits << endl;
			
			TotalOrdersProcessed += DailyOrdersProcessed;	//add daily counters into total counters
			TotalBatchesProcessed += DailyBatchesProcessed;
			TotalCosts += DailyCosts;
			TotalSales += DailySales;
			TotalProfits += DailyProfits;

			cout << "\n"									//display total report
				<< "   ---Totals So Far---\n"
				<< "Orders Processed: " << TotalOrdersProcessed << "\n"
				<< "Batches Processed: " << TotalBatchesProcessed << "\n" 
				<< "Costs:  $" << setw(10) << right << fixed << setprecision(2) << TotalCosts << "\n"
				<< "Sales:  $" << setw(10) << right << fixed << setprecision(2) << TotalSales << "\n"
				<< "Profit: $" << setw(10) << right << fixed << setprecision(2) << TotalProfits << endl;
			
			Day++;											//new day
			cout << "\n"
				<< "     -----Day " << Day << "-----" << endl;

			DailyOrdersProcessed = 0;						//reset the daily counters
			DailyBatchesProcessed = 0;
			DailyCosts = 0;
			DailySales = 0;
			DailyProfits = 0;
		}
			break;
		}

	} while (true);	

}

int Menu()
{
	cout << "\n"
		<< "Menu:\n"
		<< "1. Recieve a new batch of Widgets.\n"
		<< "2. Create a new order.\n"
		<< "3. Print remaining inventory.\n"
		<< "4. Print pending orders.\n"
		<< "5. Close orders for the day." << endl;

	int Choice = int(GetNum(true, "Choice =", 5));
	cout << endl;

	return Choice;
}

double GetNum(bool IsInteger, string Question, int Max)
{
	string A, B;
	double C;
	bool Valid = true;

	cout << Question << " ";
	getline(cin, A);										//input string
	B = A;

	if (B[0] == '-')
	{														//remove possible negative sign
		B.erase(0, 1);
	}

	size_t decimal = B.find('.');
	if (decimal != -1)
	{														//remove possible decimal point
		B.erase(decimal, 1);
	}

	for (unsigned int i = 0; i < B.size(); i++)
	{														//check if the remaining characters are digits
		if (!isdigit(B[i]))
		{
			cout << "Invalid input! Please input a numerical value." << endl;
			Valid = false;
			break;
		}
	}

	if (Valid)
	{														//string input is numeric, so convert to double
		C = stod(A);
	}

	if (Valid && IsInteger && (C - int(C) != 0))
	{														//verify if the input is an integer
		cout << "Invalid input! Please input an integer value." << endl;
		Valid = false;
	}

	if (Valid && C <= 0)
	{														//verify if the input is positive
		cout << "Invalid input! Please input a positive value." << endl;
		Valid = false;
	}

	if (Valid && Max > 0 && C > Max)
	{														//verify if the input is at most MAX
		cout << "Invalid input! Please enter a number less than or equal to " << Max << "." << endl;
		Valid = false;
	}

	if (!Valid)
	{														//recall function with same variables if invalid
		C = GetNum(IsInteger, Question, Max);
	}

	return C;
}