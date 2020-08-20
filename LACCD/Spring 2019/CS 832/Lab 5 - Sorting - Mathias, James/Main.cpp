//Lab 5: Mathias, James

//James Mathias
//June 2, 2019
//CS 832
//Lab #5: Sorting 3 of 3

#include <iostream>
//#include <sstream>
//#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#include "RecordList.h"

int Menu();													//display menu
int SubMenu();												//display submenu 
int GetPosInt(string Question, int Max);					//gets positive integer, if "Max" > 0, limit output by "Max"

int main()
{
	
	/////////////////////////
	/*
	const int ListSize = 100;
	RecordList StudentRecords(ListSize);					//class that holds array of 100 records
	*/
	/////////////////////////

	RecordList StudentRecords;

	/////////////////////////

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	string InputFileName;									//read data, put data into record, put records onto list
	cout << "Input File Name = ";
	cin >> InputFileName;
	ifstream InputFile(InputFileName);
	string Line;
	//////////////////////////////////////////////////
	
	while (getline(InputFile, Line))
	{
		string tempData[5];
		istringstream ss(Line);
		for (int i = 0; i < 5; i++)
		{
			getline(ss, tempData[i], ' ');
		}
		Record tempRecord(tempData[0], tempData[1], stod(tempData[2]), stoi(tempData[3]), tempData[4]);
		StudentRecords.AddRecord(tempRecord);
	}
	
	//////////////////////////////////////////////////
	
	string tempFName;
	string tempLName;
	double tempGPA;
	int tempIDNum;
	string tempEMail;
	while (InputFile >> tempFName >> tempLName >> tempGPA >> tempIDNum >> tempEMail)
	{
		Record tempRecord(tempFName, tempLName, tempGPA, tempIDNum, tempEMail);
		StudentRecords.AddRecord(tempRecord);
	}
	
	//////////////////////////////////////////////////
	InputFile.close();
	*/
	////////////////////////////////////////////////////////////////////////////////////////////////////
	
	Record tempRecord1("firstname", "lastname", 4.0, 1, "abc@123.test");
	StudentRecords.AddRecord(tempRecord1);
	Record tempRecord2("first", "last", 3.5, 2, "aaa@123.test");
	StudentRecords.AddRecord(tempRecord2);
	Record tempRecord3("fname", "lname", 4.5, 3, "bbb@123.test");
	StudentRecords.AddRecord(tempRecord3);
	Record tempRecord4("firstname", "lname", 3.0, 4, "abc@111.test");
	StudentRecords.AddRecord(tempRecord4);
	Record tempRecord5("fname", "lastname", 3.5, 5, "abc@123.test");
	StudentRecords.AddRecord(tempRecord5);
	
	////////////////////////////////////////////////////////////////////////////////////////////////////


	int Choice = 0;
	int SortBy = 0;

	string Sort[4] = { "Selection", "Insertion", "Quick", "Bubble" };
	string Field[5] = { "First Name","Last Name","GPA","ID Number","E-Mail" };
	int Comparisons[4][5] = { {0} };
	int Movements[4][5] = { {0} };

	do
	{
		Choice = Menu();

		switch (Choice)
		{
		case 1:
		{
			StudentRecords.Print();
			break;
		}
		case 2:
		{
			RecordList TempList = StudentRecords;
			SortBy = SubMenu() - 1;
			TempList.SelectionSort(SortBy);
			TempList.Print();
			cout << "\n"
				<< "Comparisons = " << TempList.Comparison() << "\n"
				<< "Movements = " << TempList.Movement() << endl;
			Comparisons[0][SortBy] += TempList.Comparison();
			Movements[0][SortBy] += TempList.Movement();
			break;
		}
		case 3:
		{
			RecordList TempList = StudentRecords;
			SortBy = SubMenu() - 1;
			TempList.InsertionSort(SortBy);
			TempList.Print();
			cout << "\n"
				<< "Comparisons = " << TempList.Comparison() << "\n"
				<< "Movements = " << TempList.Movement() << endl;
			Comparisons[1][SortBy] += TempList.Comparison();
			Movements[1][SortBy] += TempList.Movement();
			break;
		}
		case 4:
		{
			RecordList TempList = StudentRecords;
			SortBy = SubMenu() - 1;
			TempList.QuickSort(SortBy);
			TempList.Print();
			cout << "\n"
				<< "Comparisons = " << TempList.Comparison() << "\n"
				<< "Movements = " << TempList.Movement() << endl;
			Comparisons[2][SortBy] += TempList.Comparison();
			Movements[2][SortBy] += TempList.Movement();
			break;
		}
		case 5:
		{
			RecordList TempList = StudentRecords;
			SortBy = SubMenu() - 1;
			TempList.BubbleSort(SortBy);
			TempList.Print();
			cout << "\n"
				<< "Comparisons = " << TempList.Comparison() << "\n"
				<< "Movements = " << TempList.Movement() << endl;
			Comparisons[3][SortBy] += TempList.Comparison();
			Movements[3][SortBy] += TempList.Movement();
			break;
		}
		}
	} while (Choice != 6);

	cout << "\n"
		<< "      Sort      Field Comparisons Movements" << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << setw(10) << right << Sort[i] << setw(11) << right << Field[j] << setw(12) << right << Comparisons[i][j] << setw(10) << right << Movements[i][j] << endl;
		}
	}
	cout << endl;

	cout << "\n";
	system("PAUSE");
	return 0;
}

