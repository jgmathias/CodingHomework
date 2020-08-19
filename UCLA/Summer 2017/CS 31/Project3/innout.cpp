// Code for Project 3
// In-n-Out Burger Cost Calculator

#include <iostream>
//#include <iomanip>
#include <string>
//#include <cmath>
using namespace std;

bool isValidOrderString(string orders)
{
	bool b = 1;
	
	int order1 = 0;
	int order2 = 0;
	int order3 = 0;
	int n = 0;
	
	for(unsigned int i = 0; i <= orders.length(); i++)
	{
		if(orders[i] >= '0' && orders[i] <= '9')
		{
			n = 10 * n + int(orders[i] - 48);
		}
		else if(orders[i] == ':')
		{
			if(n == 0)
			{
				//cout << "error: zero or blank not valid for quantity field" << endl;
				b = 0;
				break;
			}
			
			i++;
			
			if(orders[i] == '1')
			{
				order1 += n;
			}
			else if(orders[i] == '2')
			{
				order2 += n;
			}
			else if(orders[i] == '3')
			{
				order3 += n;
			}
			else
			{
				//cout << "error: invalid character in item field" << endl;
				b = 0;
				break;
			}
			
			n = 0;
			i++;
			
			if(i < orders.length() && orders[i] != '_')
			{
				//cout << "error: invalid character in place of underscore" << endl;
				b = 0;
				break;
			}
			else if(i + 1 == orders.length() && orders[i] == '_')
			{
				//cout << "error: last character can not be underscore" << endl;
				b = 0;
				break;
			}
		}
		else
		{
			//cout << "error: invalid character in quantity field" << endl;
			b = 0;
			break;
		}
	}
	
	if(order1 + order2 + order3 > 50)
	{
		//cout << "error: orders limited to 50" << endl;
		b = 0;
	}
	
	//cout << order1 << " " << order2 << " " << order3 << " " << n << " " << b << endl;
	
	return(b);
}

double cost(string orders)
{
	//bool b = 1;
	
	int order1 = 0;
	int order2 = 0;
	int order3 = 0;
	int n = 0;
	
	for(unsigned int i = 0; i <= orders.length(); i++)
	{
		if(orders[i] >= '0' && orders[i] <= '9')
		{
			n = 10 * n + int(orders[i] - 48);
		}
		else if(orders[i] == ':')
		{
			/*if(n == 0)
			{
				cout << "error: zero or blank not valid for quantity field" << endl;
				b = 0;
				break;
			}*/
			
			i++;
			
			if(orders[i] == '1')
			{
				order1 += n;
			}
			else if(orders[i] == '2')
			{
				order2 += n;
			}
			else if(orders[i] == '3')
			{
				order3 += n;
			}
			/*else
			{
				cout << "error: invalid character in item field" << endl;
				b = 0;
				break;
			}*/
			
			n = 0;
			i++;
			
			/*if(i < orders.length() && orders[i] != '_')
				{
					cout << "error: invalid character in place of underscore" << endl;
					b = 0;
					break;
				}
			else if(i + 1 == orders.length() && orders[i] == '_')
				{
					cout << "error: last character can not be underscore" << endl;
					b = 0;
					break;
				}*/
		}
		/*else
		{
			cout << "error: invalid character in quantity field" << endl;
			b = 0;
			break;
		}*/
	}
	
	/*if(order1 + order2 + order3 > 50)
	{
		cout << "error: orders limited to 50" << endl;
		b = 0;
	}*/
	
	//cout << order1 << " " << order2 << " " << order3 << " " << n << " " << b << endl;
	
	double cost = order1 * 7.40 + order2 * 6.25 + order3 * 5.95;
	return(cost);
}

int main()
{
	string order;
	cout << "Enter order: ";
	getline(cin, order);
	
	if (order == "quit")
	{
	}
	else
	{
		bool a = isValidOrderString(order);
		if(a == 1)
		{
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "This order costs $" << cost(order) << "." << endl;
		}
		else
		{
			cout << "Order is invalid." << endl;
		}
	}
	return(0);
}