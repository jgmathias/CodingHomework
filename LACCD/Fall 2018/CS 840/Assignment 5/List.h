//James Mathias
//CS 840
//Assignment 5
//2 of 3
//Dec 2, 2018

#include <iostream>
using namespace std;

template <class temp>
class List
{
private:
	int size;
	temp ptr[10];

public:
	List(int s = 0, temp pointer[] = NULL)
	{
		
	}

	List(const List& l) : size(l.size)
	{
		ptr = new temp[size];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = l.ptr[i];
		}
	}

	int get_size() const
	{
		return size;
	}

	const List& operator=(const List& l)
	{

	}

	temp operator[](int index)
	{
		return ptr[index];
	}

	~List()
	{
		delete ptr;
	}

};