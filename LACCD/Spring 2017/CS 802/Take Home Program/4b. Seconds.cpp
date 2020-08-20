#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int Seconds;

	cout << "Enter an integer for seconds: ";
	cin >> Seconds;

	int Hours = Seconds / 3600;
	Seconds = Seconds % 3600;
	int Minutes = Seconds / 60;
	Seconds = Seconds % 60;

	cout << "Elapsed time should be: " << Hours << " hour(s) " << Minutes << " minute(s) and " << Seconds << " second(s)" << endl;
	
	return 0;
}