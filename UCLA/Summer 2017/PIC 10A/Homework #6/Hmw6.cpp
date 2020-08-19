/*
Homework #6
Author: James Mathias
Email: jgmathias@g.ucla.edu
Course: PIC 10A Summer 2017
Collaborators: N/A

Honesty Pledge:
I, James Mathias, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.

User inputs: battleship target
Output: hit or miss and percent of success
List of known bugs: none
*/

#include <iostream>
#include <iomanip>
#include <string>
//#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int RandPos(int loc)																	//function to get random integer
{
	int pos = rand() % loc;
	return pos;
}

void pagedown(int n)																	//function to skip a number of lines
{
	for(int i = 0; i < n; i++)
	{
		cout << endl;
	}
}

int main()
{
	srand(time(0));
	
	const int locations = 10;
	const int ships = 3;
	const int tries = 3;
	
	vector<int> game(locations);														//0 for empty space, 1 for ship
	game.assign(locations, 0);
	for(int a = 1; a <= ships; a++)
	{
		int position = RandPos(locations);
		game[position] = 1;
	}
	
	vector<string> display(locations);													//all displayed positions are " ---" at beginning of game
	display.assign(locations, " ---");
	
	int hits = 0;
	for(int b = 1; b <= tries; b++)
	{
		for(int c = 0; c < locations; c++)												//displaying hits and misses
		{
			cout << display[c];
		}
		
		int shot;
		cout << " Shot " << b << " Location: ";
		cin >> shot;
		shot--;
		
		while(shot < 0 || shot > locations - 1 || game[shot] == 2 || game[shot] == 3)	//checking for valid input
		{
			cout << setw(4 * locations)<< " Location Input Error, Try Again:";
			cout << " Shot " << b << " Location: ";
			cin >> shot;
			shot--;
		}
		
		if(game[shot] == 1)																//if (ship in that position) {hit: <*>} else (miss: *)
		{
			game[shot] = 3;
			display[shot] = " <*>";
			hits++;
		}
		else
		{
			game[shot] = 2;
			display[shot] = "  * ";
		}
		
		pagedown(10);																	//skip 10 lines
		
		int sum = 0;																	//if all ships are hit, then break loop and go to results
		for(int d = 0; d < locations; d++)
		{
			if(game[d] == 1)
			{
				sum++;
			}
		}
		if(sum == 0)
		{
			break;
		}
	}
	
	
	int missed = 0;
	for(int e = 0; e < locations; e++)													//missed ships now will display as <=>
	{
		if (game[e] == 1)
		{
			display[e] = " <=>";
			missed++;
		}
	}
	
	for(int f = 0; f < locations; f++)													//final display
	{
		cout << display[f];
	}
	
	int success = hits * 100.0 / (hits + missed);										//percentage of success
	cout << " Success = " << success << "%" << endl;
	
	return 0;
}