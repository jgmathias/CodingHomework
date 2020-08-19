/*
Homework #7
Author: James Mathias
Email: jgmathias@g.ucla.edu
Course: PIC 10A Summer 2017
Collaborators: N/A

Honesty Pledge:
I, James Mathias, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.

User inputs: purchase info of a person
Output: success or failure of purchases based on credit limit
List of known bugs: none
*/

#include <iostream>
#include <iomanip>
#include <string>
//#include <cmath>
//#include <cstdlib>
//#include <ctime>
//#include <vector>

using namespace std;

class Customer
{
	private:
		string name;
		int limit;
		double balance;
		int items;
		
	public:
		Customer();
		Customer(string, int);
		string get_name();
		int get_limit();
		bool add_purchase(double);
		double get_balance();
		int get_num_purchases();
	
};

Customer::Customer()
{
	name = "John Doe";
	limit = 1500;
	balance = limit;
	items = 0;
}

Customer::Customer(string a, int b)
{
	name = a;
	limit = b;
	balance = limit;
	items = 0;
}

bool Customer::add_purchase(double val)
{
	val *= 100;
	int temp = val;
	val = temp / 100.0;
	
	if(val <= balance && val > 0)
	{
		balance = balance - val;
		items++;
		return 1;
	}
	else
	{
		return 0;
	}
}

string Customer::get_name()
{
	return name;
}

int Customer::get_limit()
{
	return limit;
}

double Customer::get_balance()
{
	return balance;
}

int Customer::get_num_purchases()
{
	return items;
}

int main ()
{
	cout.setf(ios::fixed);
	cout.precision(2);
	
	string a;
	int b;
	
	cout << "Customer: ";
	getline(cin, a);
	cout << "Credit Limit: $";
	cin >> b;
	
	Customer x(a, b);
	
	char again;
	do
	{
		double value;
		cout << "Purchase value: $";
		cin >> value;
		
		bool b = x.add_purchase(value);
		if(b == 1)
		{
			cout << "Purchase successful." << endl;
		}
		else
		{
			cout << "Purchase failed. Not enough credit or invalid amount entered." << endl;
		}
		
		cout << "Purchase another item? (y/n) ";
		cin >> again;
	}
	while(again == 'y');
	
	cout << "The total of " << x.get_num_purchases() << " purchase(s) for " << x.get_name() << " is $" << x.get_limit() - x.get_balance() << "."<< endl;
	
	return 0;
}