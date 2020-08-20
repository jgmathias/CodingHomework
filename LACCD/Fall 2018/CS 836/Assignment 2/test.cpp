//CS 836
//Assignment 2
//3 of 3

#include <iostream>
#include <cstring>
using namespace std;

#include "cstack.h"

bool isValid(CStack&, char*);

int main(void)    
{
	char expression[20];    
	
	cout << "Enter an expression: ";
	cin >> expression;
	cout << endl;
	
	do
	{
		CStack stack;

		if (isValid(stack, expression))
		{
			cout << "It's a valid expression" << endl;
		}
		else
		{
			cout << "It's NOT a valid expression" << endl;
		}

		cout << "Enter an expression: ";
		cin >> expression;
		cout << endl;
	} while (expression[0] != 'q');
	
	system("PAUSE");
	return 0;
}

bool isValid(CStack& Stack, char* Expression)
{
	for (int i = 0; i < 20; i++)
	{
		if (Expression[i] == '{' || Expression[i] == '[' || Expression[i] == '(')
		{
			Stack.Push(Expression[i]);
		}
		else if ((Expression[i] == '}' || Expression[i] == ']' || Expression[i] == ')') && Stack.IsEmpty())
		{
			return false;
		}
		else if (Expression[i] == '}' && Stack.Top() == '{')
		{
			Stack.Pop();
		}
		else if (Expression[i] == ']' && Stack.Top() == '[')
		{
			Stack.Pop();
		}
		else if (Expression[i] == ')' && Stack.Top() == '(')
		{
			Stack.Pop();
		}
		else if (Stack.IsEmpty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}