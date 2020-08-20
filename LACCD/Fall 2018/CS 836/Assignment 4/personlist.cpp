//CS 836
//Assignment 4
//2 of 3

#include <iostream>
using namespace std;

#include "personlist.h"

PersonList :: PersonList()
{
	head = NULL;
}

PersonList :: ~PersonList()
{
	head = NULL;
}

void PersonList :: ViewList()
{
	if (head == NULL)
	{
		cout << endl;
		cout << "List is empty" << endl;
	}
	else
	{
		cout << endl;
		cout << "# Name Contribution" << endl;
		cout << "=======================================" << endl << endl;

		int i = 1;
		PersonRec* temp = head;

		while (temp != NULL)
		{
			cout << i << " " << temp->name << " $" << temp->bribe << endl;
			temp = temp->next;
			i++;
		}
	}
}

void PersonList :: AddToList()
{
	string NAME;
	cout << "Enter the person's name: ";
	getline(cin, NAME);

	int BRIBE;
	cout << "Enter the person's contribution: ";
	cin >> BRIBE;

	PersonRec* NEW = new PersonRec;
	NEW->name = NAME;
	NEW->bribe = BRIBE;
	NEW->next = NULL;

	if (head == NULL)
	{
		head = NEW;
	}
	else
	{
		if (NEW->bribe > head->bribe)
		{
			NEW->next = head;
			head = NEW;
		}
		else
		{
			PersonRec* lasttemp = head;
			PersonRec* temp = head->next;
			while (lasttemp->next != NULL)
			{
				if (NEW->bribe > temp->bribe)
				{
					lasttemp->next = NEW;
					NEW->next = temp;
					break;
				}
				lasttemp = lasttemp->next;
				temp = temp->next;
			}
			if (lasttemp->next == NULL)
			{
				lasttemp->next = NEW;
			}
		}
	}
}