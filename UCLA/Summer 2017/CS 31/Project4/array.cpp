// Code for Project 4
// String Arrays

#include <iostream>
//#include <iomanip>
#include <string>
//#include <cmath>
//#include <cassert>
using namespace std;

string findMaximum(const string array[], int n)
{
	string max = "";
	for(int i = 0; i < n; i++)
	{
		if(array[i] > max)
		{
			max = array[i];
		}
	}
	
	return max;
}

bool hasDuplicatedValues(const string array[], int n)
{
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(array[i] == array[j])
			{
				return true;
			}
		}
	}
	
	return false;
}

int countAllVowels(const string array[], int n)
{
	int vowels = 0;
	if(n <= 0)
	{
		vowels--;
	}
	else for(int i = 0; i < n; i++)
	{
		string temp = array[i];
		for(unsigned int j = 0; j < temp.length(); j++)
		{
			if(temp[j] == 'a' || temp[j] == 'e' || temp[j] == 'i' || temp[j] == 'o' || temp[j] == 'u' || temp[j] == 'y' ||temp[j] == 'A' || temp[j] == 'E' || temp[j] == 'I' || temp[j] == 'O' || temp[j] == 'U' || temp[j] == 'Y')
			{
				vowels++;
			}
		}
	}
	
	return vowels;
}

int countIntegers(const string array[], int n)
{
	
	int integers = 0;
	if(n <= 0)
	{
		integers--;
	}
	else for(int i = 0; i < n; i++)
	{
		if(array[i] == "")
		{
		}
		else
		{
			string temp = array[i];
			integers++;
			for(unsigned int j = 0; j < temp.length(); j++)
			{
				if(temp[j] < '0' || temp[j] > '9')
				{
					integers--;
					break;
				}
			}
		}
	}
	
	return integers;
}

int moveToEnd(string array[], int n, unsigned int pos)
{
	if(pos >= n-1 || sizeof(array) == 0 || n <= 0)
	{
		return -1;
	}
	else 
	{
		string temp = array[pos];
		for(int i = 1; i < n - pos; i++)
		{
			array[pos + i - 1] = array[pos + i];
		}
		array[n - 1] = temp;
	}
	
	return 1;
}

int rotateRight(string array[], int n, unsigned int amount)
{
	int count = 0;
	if(sizeof(array) == 0 || n <= 0)
	{
		count--;
	}
	else for(int i = 1; i <= amount; i++)
	{
		string tempA = array[0];
		string tempB = array[1];
		for(int j = 0; j < n-2; j++)
		{
			array[j + 1] = tempA;
			count++;
			tempA = tempB;
			tempB = array[j + 2];
		}
		array[n - 1] = tempA;
		count++;
		array[0] = tempB;
		count++;
	}
	
	return count;
}

int shiftLeft(string array[], int n, unsigned int amount, string placeholder)
{
	int count = 0;
	if(sizeof(array) == 0 || n <= 0)
	{
		count--;
	}
	else for(int i = 0; i < n; i++)
	{
		if(i < n - amount)
		{
			array[i] = array[i + amount];
		}
		else
		{
			array[i] = placeholder;
			count++;
		}
	}
	
	return count;
}

int divide(string array[], int n, string divider)
{
	int countA = 0;
	int countB = 0;
	if(sizeof(array) == 0 || n <= 0)
	{
		countA--;
	}
	else 
	{
		string tempA[n];
		string tempB[n];
		for(int i = 0; i < n; i++)
		{
			if(array[i] < divider)
			{
				tempA[countA] = array[i];
				countA++;
			}
			else
			{
				tempB[countB] = array[i];
				countB++;
			}
		}
		for(int j = 0; j < countA; j++)
		{
			array[j] = tempA[j];
		}
		for(int k = 0; k < countB; k++)
		{
			array[countA + k] = tempB[k];
		}
	}
	
	return countA;
}

