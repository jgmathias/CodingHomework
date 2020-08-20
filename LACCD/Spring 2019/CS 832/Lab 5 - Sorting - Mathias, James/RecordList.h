//Lab 5: Mathias, James

//James Mathias
//June 2, 2019
//CS 832
//Lab #5: Sorting 2 of 3

#include <iomanip>
#include <string>
using namespace std;

#include "Record.h"

class RecordList
{
private:
	int listsize;
	int currentsize;
	int comparison;
	int movement;
	//
	Record List[100];
	//Record* List = new Record[listsize];
	string temp[100];
	void SortField(int SortBy);
	void QS(string Temp[], int Low, int High);
	int Partition(string Temp[], int Low, int High);

public:
	//
	RecordList();
	//RecordList(int ListSize);
	void AddRecord(Record NewRecord);
	void Print();
	void SelectionSort(int SortBy);
	void InsertionSort(int SortBy);
	void QuickSort(int SortBy);
	void BubbleSort(int SortBy);
	int Comparison();
	int Movement();
};

/////

RecordList::RecordList()
{
	listsize = 100;
	currentsize = 0;
}

/////
/*
RecordList::RecordList(int ListSize)
{
	listsize = ListSize;
	currentsize = 0;
}
*/
/////

void RecordList::AddRecord(Record NewRecord)
{
	List[currentsize] = NewRecord;
	currentsize++;
}

void RecordList::Print()
{
	cout << "\n"
		<< "   First Name    Last Name   GPA   ID Number   E-Mail" << endl;
	for (int i = 0; i < currentsize; i++)
	{
		cout << setw(13) << right << List[i].FName() << setw(13) << right << List[i].LName() << setw(6) << right << fixed << setprecision(2) << List[i].GPA() << setw(12) << right << List[i].IDNum() << "  " << List[i].EMail() << endl;
	}
}

void RecordList::SelectionSort(int SortBy)
{
	comparison = 0;
	movement = 0;
	SortField(SortBy);

	for (int i = 0; i < currentsize - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < currentsize; j++)
		{
			if (temp[j] < temp[min])
			{
				min = j;
			}
			comparison++;
		}

		if (min != i)
		{
			swap(temp[min], temp[i]);
			swap(List[min], List[i]);
			movement++;
		}
	}
}

void RecordList::InsertionSort(int SortBy)
{
	comparison = 0;
	movement = 0;
	SortField(SortBy);

	for (int i = 1; i < currentsize; i++)
	{
		string key = temp[i];
		int j = i - 1;

		while (j >= 0 && temp[j] > key)
		{
			comparison++;
			temp[j + 1] = temp[j];
			List[j + 1] = List[j];
			movement++;
			j = j - 1;
			
		}
		temp[j + 1] = key;
		List[j + 1] = List[i];
		movement++;
	}
}

void RecordList::QuickSort(int SortBy)
{
	comparison = 0;
	movement = 0;
	SortField(SortBy);

	QS(temp, 0, currentsize - 1);
}

void RecordList::QS(string Temp[], int Low, int High)
{
	if (Low < High)
	{
		int P = Partition(Temp, Low, High);
		QS(Temp, Low, P);
		QS(Temp, P + 1, High);
		comparison++;
	}
}

int RecordList::Partition(string Temp[], int Low, int High)
{
	string pivot = Temp[Low];
	int i = Low - 1;
	int j = High + 1;

	do
	{
		do
		{
			i++;
			comparison++;
		} while (Temp[i] < pivot);

		do
		{
			j--;
			comparison++;
		} while (Temp[j] > pivot);

		if (i >= j)
		{
			return j;
		}
		comparison++;

		swap(Temp[i], Temp[j]);
		swap(List[i], List[j]);
		movement++;
	} while (true);
}

void RecordList::BubbleSort(int SortBy)
{
	comparison = 0;
	movement = 0;
	SortField(SortBy);

	int n1 = currentsize;
	while (n1 > 1)
	{
		int n2 = 0;
		for (int i = 1; i < n1; i++)
		{
			if (temp[i - 1] > temp[i])
			{
				swap(temp[i - 1], temp[i]);
				swap(List[i - 1], List[i]);
				movement++;
				n2 = i;
			}
			comparison++;
		}
		n1 = n2;
	}
}

void RecordList::SortField(int SortBy)
{
	if (SortBy == 0)
	{
		for (int i = 0; i < currentsize; i++)
		{
			temp[i] = List[i].FName();
		}
	}
	else if (SortBy == 1)
	{
		for (int i = 0; i < currentsize; i++)
		{
			temp[i] = List[i].LName();
		}
	}
	else if (SortBy == 2)
	{
		for (int i = 0; i < currentsize; i++)
		{
			temp[i] = List[i].GPA();
		}
	}
	else if (SortBy == 3)
	{
		for (int i = 0; i < currentsize; i++)
		{
			temp[i] = List[i].IDNum();
		}
	}
	else if (SortBy == 4)
	{
		for (int i = 0; i < currentsize; i++)
		{
			temp[i] = List[i].EMail();
		}
	}
}

int RecordList::Comparison()
{
	return comparison;
}

int RecordList::Movement()
{
	return movement;
}