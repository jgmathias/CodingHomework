// Code for Project 5
// Airline Ticket 2/5

#include <iostream>
#include <iomanip>
#include <string>
//#include <cmath>
//#include <cassert>
#include <stdexcept>
#include "Ticket.h"

using namespace std;

Ticket::Ticket()
{
	mName = "";
	mFromCity = "";
	mToCity = "";
	mCost = 0;
}

Ticket::Ticket(string name, string fromCity, string toCity, double cost)
{
	if(name == "" || fromCity == "" || toCity == "" || cost <= 0)
	{
		throw(std::logic_error("blank info or cost not positive"));
	}
	else
	{
		mName = name;
		mFromCity = fromCity;
		mToCity = toCity;
		mCost = cost;
	}
}

string Ticket::getName()
{
	return mName;
}

string Ticket::getFromCity()
{
	return mFromCity;
}

string Ticket::getToCity()
{
	return mToCity;
}

double Ticket::getCost()
{
	return mCost;
}
		
void Ticket::setName(string name)
{
	if(name == "")
	{
		throw(std::logic_error("blank name"));
	}
	else
	{
		mName = name;
	}
}

void Ticket::setFromCity(string fromCity)
{
	if(fromCity == "")
	{
		throw(std::logic_error("blank fromCity"));
	}
	else
	{
		mFromCity = fromCity;
	}
}

void Ticket::setToCity(string toCity)
{
	if(toCity == "")
	{
		throw(std::logic_error("blank toCity"));
	}
	else
	{
		mToCity = toCity;
	}
}

void Ticket::setCost(double cost)
{
	if(cost <= 0)
	{
		throw(std::logic_error("zero or negative cost"));
	}
	else
	{
		mCost = cost;
	}
}