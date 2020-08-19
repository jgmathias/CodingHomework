/*
Homework #4
Author: James Mathias
Email: jgmathias@g.ucla.edu
Course: PIC 10A Summer 2017
Collaborators: N/A

Honesty Pledge:
I, James Mathias, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.

User inputs: grades earned in class
Output: final grade
List of known bugs: none
*/

#include <iostream>
#include <iomanip>
//#include <string>
//#include <cmath>
using namespace std;

int main()
{
	cout << "PIC 10A GRADE CALCULATOR" << endl;					//heading
	cout << endl;
	
	double HW, E1, E2, FE;
	
	cout << "Homework grade (%)   = ";						//user inputs values
		cin >> HW;
	cout << endl;
	cout << "Exam I grade (%)     = ";
		cin >> E1;
	cout << endl;
	cout << "Exam II grade (%)    = ";
		cin >> E2;
	cout << endl;
	cout << "Final Exam grade (%) = ";
		cin >> FE;
	cout << endl;
	
	if(HW < 0 || HW > 100)								//error checking the input
	{
		cout << "Error: Homework grade not valid" << endl;
		return 1;
	}
	else if(E1 < 0 || E1 > 100)
	{
		cout << "Error: Exam I grade not valid" << endl;
		return 1;
	}
	else if(E2 < 0 || E2 > 100)
	{
		cout << "Error: Exam II grade not valid" << endl;
		return 1;
	}
	else if(FE < 0 || FE > 100)
	{
		cout << "Error: Final Exam grade not valid" << endl;
		return 1;
	}
	
	if(E1 <= E2)									//replace lower exam grade with final exam grade
	{
		if(E1 < FE)
			{E1 = FE;}
	}
	else
	{
		if(E2 < FE)
			{E2 = FE;}
	}
	
	double OA = (0.2 * HW) + (0.25 * E1) + (0.25 * E2) + (0.3 * FE);		//overall grade
	
	string CG;									//getting class grade
	if(OA >= 93)
		{CG = "A";}
	else if(OA >= 90)
		{CG = "A-";}
	else if(OA >= 87)
		{CG = "B+";}
	else if(OA >= 83)
		{CG = "B";}
	else if(OA >= 80)
		{CG = "B-";}
	else if(OA >= 77)
		{CG = "C+";}
	else if(OA >= 73)
		{CG = "C";}
	else if(OA >= 70)
		{CG = "C-";}
	else if(OA >= 67)
		{CG = "D+";}
	else if(OA >= 63)
		{CG = "D";}
	else if(OA >= 61)
		{CG = "D-";}
	else
		{CG = "F";}
	
	cout.setf(ios::fixed);
	cout.precision(2);
	
	cout << endl;									//output
	cout << "CATEGORY         GRADE" << endl;
	cout << endl;
	cout << "HOMEWORK        " << setw(6) << HW << endl;
	cout << "EXAM I          " << setw(6) << E1 << endl;
	cout << "EXAM II         " << setw(6) << E2 << endl;
	cout << "FINAL EXAM      " << setw(6) << FE << endl;
	cout << "OVERALL GRADE   " << setw(6) << OA << endl;
	cout << "CLASS GRADE       " << CG << endl;
	
	return 0;
}