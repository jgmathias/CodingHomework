/*
Homework #3
Author: James Mathias
Email: jgmathias@g.ucla.edu
Course: PIC 10A Summer 2017
Collaborators: N/A

Honesty Pledge:
I, James Mathias, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.

User inputs: budget and home size information
Output: cost of project or warning that project will be overbudget
List of known bugs: none
*/

#include <iostream>
#include <iomanip>
//#include <string>
#include <cmath>
using namespace std;

int main()
{
	cout << "* Home Remodeling *" << endl;								//heading
	cout << endl;
	
	int budget, length, width;
	
	cout << "Budget = ";										//user inputs values
		cin >> budget;
	cout << endl;
	cout << "Living Room Width (feet) = ";
		cin >> width;
	cout << endl;
	cout << "Living Room Length (feet) = ";
		cin >> length;
	cout << endl;
	
	int FloorArea = width * length;									//calculating the costs
	double FloorCost = 3.79 * FloorArea;
	int BackyardArea = 3 * FloorArea;
	double BackyardLength = sqrt(BackyardArea);
	int FenceCost = 18 * ceil(3 * BackyardLength);
	double TotalCost = FloorCost + FenceCost;
	
	if(budget < FloorCost)										//if cost is too high
	{
		cout << "* * * * * * * * * * * * * * * * * * *" << endl;
		cout << "* SORRY, YOUR BUDGET IS NOT ENOUGH. *" << endl;
		cout << "* * * * * * * * * * * * * * * * * * *" << endl;
	}
	else if(budget >= TotalCost)									//if budget is enough for both projects
	{
		cout << "* * * * * * * * * * * * * * * * * * *" << endl;
		cout << "* REMODELING PROJECT SPECIFICATIONS *" << endl;
		cout << "* * * * * * * * * * * * * * * * * * *" << endl;
		cout << endl;
		
		cout << "LIVING ROOM = " << FloorArea << " square feet of flooring needed." << endl;
		cout << "BACK YARD = " << ceil(3 * BackyardLength) << " feet of fence needed." << endl;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "TOTAL COST = $" << TotalCost << endl;
		
	}
	else												//if budget is enough for only for flooring
	{
		cout << "* * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "* NOT ENOUGH BUDGET ... ADJUSTING BACK YARD SIZE. *" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << endl;
		
		cout << "LIVING ROOM = " << FloorArea << " square feet of flooring needed." << endl;
		cout << endl;
		
		cout << "     TOTAL COST     FENCE AMOUNT     BACK YARD SIZE" << endl;			//how much for various downsized backyard fences
		cout << endl;
		cout.setf(ios::fixed);
		cout.precision(2);
		int TestFenceLength = 0;
		double TestCost = FloorCost;
		while( budget >= TestCost)
		{
			cout << "      $" << setw(8) << TestCost << "         " << setw(3) << 3 * TestFenceLength << "'            " << setw(2) << TestFenceLength << "' x " << setw(2) << TestFenceLength << "'" << endl;
			TestFenceLength +=5;
			TestCost = FloorCost + (18 * 3 * TestFenceLength);
		}
	}

	
	return 0;
}