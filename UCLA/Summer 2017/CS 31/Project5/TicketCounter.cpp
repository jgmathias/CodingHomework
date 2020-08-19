// Code for Project 5
// Airline Ticket 4/5

#include <iostream>
#include <iomanip>
#include <string>
//#include <cmath>
//#include <cassert>
#include "TicketCounter.h"
#include "Ticket.h"

using namespace std;

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