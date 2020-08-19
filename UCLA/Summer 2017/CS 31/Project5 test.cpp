// Code for Project 5
// Airline Ticket: all 5 parts

#include <iostream>
#include <iomanip>
#include <string>
//#include <cmath>
#include <cassert>
#include <stdexcept>

using namespace std;

// 1/5 Ticket.h

class Ticket
{
	
	public:
		Ticket();
		Ticket(string, string, string, double);
		
		string getName();
		string getFromCity();
		string getToCity();
		double getCost();
		
		void setName(string);
		void setFromCity(string);
		void setToCity(string);
		void setCost(double);
		
	private:
		string mName;
		string mFromCity;
		string mToCity;
		double mCost;
		
};

// 2/5 Ticket.cpp

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

// 3/5 TicketCounter.h

class TicketCounter
{
	
	public:
		TicketCounter();
		void issueTicket(string, string, string, int, bool, bool, bool);
	
};

// 4/5 TicketCounter.cpp

TicketCounter::TicketCounter()
{
	Ticket();
}

void TicketCounter::issueTicket(string name, string fromCity, string toCity, int numberOfHops, bool weekendTravel, bool fourteenDaysinAdvance, bool firstClass)
{
	double cost = 100;
	if (firstClass == 1)
	{
		cost += 400;
	}
	if (numberOfHops == 0)
	{
		cost *= 1.1;
	}
	if (weekendTravel == 1)
	{
		cost *= 0.8;
	}
	if (fourteenDaysinAdvance == 1)
	{
		cost *= 0.75;
	}
	
	Ticket(name, fromCity, toCity, cost);
}

// 5/5 main.cpp

int main()
{
	
	Ticket t( "Howard", "Los Angeles", "New York", 100.0 );
		assert( t.getName() == "Howard" );
		assert( t.getFromCity() == "Los Angeles" );
		assert( t.getToCity() == "New York" );
		assert( t.getCost() == 100.0 );
	
	try
	{
		t.setName( "" );
		assert( false );  
	}
	catch(std::logic_error)
	{
		assert( true );
	}
	
	try
	{
		t.setFromCity( "" );
		assert( false );  
	}
	catch(std::logic_error)
	{
		assert( true );
	}
	
	try
	{
		t.setToCity( "" );
		assert( false );  
	}
	catch(std::logic_error)
	{
		assert( true );
	}
	
	try
	{
		t.setCost( -100.00 );
		assert( false );  
	}
	catch(std::logic_error)
	{
		assert( true );
	}
           
	TicketCounter counter;
		t = counter.issueTicket( "Howard", "Los Angeles", "Sacramento", 2, false, false, true );
			assert( t.getCost() == 500.00 );
		t = counter.issueTicket( "Howard", "Los Angeles", "Sacramento", 0, false, false, true );
			assert( t.getCost() == 550.00 );
		t = counter.issueTicket( "Howard", "Los Angeles", "Sacramento", 2, false, false, false );
			assert( t.getCost() == 100.00 );
		t = counter.issueTicket( "Howard", "Los Angeles", "Sacramento", 0, false, false, false );
			assert( t.getCost() == 110.00 );
		t = counter.issueTicket( "Howard", "Los Angeles", "Sacramento", 2, true, false, true );
			assert( t.getCost() == 400.00 );
		t = counter.issueTicket( "Howard", "Los Angeles", "Sacramento", 2, true, false, false );
			assert( t.getCost() == 80.00 );
		t = counter.issueTicket( "Howard", "Los Angeles", "Sacramento", 0, true, false, true );
			assert( t.getCost() == 440.00 );
		t = counter.issueTicket( "Howard", "Los Angeles", "Sacramento", 0, true, false, false );
			assert( t.getCost() == 88.00 );
		t = counter.issueTicket( "Howard", "Los Angeles", "Sacramento", 0, true, true, true );
			assert( t.getCost() == 330.00 );
		t = counter.issueTicket( "Howard", "Los Angeles", "Sacramento", 0, true, true, false );
			assert( t.getCost() == 66.00 );
	
	cout << "all tests passed!" << endl;
    return 0;
}