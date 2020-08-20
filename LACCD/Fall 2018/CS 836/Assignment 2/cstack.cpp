//CS 836
//Assignment 2
//2 of 3

#include <iostream>
using namespace std;

#include "cstack.h"

CStack::CStack()
{
	top = -1;
}

bool CStack::IsEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CStack::IsFull()
{
	if (top == 19)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CStack::Push(char Char)
{
	data[top + 1] = Char;
	top += 1;
}

void CStack::Pop()
{
	top -= 1;
}

char CStack::Top()
{
	return data[top];
}