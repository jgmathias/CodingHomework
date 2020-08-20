#include <iostream>
using namespace std;

void num_chars(char a, int numb)
{
	for (int x = 1; x <= numb; x++)
	{
		cout << a << " ";
	}
	cout << endl;
}


int main()
{
	char C;
	int num;

	cout << "Enter a character: ";
	cin >> C;
	
	do
	{
		cout << "How many times would you want to display character " << C << "? ";
		cin >> num;

		num_chars(C, num);

		cout << "Enter another character or press the q-key to quit: ";
		cin >> C;
	}
	while (C != 'q');

	cout << "Bye" << endl;

	return 0;
}