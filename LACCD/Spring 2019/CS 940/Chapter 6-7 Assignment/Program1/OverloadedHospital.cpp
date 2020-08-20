//James Mathias
//Mar 2, 2019
//CS 940
//Chapter 6-7 Assignment: Overloaded Hospital
//computes and displays the charges for a patient’s hospital stay by using overloaded functions

#include <iostream>
#include <string>
using namespace std;

double getPosNum();
double Cost(double days, double rate, double services, double meds);
double Cost(double services, double meds);

int main()
{
	string Type = "";
	cout << "In-Patient or Out-Patient: ";
	cin >> Type;
	int i = 0;
	while (Type[i])
	{
		char c = Type[i];
		Type[i] = toupper(c);
		i++;
	}
	while (Type != "IN" and Type != "OUT")
	{
		cout << "Enter \"IN\" or \"OUT\": ";
		cin >> Type;
		int i = 0;
		while (Type[i])
		{
			char c = Type[i];
			Type[i] = toupper(c);
			i++;
		}
	}
	
	double Days;
	double Rate;
	double Services;
	double Meds;

	if (Type == "IN")
	{
		cout << "Number of days spent in the hospital: ";
		Days = getPosNum();
		
		cout << "Daily Rate: $";
		Rate = getPosNum();
	}
	
	cout << "Charges for hospital services: $";
	Services = getPosNum();
	
	cout << "Charges for medications: $";
	Meds = getPosNum();
	
	double cost;

	if (Type == "IN")
	{
		cost = Cost(Days, Rate, Services, Meds);
	}
	else
	{
		cost = Cost(Services, Meds);
	}
	
	printf("Your charges are $%.2f \n", cost);

	system("PAUSE");
	return 0;
}

double getPosNum()
{
	double num;
	cin >> num;
	while (num < 0)
	{
		cout << "Enter a positive number: ";
		cin >> num;
	}

	return num;
}

double Cost(double days, double rate, double services, double meds)
{
	double cost = days * rate + services + meds;
	return cost;
}

double Cost(double services, double meds)
{
	double cost = services + meds;
	return cost;
}