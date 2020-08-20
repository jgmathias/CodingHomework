//CS 840
//Assignment 2
//3 of 5

#include <iostream>
#include <vector>

#include "Fraction.h"

class FracList
{

private:
	vector<Fraction> list;
	int size;

public:

	FracList(int = 0);
	~FracList();
	FracList(FracList&);
	Fraction getFrac(int);
	void setFrac(Fraction, int);
	void display();
	void operator =(FracList&);
	bool operator <(FracList&);
	bool operator <=(FracList&);
	bool operator >(FracList&);
	bool operator >=(FracList&);
	bool operator ==(FracList&);
	bool operator !=(FracList&);
	void operator <<(FracList&);
	void operator >>(FracList&);
	FracList resize1(int);
	void resize2(int);
	void sort();
	void swap(int, int);
	void search(Fraction&);
};
