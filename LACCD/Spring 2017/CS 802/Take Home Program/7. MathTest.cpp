#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

	int num = 1;
	int problems = 5;
	int range = 10;
	int ans;
	int Correct = 0;
	srand(time(0));
	
	long startTime = time(0);
	
	while (num <= problems)
	{
		int rand1 = rand() % range;
		int rand2 = rand() % range;
		cout << "What is " << rand1 << " + " << rand2 << "? ";
		cin >> ans;
		if (ans == rand1 + rand2)
			{ cout << "You are correct!" << endl << endl;
			Correct++; }
		else
			{cout << "Your answer is wrong." << endl;
			cout << rand1 << " + " << rand2 << " should be " << rand1 + rand2 << "." << endl << endl;}
		num++;
	}

	long endTime = time(0);
	
	cout << "++++++++++ Result +++++++" << endl;
	cout << "Correct count is "<< Correct << "." << endl;
	cout << "Test time is " << endTime - startTime << " seconds." << endl;

	return 0;
}