//James Mathias
//Apr 30, 2019
//CS 940
//Chapter 15 Assignment: Sequence Sum

#include <iostream>
using namespace std;

class AbstractSeq
{
public:
	AbstractSeq();
	void PrintSeq(int i, int j);
	int SumSeq(int i, int j);

private:
	int Fun(unsigned int i);
	int Sum(int i);
};

AbstractSeq::AbstractSeq()
{

}

inline void AbstractSeq::PrintSeq(int i, int j)
{
	cout << Fun(i);
	int I = i;
	while (I < j)
	{
		I++;
		cout << ", " << Fun(I);
	}
}

inline int AbstractSeq::SumSeq(int i, int j)
{
	return (Sum(j) - Sum(i));
}

int AbstractSeq::Fun(unsigned int i)
{
	return (2 * i + 1);
}

inline int AbstractSeq::Sum(int i)
{
	int I = i;
	int sum = 0;

	while (I > 0)
	{
		sum += Fun(I);
		I--;
	}

	return sum;
}