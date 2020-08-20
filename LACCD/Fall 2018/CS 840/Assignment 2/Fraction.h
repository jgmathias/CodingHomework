//CS 840
//Assignment 2
//1 of 5

#include <iostream>
#include <cstring>
using namespace std;

class Fraction
{

private:
	int num, den;
	void reduce();

public:
	Fraction(int = 0, int = 1);
	~Fraction();
	void display();
	void operator =(Fraction&);
	bool operator <(Fraction&);
	bool operator <=(Fraction&);
	bool operator >(Fraction&);
	bool operator >=(Fraction&);
	bool operator ==(Fraction&);
	bool operator !=(Fraction&);
	Fraction operator +(Fraction&);
	void operator +=(Fraction&);
	Fraction operator -(Fraction&);
	void operator -=(Fraction&);
	Fraction operator *(Fraction&);
	void operator *=(Fraction&);
	Fraction operator /(Fraction&);
	void operator /=(Fraction&);
	void operator <<(Fraction&);
	void operator >>(Fraction&);
	
};