int main()
{
	cout << "succesful tests output 1, failed tests output 0" << endl;
	cout << endl;
	
	string a[6] = {"alpha", "beta", "gamma", "gamma", "beta", "delta"};
	string b[6] = {"delta", "gamma", "beta", "alpha", "beta", "alpha"};
	string c[4] = {"1", "2", "3", "4"};
	string d[5] = {"1", "", "", "2"};
    string h[7] = {"Samwell", "Jon", "Margaery", "Daenerys", "", "Tyrion", "Margaery"};
	int answer;
	
	cout << "findMaximum" << endl;
	cout << (findMaximum(a, 3) == "gamma");
	cout << (findMaximum(b, 3) == "gamma");
	cout << (findMaximum(c, 3) == "3");
	cout << (findMaximum(c, 4) == "4");
	cout << (findMaximum(c, 0) == "");
	cout << endl << endl;
	
	cout << "hasDuplicatedValues" << endl;
	cout << (hasDuplicatedValues(a, 5) == true);
	cout << (hasDuplicatedValues(b, 4) == false);
	cout << (hasDuplicatedValues(d, 4) == true);
	cout << endl << endl;
	
	cout << "countAllVowels" << endl;
	cout << (countAllVowels(a, 3) == 6);
	cout << (countAllVowels(a, 6) == 12);
	cout << (countAllVowels(c, 4) == 0);
	cout << (countAllVowels(h, 6) == 14);
	cout << (countAllVowels(h, 0) == -1);
	cout << endl << endl;
	
	cout << "countIntegers" << endl;
    cout << (countIntegers(a, 6) == 0);
	cout << (countIntegers(h, 6) == 0);
	cout << (countIntegers(c, 4) == 4);
	cout << (countIntegers(c, 3) == 3);
	cout << (countIntegers(d, 4) == 2);
	cout << (countIntegers(c, 0) == -1);
	cout << endl << endl;
	
	cout << "moveToEnd" << endl;
	answer = moveToEnd(a, 3, 0);
		cout << (answer == 1);
		cout << (a[0] == "beta");
		cout << (a[1] == "gamma");
		cout << (a[2] == "alpha");
	answer = moveToEnd(b, 4, 0);
		cout << (answer == 1);
		cout << (b[0] == "gamma");
		cout << (b[1] == "beta");
		cout << (b[2] == "alpha");
		cout << (b[3] == "delta");
	answer = moveToEnd(a, 3, 2);
		cout << (answer == -1);
	cout << endl << endl;
	
	cout << "rotateRight" << endl;
	answer = rotateRight(c, 3, 2);
		cout << (answer == 6);
		cout << (c[0] == "2");
		cout << (c[1] == "3");
		cout << (c[2] == "1");
	answer = rotateRight(d, 4, 6);
		cout << (answer == 24);
		cout << (d[0] == "");
		cout << (d[1] == "2");
		cout << (d[2] == "1");
		cout << (d[3] == "");
	answer = rotateRight(c, 4, 0);
		cout << (answer == 0);
	answer = rotateRight(c, 0, 2);
		cout << (answer == -1);
	cout << endl << endl;
	
	cout << "shiftLeft" << endl;
	answer = shiftLeft(h, 5, 3, "test");
		cout << (answer == 3);
		cout << (h[0] == "Daenerys");
		cout << (h[1] == "");
		cout << (h[2] == "test");
		cout << (h[3] == "test");
		cout << (h[4] == "test");
		cout << (h[5] == "Tyrion");
		cout << (h[6] == "Margaery");
	answer = shiftLeft(h, 4, 0, "test");
		cout << (answer == 0);
	answer = shiftLeft(h, 0, 3, "test");
		cout << (answer == -1);
	cout << endl << endl;
	
	cout << "divide" << endl;
	answer = divide(h, 7, "Test");
		cout << (answer == 3);
		cout << (h[0] == "Daenerys");
		cout << (h[1] == "");
		cout << (h[2] == "Margaery");
		cout << (h[3] == "test");
		cout << (h[4] == "test");
		cout << (h[5] == "test");
		cout << (h[6] == "Tyrion");
	answer = divide(c, 0, "test");
		cout << (answer == -1);
	cout << endl << endl;
		
	return 0; 
}