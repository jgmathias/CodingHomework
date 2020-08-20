//CS 816
//HW2 - Image Serializer

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int length;
	cout << "What is the length of the image? ";
	cin >> length;
	while (length <= 0)
	{
		cout << "Please enter a positive integer. ";
		cin >> length;
	}
	cout << endl;

	int height;
	cout << "What is the height of the image? ";
	cin >> height;
	while (height <= 0)
	{
		cout << "Please enter a positive integer. ";
		cin >> height;
	}
	cout << endl;

	string serial;
	cout << "Write a sting with a length of " << length * height << ". (Anything longer will be truncated.)" << endl;
	cin.ignore();
	getline(cin, serial);
	while (serial.size() < length * height)
	{
		cout << "Write a longer sting." << endl;
		getline(cin, serial);
	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		cout << serial.substr(length * i, length) << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}