//James Mathias
//Mar 10, 2019
//CS 940
//Chapter 8-9 Assignment: Sorting
//take an array and sort it in two different ways

#include <iostream>
#include <string>
using namespace std;

void Display(int Array[], int Size);
void BubbleSort(int Array[], int Size);
void SelectionSort(int Array[], int Size);

int main()
{
	const int size = 8;
	
	int numArray1[size] = { 3, 14, 1, 59, 26, 5, 3, 5 };
	int numArray2[size] = { 3, 14, 1, 59, 26, 5, 3, 5 };

	cout << "-----Bubble Sort-----" << endl;
	Display(numArray1, size);
	BubbleSort(numArray1, size);
	cout << endl;

	cout << "-----Selection Sort-----" << endl;
	Display(numArray2, size);
	SelectionSort(numArray2, size);
	cout << endl;

	system("PAUSE");
	return 0;
}

void Display(int Array[], int Size)
{
	cout << Array[0];
	for (int i = 1; i < Size; i++)
	{
		cout << ", " << Array[i];
	}
	cout << endl;
}

void BubbleSort(int Array[], int Size)
{
	int n1 = Size;
	while (n1 > 1)
	{
		int n2 = 0;
		for(int i = 1; i < n1; i++)
		{
			if (Array[i-1] > Array[i])
			{
				swap(Array[i-1], Array[i]);
				Display(Array, Size);
				n2 = i;
			}
		}
		n1 = n2;
	}
}

void SelectionSort(int Array[], int Size)
{
	int n = Size;
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (Array[min] > Array[j])
			{
				min = j;
			}
		}
		
		if (min != i)
		{
			swap(Array[i], Array[min]);
			Display(Array, Size);
		}
	}
}