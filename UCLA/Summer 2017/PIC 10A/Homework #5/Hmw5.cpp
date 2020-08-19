/*
Homework #5
Author: James Mathias
Email: jgmathias@g.ucla.edu
Course: PIC 10A Summer 2017
Collaborators: N/A

Honesty Pledge:
I, James Mathias, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.

User inputs: initial population conditions and # of years to run population growth model
Output: probability of survival
List of known bugs: none
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

unsigned long long Deterministic(int p0, double rb, double rd, int t)
{
	int pt = p0 * pow(1 + rb - rd, t);
	return pt;
}

double Enviornmental(double pt, double rb, double rd, double e)
{
	double pt1 = pt * (1 + rb - rd - e);
	return pt1;
}

double e()																				//e() returns a random number between -1 and 1 
{
	double e = -1 + rand() * 2.0 / RAND_MAX;
	return e;
}

int main()
{
	int P0, T;
	double RB, RD;
	
	cout << "Initial Population = ";
	cin >> P0;
	cout << "Birth Rate = ";
	cin >> RB;
	cout << "Death Rate = ";
	cin >> RD;
	cout << "Years = ";
	cin >> T;
	cout << endl;
	
	if(P0 < 2)
	{
		cout << "Error: Initial Population not valid" << endl;
		return 1;
	}
	
	srand(time(0));
	
	unsigned long long DPT = Deterministic(P0, RB, RD, T);								//running direct model
	string EX;
	if(DPT == 0)
	{
		EX = "Certain";
	}
	else if (DPT < P0)
	{
		EX = "Probable";
	}
	else
	{
		EX = "Possible";
	}
	
	unsigned long long EPT = P0;
	double EP = P0;
	for(int j = 1; j <= T; j++)															//running yearly random model for T years
	{
		double E = e();
		EP = Enviornmental(EP, RB, RD, E);
		//cout << E << " " << EP << endl;
		if(EP < 1)
		{
			break;																		//the loop stops when the population drops to virtually zero
		}
	}
	EPT = EP;
	
	int k = 0;
	for(int i = 1; i <= 100; i++)														//outer loop: running environmental model 100 times
	{
		double EP = P0;
		for(int j = 1; j <= T; j++)														//inner loop: yearly random model for T years
		{
			double E = e();
			EP = Enviornmental(EP, RB, RD, E);
			//cout << E << " " << EP << endl;
			if(EP < 1)
			{
				k++;																	//k counts the number of times population drops to virtually zero
				break;																	//the inner loop then stops, outer loop still continues
			}
		}
	}
	double RE = k / 100.0; 
	
	cout.setf(ios::fixed);
	cout.precision(2);
	
	cout << "Model              Years           Population     Extinction" << endl;
	cout << "Deterministic    " << setw(7) << T << setw(21) << DPT << setw(15) << EX << endl;
	cout << "Enviornmental    " << setw(7) << T << setw(21) << EPT << "    Prob = "<< RE << endl;
	
	return 0;
}