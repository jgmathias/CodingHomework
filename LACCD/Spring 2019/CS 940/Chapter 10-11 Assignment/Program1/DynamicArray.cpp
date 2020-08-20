//James Mathias
//Mar 18, 2019
//CS 940
//Chapter 10-11 Assignment: Dynamic Array
//create a dynamic array that holds test scores

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void Display(int Array[], int Size);
void SelectionSort(int Array[], int Size);
double Average(int Array[], int Size);

int main()
{
	cout << "-----Create Test Score Array-----" << endl;

	int size = 0;
	while (size <= 0)
	{
		cout << "How many test scores? ";
		cin >> size;
	}

	int *Scores = new int[size];

	for (int i = 0; i < size; i++)
	{
		int score = -1;
		while (score < 0)
		{
			cout << "Test score " << i+1 << ": ";
			cin >> score;
		}
		Scores[i] = score;
	}

	cout << "Unsorted List of Scores" << endl;
	Display(Scores, size);

	cout << "\n-----Sort Test Scores-----" << endl;
	cout << "Sorted List of Scores" << endl;
	SelectionSort(Scores, size);

	cout << "\n-----Get Average Score-----" << endl;
	double average = Average(Scores, size);
	cout << "Average: " << fixed << setprecision(2) << average << endl;

	delete[] Scores;

	cout << "\n";
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
			
		}
	}
	Display(Array, Size);
}

double Average(int Array[], int Size)
{
	double sum = 0;

	for (int i = 0; i < Size; i++)
	{
		sum += Array[i];
	}

	double average = sum / Size;

	return average;
}