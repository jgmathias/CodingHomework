// Code for Project 5
// Airline Ticket 1/5

#include <iostream>
#include <iomanip>
#include <string>
//#include <cmath>
//#include <cassert>

using namespace std;

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