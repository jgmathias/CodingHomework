//CS 840
//Assignment 2
//4 of 5

#include "FracList.h"

inline FracList :: FracList(int Size)
{
	size = Size;
	for (int i = 1; i <= size; i++)
	{
		list.push_back(Fraction());
	}
}

FracList :: ~FracList()
{
	size = 0;
	list.resize(size);
}

FracList :: FracList(FracList& Copy)
{
	list = Copy.list;
	size = Copy.size;
}

Fraction FracList :: getFrac(int i)
{
	return list[i];
}

void FracList :: setFrac(Fraction f, int i)
{
	list[i] = f;
}

void FracList :: display()
{
	for (int i = 0; i < size; i++)
	{
		list[i].display();
		cout << " ";
	}
	cout << endl;
}

void FracList :: operator =(FracList& fl2)
{
	this->size = fl2.size;
	this->list = fl2.list;
}

bool FracList :: operator <(FracList& fl2)
{
	if (this->size < fl2.size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FracList :: operator <=(FracList& fl2)
{
	if (this->size <= fl2.size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FracList :: operator >(FracList& fl2)
{
	if (this->size > fl2.size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FracList :: operator >=(FracList& fl2)
{
	if (this->size >= fl2.size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FracList :: operator ==(FracList& fl2)
{
	if (this->size == fl2.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (this->list[i] == fl2.list[i])
			{

			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

bool FracList :: operator !=(FracList& fl2)
{
	if (this->size == fl2.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (this->list[i] == fl2.list[i])
			{

			}
			else
			{
				return true;
			}
		}
	}
	else
	{
		return true;
	}

	return false;
}

void FracList :: operator <<(FracList& fl)
{
	display();
}

void FracList :: operator >>(FracList& fl)
{
	int a, b;
	char slash = '/';

	for (int i = 0; i < size; i++)
	{
		cin >> a >> slash >> b;
		Fraction f(a, b);
		list[i] = f;
	}
}

FracList FracList :: resize1(int newSize)
{
	int dif = size - newSize;
	FracList leftover(dif);

	if (dif > 0)
	{
		for (int i = 0; i < dif; i++)
		{
			leftover.list[i] = this->list[newSize + i];
		}

		this->size = newSize;
		this->list.resize(size);
	}
	else
	{
		for (int i = -1; i >= dif; i--)
		{
			this->list.push_back(Fraction());
		}
	}

	return leftover;
}

void FracList :: resize2(int newSize)
{
	size = newSize;
	list.resize(size);
}

void FracList::sort()
{
	for (int i = 1; i < size; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (list[j - 1] > list[j])
			{
				swap(j - 1, j);
			}
			else
			{
				break;
			}
		}
	}
}

void FracList :: swap(int i, int j)
{
	Fraction ftemp = list[i];
	list[i] = list[j];
	list[j] = ftemp;
}

void FracList :: search(Fraction& fsearch)
{
	int Found = -1;

	unsigned int First = 0;
	unsigned int Last = size - 1;
	unsigned int Middle = Last / 2;

	if (list[First] == fsearch)
	{
		Found = First;
	}
	else if (list[Last] == fsearch)
	{
		Found = Last;
	}
	else
	{
		while (list[Middle] != fsearch && First != Middle)
		{
			if (list[Middle] > fsearch)
			{
				Last = Middle;
			}
			else
			{
				First = Middle;
			}
			Middle = (First + Last) / 2;
		}

		if (list[Middle] == fsearch)
		{
			Found = Middle;
		}
	}

	if (Found >= 0)
	{
		fsearch.display();
		cout << " was found at index " << Found << endl;
	}
	else
	{
		cout << "Fraction was not found in this list." << endl;
	}
}