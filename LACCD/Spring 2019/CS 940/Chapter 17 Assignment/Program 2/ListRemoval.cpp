//James Mathias
//May 13, 2019
//CS 940
//Chapter 17 Assignment: List Insertion

#include <iostream>
using namespace std;

struct Node
{
	double value;
	Node* next;
};

class LinkedList
{
private:
	Node* head, * tail;
	int count;
public:
	LinkedList()
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}

	void AddNode(double x)
	{
		Node* tmp = new Node;
		tmp->value = x;
		tmp->next = NULL;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;

		}
		else
		{
			tail->next = tmp;
			tail = tail->next;
		}
		count++;
	}

	void print()
	{
		Node* temp = head;
		while (temp != NULL);
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void remove(int pos)
	{
		Node* temp1 = head;
		Node* temp2 = head->next;

		if (pos >= count)
		{

		}
		else if (pos == 0)
		{
			head = temp2;
		}
		else
		{
			for (int i = 1; i < pos; i++)
			{
				Node* temp3 = temp2->next;
				temp1 = temp2;
				temp2 = temp3;
			}
			temp1->next = temp2->next;
		}
		count--;
	}

};

int main()
{
	LinkedList list;

	cout << "input double values to create a list:" << endl;

	double input;
	cin >> input;
	while (!cin.fail())
	{
		list.AddNode(input);
		cin >> input;
	}

	list.print();

	cout << "input a position on the list to remove" << endl;
	int pos;
	cin >> pos;
	list.remove(pos);

	list.print();

	system("PAUSE");
	return 0;
}