#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int num;
	int sum = 0;
	int pos = 0;
	int neg = 0;
	int zero = 0;
	ifstream inputFile;
	inputFile.open("numbers.txt");
	cout << "Here are the numbers stored in the input file." << endl;

	do
	{
		inputFile >> num;
		cout << num << " ";
		sum += num;
		if (num > 0)
			{pos++;}
		else if (num < 0)
			{neg++;}
		else
			{zero++;}
	}
	while (!inputFile.eof());

	int ave = sum / (pos + neg + zero);

	cout << endl << "Number of Positives: " << pos << endl;
	cout << "Number of Negatives: " << neg << endl << endl;

	cout << "Total is " << sum << endl;
	cout << "Average is " << ave << endl << endl;
	
	cout << "Done. " << endl;

	return 0;
}