#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	int a = rand() % 10;
	int b = rand() % 10;
	int c = rand() % 10;
	int Sum = a + b + c;
	int Answer;

	cout << "What is " << a << " + " << b << " + " << c << "? ";
	cin >> Answer;

	if (Answer == Sum) {
		cout << "You are correct!" << endl;
	}
	else {
		cout << "Your answer is wrong." << endl
			<< a << " + " << b << " + " << c << " should be " << Sum << "." << endl;
	}

	return 0;
}