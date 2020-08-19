// Code for Project 5
// Airline Ticket 5/5

#include <iostream>
#include <iomanip>
#include <string>
//#include <cmath>
#include <cassert>
#include <stdexcept>
#include "Ticket.cpp"
#include "TicketCounter.cpp"

using namespace std;

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