//CS 839
//Final

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Product
{
	char description[51];
	double price;
};

void initialize(Product ProductPointers[], int MaxSize);
void getProductInfo(Product ProductPointers[], int Size);

void sort(Product Products[], int Size);

void display1(Product Product);
void displayAll(Product ProductPointers[], int Size);

void comparison(Product ProductPointers[], int Size, char Angle, double Compare);

int main()
{
	const int maxSize = 100;

	Product* productPointers = NULL;
	productPointers = new Product[maxSize];

	initialize(productPointers, maxSize);

	int size;
	cout << "Enter number of products (max 100): ";
	cin >> size;
	cout << endl;

	getProductInfo(productPointers, size);

	cout << endl;
	sort(productPointers, size);
	cout << "Sorted List:" << endl;
	cout << endl;

	displayAll(productPointers, size);

	char angle;
	double compare;
	cout << "Enter search expression (write '<', '>', or '=', then write price): ";
	cin >> angle >> compare;
	cout << endl;

	comparison(productPointers, size, angle, compare);

	cin >> angle;
	return 0;
}

void initialize(Product ProductPointers[], int MaxSize)
{
	for (int i = 1; i < MaxSize; i++)
	{
		for (int j = 0; j < 51; j++)
		{
			ProductPointers[i].description[j] = NULL;
		}
		ProductPointers[i].price = NULL;
	}
}

void getProductInfo(Product ProductPointers[], int Size)
{
	string Desc;
	for (int i = 0; i < Size; i++)
	{
		cout << "Enter description of product " << i + 1 << " (max 51 characters): ";
		cin.ignore();
		getline(cin, Desc);
		for (unsigned int j = 0; j < Desc.length(); j++)
		{
			ProductPointers[i].description[j] = Desc[j];
		}

		double Price;
		cout << "Enter price of " << Desc << ": ";
		cin >> Price;
		ProductPointers[i].price = Price;
		cout << endl;
	}
}

void sort(Product Products[], int Size)
{
	for (int i = 0; i < Size - 1; i++)
	{
		for (int j = i + 1; j < Size; j++)
		{
			if (Products[i].price > Products[j].price)
			{
				Product Temp = Products[i];
				Products[i] = Products[j];
				Products[j] = Temp;
			}
		}
	}
}

void display1(Product Product)
{
	cout << "Description: ";
	for (int j = 0; j < 51; j++)
	{
		cout << Product.description[j];
	}
	cout << endl;

	cout << "Price: $"<< Product.price << endl;
	cout << endl;
}

void displayAll(Product ProductPointers[], int Size)
{
	for (int i = 0; i < Size; i++)
	{
		display1(ProductPointers[i]);
	}
	cout << endl;
}

void comparison(Product ProductPointers[], int Size, char Angle, double Compare)
{

	bool test = false;

	if (Angle == '<')
	{
		for (int i = 0; i < Size; i++)
		{
			if (ProductPointers[i].price < Compare)
			{
				display1(ProductPointers[i]);
				test = true;
			}
		}
	}
	else if (Angle == '>')
	{
		for (int i = 0; i < Size; i++)
		{
			if (ProductPointers[i].price > Compare)
			{
				display1(ProductPointers[i]);
				test = true;
			}
		}
	}
	else if (Angle == '=')
	{
		for (int i = 0; i < Size; i++)
		{
			if (ProductPointers[i].price == Compare)
			{
				display1(ProductPointers[i]);
				test = true;
			}
		}
	}

	if (test == false)
	{
		cout << "There are no products " << Angle << Compare << endl;
	}
}