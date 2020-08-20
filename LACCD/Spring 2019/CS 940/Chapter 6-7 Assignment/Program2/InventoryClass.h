//James Mathias
//Mar 2, 2019
//CS 940
//Chapter 6-7 Assignment: Inventory(1 of 2) - Class 
//create a class that can hold information for an item in a retail store’s inventory

#include <iostream>
#include <string>
using namespace std;

class Inventory
{
protected:
	int ItemNumber;
	int Quantity;
	double Cost;

public:
	Inventory(int = 0, int = 0, double = 0);
	void setItemNumber(int = 0);
	void setQuantity(int = 0);
	void setCost(double = 0);
	int getItemNumber();
	int getQuantity();
	double getCost();
	double getTotalCost();
	double getPosNum(double, string);
};

Inventory::Inventory(int itemnumber, int quantity, double cost)
{
	setItemNumber(itemnumber);
	setQuantity(quantity);
	setCost(cost);
}

void Inventory::setItemNumber(int itemnumber)
{
	double Num = getPosNum(itemnumber, "Item Number");
	while (Num - int(Num) != 0)
	{
		double num;
		cout << "Invalid Item Number. Enter an integer: ";
		cin >> num;
		Num = getPosNum(num, "Item Number");
	}
	ItemNumber = Num;
}

void Inventory::setQuantity(int quantity)
{
	double Num = getPosNum(quantity, "Quantity");
	while (Num - int(Num) != 0)
	{
		double num;
		cout << "Invalid Quantity. Enter an integer: ";
		cin >> num;
		Num = getPosNum(num, "Quantity");
	}
	Quantity = Num;
}

void Inventory::setCost(double cost)
{
	double Num = getPosNum(cost, "Cost");
	Cost = Num;
}

int Inventory::getItemNumber()
{
	return ItemNumber;
}

int Inventory::getQuantity()
{
	return Quantity;
}

double Inventory::getCost()
{
	return Cost;
}

double Inventory::getTotalCost()
{
	double TotalCost = Quantity * Cost;
	return TotalCost;
}

double Inventory::getPosNum(double input, string str)
{
	double num = input;

	while (num < 0)
	{
		cout << "Invalid " << str << ". Enter a positive number: ";
		cin >> num;
	}

	return num;
}