int Menu()
{
	cout << "\n"
		<< "\n"
		<< "Menu:\n"
		<< "1. Print Unsorted Records.\n"
		<< "2. Use Selection Sort then Print.\n"
		<< "3. Use Insertion Sort then Print.\n"
		<< "4. Use Quick Sort then Print.\n"
		<< "5. Use Bubble Sort then Print.\n"
		<< "6. Print Total Number of Comparisons and Movements then Quit." << endl;

	int Choice = GetPosInt("Choice:", 6);
	cout << endl;

	return Choice;
}

int SubMenu()
{
	cout << "\n"
		<< "Sort by which value:\n"
		<< "1. First Name.\n"
		<< "2. Last Name.\n"
		<< "3. GPA.\n"
		<< "4. ID Number.\n"
		<< "5. E-Mail." << endl;

	int SortBy = GetPosInt("Choice:", 5);
	cout << endl;

	return SortBy;
}

int GetPosInt(string Question, int Max)
{
	string A, B;
	double C;
	bool Valid = true;

	cout << Question << " ";
	getline(cin, A);										//input string
	B = A;

	if (B[0] == '-')
	{														//remove possible negative sign
		B.erase(0, 1);
	}

	size_t decimal = B.find('.');
	if (decimal != -1)
	{														//remove possible decimal point
		B.erase(decimal, 1);
	}

	for (unsigned int i = 0; i < B.size(); i++)
	{														//check if the remaining characters are digits
		if (!isdigit(B[i]))
		{
			cout << "Invalid input! Please input a numerical value." << endl;
			Valid = false;
			break;
		}
	}

	if (Valid)
	{														//string input is numeric, so convert to double
		C = stod(A);
	}

	if (Valid && (C - int(C) != 0))
	{														//verify if the input is an integer
		cout << "Invalid input! Please input an integer value." << endl;
		Valid = false;
	}

	if (Valid && C <= 0)
	{														//verify if the input is positive
		cout << "Invalid input! Please input a positive value." << endl;
		Valid = false;
	}

	if (Valid && Max > 0 && C > Max)
	{														//verify if the input is at most MAX
		cout << "Invalid input! Please enter a number less than or equal to " << Max << "." << endl;
		Valid = false;
	}

	if (!Valid)
	{														//recall function with same variables if invalid
		C = GetPosInt(Question, Max);
	}

	return int(C);
}