#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char letter, number, symbol;

	cout << "Please enter a letter, integer number and a symbol (e.g. B 6 #): ";
	cin >> letter >> number >> symbol;

	int nletter = (int)letter;
	int nnumber = (int)number;
	int nsymbol = (int)symbol;

	cout << "          letter = " << letter << "     number = " << number << "     symbol = " << symbol << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Decimal" << dec << setw(10) << nletter << setw(15) << nnumber << setw(15) << nsymbol << endl;
	cout << "Hex    " << hex << setw(10) << nletter << setw(15) << nnumber << setw(15) << nsymbol << endl;
	cout << "Octal  " << oct << setw(10) << nletter << setw(15) << nnumber << setw(15) << nsymbol << endl;

	return 0;
}