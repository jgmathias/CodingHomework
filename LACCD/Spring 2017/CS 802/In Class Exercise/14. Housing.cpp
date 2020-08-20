#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int House;
	int Utilities;
	int Phone;
	int Cable;

	cout << "Enter your monthly costs for the folowing:" << endl;
	cout << endl;
	cout << "Rent or morgage: $";
	cin >> House;
	cout << "Utilities:\t $";
	cin >> Utilities;
	cout << "Phone(s):\t $" ;
	cin >> Phone;
	cout << "Cable:\t\t $";
	cin >> Cable;

	double Total = House + Utilities + Phone + Cable + 0.;
	double YearlyTotal = Total * 12.;
	
	cout << endl;
	cout << fixed << setprecision(2);
	cout << "Total monthly housing costs $ " << setw(8) << Total << endl;
	cout << "Total annual housing costs  $ " << setw(8) << YearlyTotal << endl;

	return 0;
}