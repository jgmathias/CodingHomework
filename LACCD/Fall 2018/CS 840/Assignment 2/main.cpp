//CS 840
//Assignment 2
//5 of 5

#include <iostream>
#include <cstring>
using namespace std;

#include "FracList.h"

int main(void)
{
	int sizeA, sizeB;
	
	cout << "Size of 1st fraction list: ";
	cin >> sizeA;
	cout << "Size of 2nd fraction list: ";
	cin >> sizeB;
	cout << endl;
	
	FracList ListA(sizeA);
	FracList ListB(sizeB);

	cout << "Enter " << sizeA << " fractions for the 1st list: ";
	ListA >> ListA;
	cout << "Enter " << sizeB << " fractions for the 2nd list: ";
	ListB >> ListB;
	cout << endl;

	cout << "Sorted Lists: " << endl;
	ListA.sort();
	ListA << ListA;
	ListB.sort();
	ListB << ListB;
	cout << endl;

	cout << "Enter a fraction to search for: ";
	Fraction Search(0,1);
	Search >> Search;
	ListA.search(Search);
	ListB.search(Search);
	cout << endl;

	cout << "Swapped Lists: " << endl;
	FracList fltemp = ListA;
	int sizetemp = sizeA;
	ListA = ListB;
	sizeA = sizeB;
	ListB = fltemp;
	sizeB = sizetemp;
	ListA << ListA;
	ListB << ListB;
	cout << endl;

	cout << "Added sum to the end of the longer list: " << endl;
	FracList ListC;
	int sizeC;
	if (ListA >= ListB)
	{
		ListC = ListA;
		sizeC = sizeA;
	}
	else
	{
		ListC = ListB;
		sizeC = sizeB;
	}
	Fraction listsum(0,1);
	for (int i = 0; i < sizeC; i++)
	{
		Fraction fractemp = ListC.getFrac(i);
		listsum += fractemp;
	}
	sizeC += 1;
	ListC.resize2(sizeC);
	ListC.setFrac(listsum, sizeC - 1);
	ListC << ListC;

	cout << endl;

	system("PAUSE");
	return 0;
}