#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

	string Name;
	int num;
	int range = 10;
	int random;
	string compare;
	char again;
	srand(time(0));

	cout << "Please enter your name: ";
	cin >> Name;

	do {
		
		cout << endl << "Please enter a number between 1 and "<< range <<": ";
		cin >> num;
		
		if (num < 1 || num > range)
		{cout << endl << "\t" << Name << ", your number is out of range." << endl;}
		else{
			int random = rand() % range + 1;
			cout << endl << "\t" << Name << ", you entered " << num << " and the computer generated " << random << "." << endl;
			if (num > random)
				{compare = "greater than";}
			else if (num < random)
				{compare = "less than";}
			else
				{compare = "the same as";}
			cout << "\t" << "Your number is " << compare << " the computer's number." << endl;
		}

		cout << endl << "\t" << "Go again? (Y/N) ";
		cin >> again;
	} while (toupper(again) == 'Y');	

	cout << endl << "Goodbye for now" << endl;

	return 0;
}