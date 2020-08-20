//CS 840
//Assignment 2
//2 of 5

#include "Fraction.h"

Fraction :: Fraction(int Num, int Den) : num(Num), den(Den)
{
	reduce();
}

Fraction :: ~Fraction()
{
	this->num = 0;
	this->den = 1;
}

void Fraction :: display()
{
	cout << num << '/' << den;
}

void Fraction :: reduce()
{
	int u = this->num;
	int v = this->den;

	while (v != 0)
	{
		int r = u % v;
		u = v;
		v = r;
	}

	this->num /= u;
	this->den /= u;
}

void Fraction :: operator =(Fraction& f2)
{
	this->num = f2.num;
	this->den = f2.den;
}

bool Fraction :: operator <(Fraction& f2)
{
	this->num *= f2.den;
	f2.num *= this->den;

	if (this->num < f2.num)
	{
		this->num /= f2.den;
		f2.num /= this->den;
		return true;
	}
	else
	{
		this->num /= f2.den;
		f2.num /= this->den;
		return false;
	}
}

bool Fraction :: operator <=(Fraction& f2)
{
	this->num *= f2.den;
	f2.num *= this->den;

	if (this->num <= f2.num)
	{
		this->num /= f2.den;
		f2.num /= this->den;
		return true;
	}
	else
	{
		this->num /= f2.den;
		f2.num /= this->den;
		return false;
	}
}

bool Fraction :: operator >(Fraction& f2)
{
	this->num *= f2.den;
	f2.num *= this->den;

	if (this->num > f2.num)
	{
		this->num /= f2.den;
		f2.num /= this->den;
		return true;
	}
	else
	{
		this->num /= f2.den;
		f2.num /= this->den;
		return false;
	}
}

bool Fraction :: operator >=(Fraction& f2)
{
	this->num *= f2.den;
	f2.num *= this->den;

	if (this->num >= f2.num)
	{
		this->num /= f2.den;
		f2.num /= this->den;
		return true;
	}
	else
	{
		this->num /= f2.den;
		f2.num /= this->den;
		return false;
	}
}

bool Fraction :: operator ==(Fraction& f2)
{
	if (this->den == f2.den)
	{
		if (this->num == f2.num)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Fraction :: operator !=(Fraction& f2)
{
	if (this->den == f2.den)
	{
		if (this->num == f2.num)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return true;
	}
}

Fraction Fraction :: operator +(Fraction& f2)
{
	Fraction fsum;
	fsum.num = (this->num * f2.den) + (f2.num * this->den);
	fsum.den = this->den * f2.den;
	fsum.reduce();
	return fsum;
}

void Fraction :: operator +=(Fraction& f2)
{
	Fraction fsum;
	fsum.num = (this->num * f2.den) + (f2.num * this->den);
	fsum.den = this->den * f2.den;
	fsum.reduce();
	this->num = fsum.num;
	this->den = fsum.den;
}

Fraction Fraction :: operator -(Fraction& f2)
{
	Fraction fdif;
	fdif.num = (this->num * f2.den) - (f2.num * this->den);
	fdif.den = this->den * f2.den;
	fdif.reduce();
	return fdif;
}

void Fraction :: operator -=(Fraction& f2)
{
	Fraction fdif;
	fdif.num = (this->num * f2.den) - (f2.num * this->den);
	fdif.den = this->den * f2.den;
	fdif.reduce();
	this->num = fdif.num;
	this->den = fdif.den;
}

Fraction Fraction :: operator *(Fraction& f2)
{
	Fraction fpro;
	fpro.num = this->num * f2.num;
	fpro.den = this->den * f2.den;
	fpro.reduce();
	return fpro;
}

void Fraction :: operator *=(Fraction& f2)
{
	Fraction fpro;
	fpro.num = this->num * f2.num;
	fpro.den = this->den * f2.den;
	fpro.reduce();
	this->num = fpro.num;
	this->den = fpro.den;
}

Fraction Fraction :: operator /(Fraction& f2)
{
	Fraction fdiv;
	fdiv.num = this->num * f2.den;
	fdiv.den = this->den * f2.num;
	fdiv.reduce();
	return fdiv;
}

void Fraction :: operator /=(Fraction& f2)
{
	Fraction fdiv;
	fdiv.num = this->num * f2.den;
	fdiv.den = this->den * f2.num;
	fdiv.reduce();
	this->num = fdiv.num;
	this->den = fdiv.den;
}

void Fraction :: operator <<(Fraction& f)
{
	display();
}

void Fraction :: operator >>(Fraction& f)
{
	char slash = '/';
	cin >> num >> slash >> den;
	reduce();
}