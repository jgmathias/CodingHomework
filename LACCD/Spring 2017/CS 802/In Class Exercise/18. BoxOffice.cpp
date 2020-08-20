#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string Movie;
	int AdultTix;
	int ChildTix;
	int AdultPrice = 10;
	int ChildPrice = 6;
	double DistributorPercent = .8;

	cout << "Name of the movie: ";
	getline(cin, Movie);
	cout << "Number of adult tickets sold: ";
	cin >> AdultTix;
	cout << "Number of child tickets sold: ";
	cin >> ChildTix;

	int Gross = AdultTix*AdultPrice + ChildTix*ChildPrice;
	double Distributor = Gross*(1 - DistributorPercent);
	double Revenue = Gross - Distributor;

	cout << endl;
	cout << "Revenue Report" << endl;
	cout << endl;
	cout << "Movie Name:\t\t\t  \"" << Movie << "\""<< endl;
	cout << "Adult Tickets Sold:\t\t  " << AdultTix << endl;
	cout << "Child Tickets Sold:\t\t  " << ChildTix << endl;
	cout << fixed << setprecision(2);
	cout << "Gross Box Office Revenue:\t  $" << setw(8) << (float)Gross << endl;
	cout << "Amount Paid to Distributor:\t -$" << setw(8) << Distributor << endl;
	cout << "Net Box Office Revenue:\t\t  $" << setw(8) << Revenue << endl;

	return 0;
}