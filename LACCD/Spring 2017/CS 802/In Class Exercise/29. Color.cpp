#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	string Color1;
	string Color2;

	cout << "When you enter two primary colors, I will tell you" << endl
		<< "what color they make when they are mixed together." << endl << endl
		<< "Enter red, blue, or yellow: ";
	cin >> Color1;

	if (Color1 == "red")
		{
		cout << "Now enter blue or yellow: ";
		cin >> Color2;
		if (Color2 == "blue")
			{ cout << "Red and blue make purple." << endl; }
		else if (Color2 == "yellow")
			{cout << "Red and yellow make orange." << endl; }
		else
			{ cout << "You did not enter a second primary color." << endl; }
		}
	else if (Color1 == "blue")
		{
		cout << "Now enter red or yellow: ";
		cin >> Color2;
		if (Color2 == "red")
			{ cout << "Blue and red make purple." << endl; }
		else if (Color2 == "yellow")
			{ cout << "Blue and yellow make green." << endl; }
		else
			{ cout << "You did not enter a second primary color." << endl; }
		}
	else if (Color1 == "yellow")
		{
		cout << "Now enter red or blue: ";
		cin >> Color2;
		if (Color2 == "red")
			{ cout << "Yellow and red make orange." << endl; }
		else if (Color2 == "blue")
			{ cout << "Yellow and blue make green." << endl; }
		else
			{ cout << "You did not enter a second primary color." << endl; }
		}
	else { cout << "You did not enter a primary color." << endl; }

	return 0;
}