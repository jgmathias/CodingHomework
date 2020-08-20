//CS816
//Binary Converter Menu

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const int CellSize = 8;

int main()
{
	int Choice = 0;
	
	while (Choice != 6)
	{
		cout << "Menu" << endl
			<< endl
			<< "1 - Convert an unsigned binary number to a decimal" << endl
			<< "2 - Convert a positive decimal number to unsigned binary" << endl
			<< "3 - Convert a signed binary number in sign-bit representation to decimal" << endl
			<< "4 - Convert a decimal number to a binary number in sign-bit representation" << endl
			<< "5 - Convert a decimal number to binary number in two's complement representation" << endl
			<< "6 - Exit" << endl
			<< endl
			<< "Enter your choice (1-6): ";
		cin >> Choice;
		cout << endl;
        
		string bin = "00000000";
		int dec = 0;
		int size = 0;
		bool C = 0;
		bool N = 0;
	
		switch (Choice)
		{
			case 1:
				cout << "Enter an unsigned " << CellSize << "-bit binary number: ";
				cin >> bin;
				
				size = bin.size();
				if (size > CellSize)
				{
					for(int i = 0; i < size - CellSize; i++)
					{
						if(bin[i] = '1')
						{
							C = 1;
							break;
						}
					}
				}
				
				for (int i = 0; i < min(CellSize, size); i++)
				{
					if (bin[size - 1 - i] == '1')
					{
						dec += pow(2, i);
					}
				}
				
				cout << "C = " << C << endl;
				cout << dec << endl;
			break;
			
			case 2:
				size = pow(2, CellSize);
				cout << "Enter a positive decimal integer less than " << size << ": ";
				cin >> dec;
				
				if (dec >= size)
				{
					C = 1;
				}
				while (dec < 0)
				{
					C = 1;
					N = 1;
					dec += size;
				}
				
				for (int i = CellSize - 1; i >= 0; i--)
				{
					if (dec % 2 == 1)
					{
						bin[i] = '1';
					}
					dec /= 2;
					}
				
				cout << "C = " << C << endl;
				cout << bin << endl;
			break;
			
			case 3:
				cout << "Enter a signed " << CellSize << "-bit binary number in sign-bit representation: ";
				cin >> bin;
				
				size = bin.size();
				if (size > CellSize)
				{
					for(int i = 1; i < size + 1 - CellSize; i++)
					{
						if(bin[i] = '1')
						{
							C = 1;
							break;
						}
					}
				}
				
				for (int i = 0; i < min(CellSize, size) - 1; i++)
				{
					if (bin[size - 1 - i] == '1')
					{
						dec += pow(2, i);
					}
				}
				if (bin[0] == '1')
				{
					N = 1;
					dec *= -1;
				}
				
				cout << "C = " << C << endl;
				cout << dec << endl;
			break;
	
			case 4:
				size = pow(2, CellSize - 1);
				cout << "Enter a decimal integer with a magnitude less than " << size << ": ";
				cin >> dec;
				
				if (dec >= size || dec <= size * -1)
				{
					C = 1;
				}
				if (dec < 0)
				{
					N = 1;
					dec *= -1;
					bin[0] = '1';
				}
				
				for (int i = CellSize - 1; i > 0 ; i--)
				{
					if (dec % 2 == 1)
					{
						bin[i] = '1';
					}
					dec /= 2;
				}
	
				cout << "C = " << C << endl;
				cout << bin << endl;
			break;
			
			case 5:
				size = pow(2, CellSize);
				cout << "Enter a decimal integer with a magnitude less than " << size << ": ";
				cin >> dec;
				
				if (dec >= size || dec <= size * -1)
				{
					C = 1;
				}
				if (dec < 0)
				{
					N = 1;
					dec *= -1;
				}
				
				for (int i = CellSize - 1; i >= 0 ; i--)
				{
					if (dec % 2 == 1)
					{
						bin[i] = '1';
					}
					dec /= 2;
				}
				if (N == 1)
				{
					int j = CellSize - 1;
					do
					{
						j--;
					}
					while(bin[j + 1] == '0' && j != -1);
					for(int k = j; k >= 0; k--)
					{
						if (bin[k] == '0')
						{
							bin[k] = '1';
						}
						else
						{
							bin[k] = '0';
						}
					}
				}
				
				cout << "C = " << C << endl;
				cout << bin << endl;
			break;
			
			case 6:
			break;
			
			default:
			cout << "The choice must be 1, 2, 3, 4, 5, or 6." << endl;
		}
        
		cout << endl;
	}
	
	cout << endl;
	system("pause");
	return 0;
}
