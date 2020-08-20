//James Mathias
//CS 840
//Midterm
//3 of 4
//Nov 9, 2018

#include <iostream>
using namespace std;

#include "hDate.h"

class hDateArray
{
private:
	int size;
	hDate* DateArray[100];
	hDate* ptr;
public:
	hDateArray(int = 1);
	~hDateArray();
	void input();
	void output();
};

hDateArray::hDateArray(int s)
{
	for (int i = 0; i < s; i++)
	{
		hDate* hd = new hDate;
		DateArray[i] = hd;
	}
}

hDateArray::~hDateArray()
{

}

void hDateArray::input()
{
	for (int i = 0; i < size; i++)
	{
		DateArray[i] >> DateArray[i];
	}
}

void hDateArray::output()
{
	for (int i = 0; i < size; i++)
	{
		DateArray[i] << DateArray[i];
	}
}