//CS 839
//Test 2

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Date
{
	int month;
	int day;
	int year;
};

struct Book
{
	string title;
	string author;
	int pages;
	double price;
	Date date;
};

int Get_Info(Book Books[]);

void Sort_Price(Book Books[], int NumOfBooks);

void Display1(Book Book);
void DisplayAll(Book Books[], int NumOfBooks);

int CheapCount(Book Books[], int NumOfBooks, double Cutoff);

int main()
{
	Book books[100];

	int numOfBooks = Get_Info(books);

	Sort_Price(books, numOfBooks);

	cout << "Books sorted by price:" << endl;
	DisplayAll(books, numOfBooks);

	double cutoff;
	cout << "Enter cutoff price: $";
	cin >> cutoff;
	cout << endl;

	int cheapCount = CheapCount(books, numOfBooks, cutoff);

	Book cheap[100];
	if (cheapCount == 0)
	{
		cout << "(no books at or below $" << fixed << setprecision(2) << cutoff << ")" << endl;
		cout << endl;
	}
	else
	{
		for (int j = 0; j < cheapCount; j++)
		{
			cheap[j] = books[j];
		}
		cout << "<= $" << fixed << setprecision(2) << cutoff << endl;
		DisplayAll(cheap, cheapCount);
	}

	Book expensive[100];
	if (cheapCount == numOfBooks)
	{
		cout << "(no books above $" << fixed << setprecision(2) << cutoff << ")" << endl;
		cout << endl;
	}
	else
	{
		for (int k = 0; k < numOfBooks - cheapCount; k++)
		{
			expensive[k] = books[cheapCount + k];
		}
		cout << " > $" << fixed << setprecision(2) << cutoff << endl;
		DisplayAll(expensive, numOfBooks - cheapCount);
	}

	system("pause");

	return 0;
}

int Get_Info(Book Books[])
{
	int BookCount = 0;

	while (BookCount < 100)
	{
		cout << "Enter book title (end by pressing Enter): ";
		if (BookCount != 0)
		{
			cin.ignore();
		}
		string InputTitle;
		getline(cin, InputTitle);
		if (InputTitle == "")
		{
			cout << endl;
			return BookCount;
		}
		Books[BookCount].title = InputTitle;
		
		cout << "Enter author: ";
		getline(cin, Books[BookCount].author);

		cout << "Enter pages: ";
		cin >> Books[BookCount].pages;

		cout << "Enter price: ";
		cin >> Books[BookCount].price;

		cout << "Enter date of publication: ";
		char slash = '/';
		cin >> Books[BookCount].date.month >> slash >> Books[BookCount].date.day >> slash >> Books[BookCount].date.year;

		BookCount++;
		cout << endl;
	}

	cout << "You've entered the maximum number of books." << endl;
	cout << endl;

	return BookCount;
}

void Sort_Price(Book Books[], int NumOfBooks)
{
	for (int i = 0; i < NumOfBooks - 1; i++)
	{
		for (int j = i + 1; j < NumOfBooks; j++)
		{
			if (Books[i].price > Books[j].price)
			{
				Book Temp = Books[i];
				Books[i] = Books[j];
				Books[j] = Temp;
			}
		}
	}
}

void Display1(Book Book)
{
	cout << Book.title << " BY " << Book.author << ", " << Book.pages << " pages, $" << fixed << setprecision(2) << Book.price << ", " << Book.date.month << "/" << Book.date.day << "/" << Book.date.year << endl;
}

void DisplayAll(Book Books[], int NumOfBooks)
{
	for (int i = 0; i < NumOfBooks; i++)
	{
		Display1(Books[i]);
	}
	cout << endl;
}

int CheapCount(Book Books[], int NumOfBooks, double Cutoff)
{
	int CheapCount = 0;

	for (int i = 0; i < NumOfBooks; i++)
	{
		if (Books[i].price <= Cutoff)
		{
			CheapCount++;
		}
		else
		{
			break;
		}
	}

	return CheapCount;
}