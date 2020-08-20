//James Mathias
//Apr 30, 2019
//CS 940
//Chapter 15 Assignment: Sequence Sum

#include <iostream>
using namespace std;

#include "AbstractSeq.h"

int main()
{
	AbstractSeq temp;

	cout << "i = ";
	int i;
	cin >> i;
	cout << "j = ";
	int j;
	cin >> j;

	cout << "PrintSeq = ";
	temp.PrintSeq(i, j);
	cout << "\nSumSeq = " << temp.SumSeq(i, j) <<"\n";

	system("PAUSE");
	return 0;
}