//James Mathias
//Mar 10, 2019
//CS 940
//Chapter 8-9 Assignment: Drink(1 of 2) - Class 
//create a class that simulates a drink machine

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct DrinkInfo
{
	string name;
	double price = 1;
	int quantity = 20;
};

class DrinkMachine
{
private:
	double Sales;
	DrinkInfo Drinks[5];
	double InputMoney();
	void DailyReport();

public:
	DrinkMachine();
	~DrinkMachine();
	void DisplayChoices();
	void BuyDrink();
};

DrinkMachine::DrinkMachine()
{
	Sales = 0;
	
	Drinks[0].name = "Cola";
	Drinks[1].name = "Root Beer";
	Drinks[2].name = "Orange Soda";
	Drinks[3].name = "Grape Soda";
	Drinks[4].name = "Bottled Water";

	Drinks[4].price = 1.5;
}

DrinkMachine::~DrinkMachine()
{
	DailyReport();
}

void DrinkMachine::DisplayChoices()
{
	if (Drinks[0].quantity + Drinks[1].quantity + Drinks[2].quantity + Drinks[3].quantity + Drinks[4].quantity == 0)
	{
		cout << "No more drinks are available." << endl;
		return;
	}
	
	cout << "The following drinks are available:" << endl;
	for (int i = 0; i < 5; i++)
	{
		if (Drinks[i].quantity > 0)
		{
			cout << i + 1 << ". " << setw(13) << left << Drinks[i].name << " $" << fixed << setprecision(2) << Drinks[i].price << endl;
		}
	}
}

void DrinkMachine::BuyDrink()
{
	if (Drinks[0].quantity + Drinks[1].quantity + Drinks[2].quantity + Drinks[3].quantity + Drinks[4].quantity == 0)
	{
		cout << "No more drinks are available.";
		return;
	}

	double money;
	money = InputMoney();
	if (money == 0)
	{
		return;
	}

	int choice;
	cout << "Enter a drink choice or enter 0 to exit: ";
	cin >> choice;
	if (choice == 0)
	{
		choice = 1;
		money = 0;
	}
	while (choice < 1 || choice > 5 || Drinks[choice - 1].quantity == 0)
	{
		cout << "Enter a different drink choice: ";
		cin >> choice;
		if (choice == 0)
		{
			choice = 1;
			money = 0;
		}
	}
	
	if (money < Drinks[choice - 1].price)
	{
		cout << "Returning inputed money." << endl;
		
		cout << "Attempt another order? Y/N: ";
	}
	else if(money >= Drinks[choice - 1].price)
	{
		if (money > Drinks[choice - 1].price)
		{
			cout << "Returning $" << fixed << setprecision(2) << money - Drinks[choice - 1].price << "." << endl;
		}
		Sales += Drinks[choice - 1].price;
		Drinks[choice - 1].quantity--;
		cout << "Dispensing "<< Drinks[choice - 1].name <<". Enjoy your drink!" << endl;
		
		cout << "Order another drink? Y/N: ";
	}

	char another;
	cin >> another;
	if (toupper(another) == 'Y')
	{
		cout << "Display available drinks? Y/N: ";
		char display;
		cin >> display;
		if (toupper(display) == 'Y')
		{
			cout << endl;
			DisplayChoices();
			
		}
		cout << endl;
		BuyDrink();
	}
}

double DrinkMachine::InputMoney()
{
	double Money;
	cout << "Input at least $1 to buy or $0 to exit: $";
	cin >> Money;
	if (Money == 0)
	{
		return 0;
	}
	while (Money < 1)
	{
		double More;
		cout << "Input more money: $";
		cin >> More;
		if (More == 0)
		{
			return 0;
		}
		Money += More;
	}

	return Money;
}

void DrinkMachine::DailyReport()
{
	cout << "The following drinks are remaining:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ". " << setw(13) << left << Drinks[i].name << setw(3) << right << Drinks[i].quantity << endl;
	}
	cout << "The total sales for today is: $" << fixed << setprecision(2) << Sales << endl;
}