#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	
	int Year;
	string Animal;

	cout << "Enter a four-digit year: " ;
	cin >> Year;
	int Choice = Year % 12;

	if (Year < 1000 || Year >= 10000)
		{cout << "You must enter a four-digir year." << endl;}
	else
		{switch(Choice)
			{case 0: Animal = "Monkey"; break;
			case 1: Animal = "Rooster"; break;
			case 2: Animal = "Dog"; break;
			case 3: Animal = "Pig"; break;
			case 4: Animal = "Rat"; break;
			case 5: Animal = "Ox"; break;
			case 6: Animal = "Tiger"; break;
			case 7: Animal = "Rabbit"; break;
			case 8: Animal = "Dragon"; break;
			case 9: Animal = "Snake"; break;
			case 10: Animal = "Horse"; break;
			case 11: Animal = "Sheep"; break;
			default: 0;}
		cout << "The Chinese Zodiac animal for this year is the " << Animal << "." << endl;}

	return 0;
}