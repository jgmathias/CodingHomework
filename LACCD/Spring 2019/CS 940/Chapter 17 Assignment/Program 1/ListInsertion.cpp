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

	void insert(double x, int pos)
	{
		Node* tmp = new Node;
		tmp->value = x;
		tmp->next = NULL;

		if (pos >= count)
		{
			tail->next = tmp;
			tail = tail->next;
		}
		else if (pos == 0)
		{
			tmp->next = head;
			head = tmp;
		}
		else
		{
			Node* temp = head;
			for (int i = 1; i < pos; i++)
			{
				temp = temp->next;
			}
			tmp->next = temp->next;
			temp->next = tmp;
		}
		count++;
	}

};

int main()
{
	LinkedList list;

	cout << "input double values to create a list:" << endl;

	double input;
	cin >> input;
	while(!cin.fail())
	{
		list.AddNode(input);
		cin >> input;
	}

	list.print();

	cout << "\ninput a double value to insert into the middle of the list" << endl;
	cin >> input;
	cout << "input a position on the list" << endl;
	int pos;
	cin >> pos;
	list.insert(input, pos);

	list.print();

	system("PAUSE");
	return 0;
}