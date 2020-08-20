//James Mathias
//May 13, 2019
//CS 940
//Chapter 16 Assignment: Min/Max Templates

#include <iostream>
#include <string>
using namespace std;

template <class DataType>
DataType MAX(DataType A, DataType B);

template <class DataType>
DataType MIN(DataType A, DataType B);

int main()
{
	cout << "int" << endl;
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "MAX(a,b) = " << MAX <int>(a, b) << endl;
	cout << "MIN(a,b) = " << MIN <int>(a, b) << endl;
	cout << "\n";

	cout << "double" << endl;
	double c, d;
	cout << "c = ";
	cin >> c;
	cout << "d = ";
	cin >> d;
	cout << "MAX(c,d) = " << MAX <double>(c, d) << endl;
	cout << "MIN(c,d) = " << MIN <double>(c, d) << endl;
	cout << "\n";

	cout << "char" << endl;
	char e, f;
	cout << "e = ";
	cin >> e;
	cout << "f = ";
	cin >> f;
	cout << "MAX(e,f) = " << MAX <char>(e, f) << endl;
	cout << "MIN(e,f) = " << MIN <char>(e, f) << endl;
	cout << "\n";

	cout << "string" << endl;
	string g, h;
	cout << "g = ";
	cin >> g;
	cout << "h = ";
	cin >> h;
	cout << "MAX(g,h) = " << MAX <string>(g, h) << endl;
	cout << "MIN(g,h) = " << MIN <string>(g, h) << endl;
	cout << "\n";

	system("PAUSE");
	return 0;
}

template <class DataType>
DataType MAX(DataType A, DataType B)
{
	if (A >= B)
	{
		return A;
	}
	else
	{
		return B;
	}
}

template <class DataType>
DataType MIN(DataType A, DataType B)
{
	if (A <= B)
	{
		return A;
	}
	else
	{
		return B;
	}
}