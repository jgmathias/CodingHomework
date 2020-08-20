//Lab 1: Mathias, James

//James Mathias
//Feb 24, 2019
//CS 832
//Lab #1: Recursion Menu

#include <iostream>
#include <string>
using namespace std;

int menu();
double power(double X, int N);
double sumForward(int N, string Sum);			//string Sum carries the "... + 1/(n-2) + 1/(n-1) + 1/n = " until the last step where it is printed
double sumReverse(int N);						//"1/n" is output every recursion
double getNum(bool Int, bool Pos, bool Menu);	//bool Int == true -> function verifies that input is an integer
												//bool Pos == true -> function verifies that input is positive
												//bool Menu == true -> function verifies that input is 1, 2, 3, or 4

int main()
{
	int choice = 0;

	do											//begining of do-while loop
	{
		choice = menu();						//if "4" is entered, then loop will stop after this run

		double x;
		int n;
		double ans;

		switch (choice)
		{
		case 1:
			x = getNum(false, false, false);
			n = getNum(true, false, false);
			if (x < 0 || (x - int(x) != 0))		//use parentheses for negative and decimal numbers when displaying
			{
				cout << "(" << x << ")" << "^";
			}
			else
			{
				cout << x << "^";
			}
			if (n < 0)
			{
				cout << "(" << n << ") = ";
			}
			else
			{
				cout << n << " = ";
			}
			ans = power(x, n);
			cout << ans << "\n" << endl;
			break;

		case 2:
			n = getNum(true, true, false);
			cout << "sum_(N=1)^(N=" << n << ") (1/N) = ";
			ans = sumForward(n, " = ");
			cout << ans << "\n" << endl;
			break;

		case 3:
			n = getNum(true, true, false);
			cout << "sum_(N=0)^(N=" << n-1 << ") (1/(" << n << "-N)) = ";
			ans = sumReverse(n);
			cout << ans << "\n" << endl;
			break;

		case 4:
			cout << "Goodbye!" << endl;
			break;
		}
	} while (choice != 4);						//input 4 to exit do-while loop

	cout << endl;
	system("PAUSE");
	return 0;
}

int menu()
{
	int Choice;

	cout << "Menu:\n"
		<< "1. x^n\n"
		<< "2. sum_N=1^N=n (1/N)\n"
		<< "3. sum_N=0^N=n-1 (1/(n-N))\n"
		<< "4. quit" << endl;
	Choice = getNum(true, true, true);

	return Choice;
}

double power(double X, int N)
{
	if (N == 0)									//special case when N is zero
	{
		if (X == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	
	if (N < 0)
	{
		cout << "1/";
	}

	if (X < 0)
	{
		cout << "(" << X << ")";
	}
	else
	{
		cout << X;
	}

	if (abs(N) == 1)							//final recursion case
	{
		cout << " = ";
		
		if (N > 0)
		{
			return X;
		}
		else
		{
			return (1/X);
		}		
	}
	else										//general cases
	{
		cout << " * ";
		
		if (N > 0)
		{
			return (X * power(X, N - 1));
		}
		else
		{
			return ((1 / X) * power(X, N + 1));
		}
	}
}

double sumForward(int N, string Sum)
{
	if (N == 1)
	{
		cout << "1/1" << Sum;
		return 1;
	}
	else
	{
		Sum = " + 1/" + to_string(N) + Sum;		//this string is carried over to each recursive step, and outputed only at last step
		return (sumForward(N - 1, Sum) + (1.0 / N));
	}
}

double sumReverse(int N)
{
	if (N == 1)
	{
		cout << "1/1 = ";
		return 1;
	}
	else
	{
		cout << "1/" << N << " + ";				//this line is outputed each recursive step
		return ((1.0 / N) + sumReverse(N - 1));
	}
}

double getNum(bool Int, bool Pos, bool Menu)
{
	string A, B;
	double C;
	bool Valid = true;

	if (Menu)
	{
		cout << "Choice: ";
	}
	else if (Int)
	{
		cout << "n = ";
	}
	else
	{
		cout << "x = ";
	}
	cin >> A;
	B = A;

	if (B[0] == '-')							//remove possible negative
	{
		B.erase(0, 1);
	}

	int decimal = B.find('.');					//remove possible decimal point
	if (decimal != -1)
	{
		B.erase(decimal, 1);
	}

	for (unsigned int i = 0; i < B.size(); i++)	//check if the remaining characters are digits
	{
		if (!isdigit(B[i]))
		{
			cout << "Invalid input! Please input a numerical value." << endl;
			Valid = false;
			break;
		}
	}

	if (Valid)									//string input is numeric, so convert to double
	{
		C = stod(A);
	}

	if (Valid && Int && (C - int(C) != 0))		//verify if the input is an integer
	{
		cout << "Invalid input! Please input an integer value." << endl;
		Valid = false;
	}

	if (Valid && Pos && C <= 0)					//verify if the input is positive
	{
		cout << "Invalid input! Please input a positive value." << endl;
		Valid = false;
	}

	if (Valid && Menu && (C < 1 || C > 4))		//verify if the input is 1, 2, 3, or 4
	{
		cout << "Invalid choice! Please enter 1, 2, 3, or 4." << endl;
		Valid = false;
	}

	if (!Valid)									//recall function if invalid
	{
		C = getNum(Int, Pos, Menu);
	}

	return C;
}