#include <iostream>
#include <string>
using namespace std;

int main()
{
  unsigned int number;
  
  cout << "input unsigned number: ";
  cin >> number;
  
  string binary;
  unsigned int a;
  
  do
  {
      a = number % 2;
      binary.insert(0,to_string(a));
      number /= 2;
  }
  while(number > 0);
  
  cout << binary;
  
  system("pause");
  return 0;
}
