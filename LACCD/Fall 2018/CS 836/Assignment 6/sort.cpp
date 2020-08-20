//CS 836
//Assignment 6
//2 of 3

#include <iostream>
using namespace std;

#include "sort.h"

PersonList::PersonList()
{
	list[0] = NULL;
	size = 0;
}

PersonList :: ~PersonList()
{
	list[0] = NULL;
	size = 0;
}

void PersonList::ViewList()
{
	if (size == 0)
	{
		cout << endl;
		cout << "List is empty" << endl;
	}
	else
	{
		cout << endl;
		cout << "# Name Contribution" << endl;
		cout << "===================" << endl;
		
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << " " << list[i]->name << " $" << list[i]->bribe << endl;
		}
	}

	cout << endl;
	system("PAUSE");
}

void PersonList::BubbleSort()
{
	int n1 = size;
	PersonRec* temp = NULL;

	do
	{
		int n2 = 0;

		for (int i = 1; i <= n1 - 1; i++)
		{
			if (list[i - 1]->bribe < list[i]->bribe)
			{
				temp = list[i - 1];
				list[i - 1] = list[i];
				list[i] = temp;

				n2 = i;
			}
		}
		n1 = n2;
	} while (n1 > 1);
}

void PersonList::QuickSort()
{
	QS(list, 0, size - 1);
}

void PersonList::QS(PersonRec* List[], int Low, int High)
{
	if (Low < High)
	{
		int P = Partition(List, Low, High);
		QS(List, Low, P);
		QS(List, P + 1, High);
	}
}

int PersonList::Partition(PersonRec* List[], int Low, int High)
{
	PersonRec* pivot = List[Low];
	int i = Low - 1;
	int j = High + 1;

	PersonRec* temp = NULL;

	do
	{
		do
		{
			i++;
		} while (List[i]->bribe < pivot->bribe);

		do
		{
			j--;
		} while (List[j]->bribe > pivot->bribe);

		if (i >= j)
		{
			return j;
		}
		
		temp = List[i];
		List[i] = List[j];
		List[j] = temp;
	} while(true);
}

void PersonList::AddToList()
{
	string NAME;
	cout << endl;
	cout << "Enter the person's name: ";
	cin >> NAME;

	int BRIBE;
	cout << endl;
	cout << "Enter the person's contribution: ";
	cin >> BRIBE;

	PersonRec* NEW = new PersonRec;
	NEW->name = NAME;
	NEW->bribe = BRIBE;

	list[size] = NEW;
	size++;
}

bool PersonList::AtLeastTwo()
{
	if(size >= 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}