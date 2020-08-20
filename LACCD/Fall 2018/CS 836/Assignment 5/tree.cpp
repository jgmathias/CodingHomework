//CS 836
//Assignment 5
//2 of 3

#include <iostream>
using namespace std;

#include "tree.h"

PersonTree::PersonTree()
{
	root = NULL;
}

PersonTree :: ~PersonTree()
{
	root = NULL;
}

void PersonTree::ViewTree()
{
	if (root == NULL)
	{
		cout << endl;
		cout << "List is empty" << endl;
	}
	else
	{
		cout << endl;
        cout << "# Name Contribution" << endl;
		cout << "=======================================" << endl;

		int i = 1;
		
		recursion(root, i);
	}
}

int PersonTree::recursion(PersonRec* node, int Count)
{
	int i = Count;

	if (node->childMore != NULL)
	{
		i = recursion(node->childMore, i);
	}

	cout << i << " " << node->name << " $" << node->bribe << endl;
	i++;

	if (node->childLess != NULL)
	{
		i = recursion(node->childLess, i);
	}

	return i;
}

void PersonTree::AddToTree()
{
	string NAME;
	cout << endl;
	cout << "Enter the person's name: ";
	getline(cin, NAME);

	int BRIBE;
	cout << endl;
	cout << "Enter the person's contribution: ";
	cin >> BRIBE;

	PersonRec* NEW = new PersonRec;
	NEW->name = NAME;
	NEW->bribe = BRIBE;
	NEW->childLess = NULL;
	NEW->childMore = NULL;

	if (root == NULL)
	{
		root = NEW;
	}
	else
	{
		PersonRec* temp = root;

		while (temp != NULL)
		{
			if (NEW->bribe < temp->bribe)
			{
				if (temp->childLess == NULL)
				{
					temp->childLess = NEW;
					break;
				}
				else
				{
					temp = temp->childLess;
				}
			}
			else if (NEW->bribe > root->bribe)
			{
				if (temp->childMore == NULL)
				{
					temp->childMore = NEW;
					break;
				}
				else
				{
					temp = temp->childMore;
				}
			}
			else
			{
				cout << endl;
				cout << "This bribe amount has already been paid." << endl;
				break;
			}
		}
	}
}