//James Mathias
//Feb 20, 2019
//CS 940
//Chapter 4-5 Assignment: Program2
//read employee data from file, calculate raise, than write to different file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	const int MAX = 100;


	string linedata[MAX];

	ifstream readfile("employeeSalary.txt");
	string line;
	int num = 0;

	while (getline(readfile, line))
	{
		linedata[num] = line;
		num++;
	}

	readfile.close();


	string fname[MAX];
	string lname[MAX];
	double salary[MAX];
	double raise[MAX];
	double newsalary[MAX];

	string delimiter = " ";

	for (int i = 0; i < num; i++)
	{
		string stringtosplit = linedata[num];
		string split[4];

		for (int j = 0; j < 4; j++)
		{
			size_t pos = stringtosplit.find(delimiter);
			string token = stringtosplit.substr(0, pos);
			split[j] = token;
			j++;
			stringtosplit.erase(0, pos + 1);
		}

		fname[i] = split[0];
		lname[i] = split[1];
		salary[i] = stod(split[2]);
		raise[i] = stod(split[3]);
		newsalary[i] = salary[i] * (1 + (raise[i] / 100));
	}


	ofstream myfile("employeeOutput.txt");

	for (int k = 0; k < num; k++)
	{
		myfile << fname[k] << " " << lname[k] << " ";
		printf("%.2f\n", newsalary[k]);
	}

	myfile.close();

	system("PAUSE");
	return 0;
}