//CS 836
//Final
//5 of 5

#include <iostream>
#include <string>
using namespace std;

#include "cstack.h"
#include "cqueue.h"


bool isPalindrome(CStack& stack, CQueue& queue, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (stack.Top() == queue.getChar(-1))
		{
			stack.Pop();
			queue.Dequeue();
		}
		else
		{
			return false;
		}
	}

	return true;
}

int main()
{
	const int MaxSize = 100;
	string input;

	cout << "Please enter a string to test for palindrome or type QUIT to exit: ";
	getline(cin, input);

	while (!(input.length() == 4 && toupper(input[0]) == 'Q' && toupper(input[1]) == 'U' && toupper(input[2]) == 'I' && toupper(input[3]) == 'T'))
	{
		char Input[MaxSize];
		int i = 0;
		for (int j = 0; j < input.length(); j++)
		{
			if (isalpha(input[j]))
			{
				Input[i] = toupper(input[j]);
				i++;
			}
		}

		int Size = i;

		CStack Stack;
		for (int k = 0; k < Size; k++)
		{
			Stack.Push(Input[k]);
		}

		CQueue Queue;
		for (int l = 0; l < Size; l++)
		{
			Queue.Enqueue(Input[l]);
		}

		if (isPalindrome(Stack, Queue, Size))
		{
			cout << input << endl;
			cout << "The input is a palindrome." << endl;
		}
		else
		{
			cout << input << endl;
			cout << "The input is not a palindrome." << endl;
		}

		cout << endl;
		cout << "Please enter a string to test for palindrome or type QUIT to exit: ";
		getline(cin, input);
	}

	cout << endl;
	system("PAUSE");
	return 0;
}