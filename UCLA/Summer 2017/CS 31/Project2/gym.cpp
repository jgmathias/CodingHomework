// Code for Project 2
// Gym Membership Fee Calculator

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	int TrainingsPerMonth;
	string MembershipType;
	
	cout << "Customer Name: ";
	getline (cin, name);
	cout << "Training Sessions per month: ";
	cin >> TrainingsPerMonth;
	cout << "Membership Type: ";
	cin >> MembershipType;
	
	if(name == "")
	{
		cout << "--- You must enter a customer name.";
	}
	else if(TrainingsPerMonth < 0)
	{
		cout << "--- The sessions used must not be negative.";
	}
	else if(MembershipType != "Regular" && MembershipType != "Executive")
	{
		cout << "--- The membership type is not valid.";
	}
	else
	{
		double initiation = 0;
		if(MembershipType == "Regular" && TrainingsPerMonth == 0)
			{initiation = 19.99;}
		
		int cost = 30; 
		if(MembershipType == "Executive")
			{cost += 25;} 		
		
		double fee = initiation + cost + 10*TrainingsPerMonth;
		
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "--- The membership fee for "<< name << " is $" << fee << endl;
	}
	
	return(0);
}