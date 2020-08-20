#include <iostream>
using namespace std;
const int CellSize = 6;
bool C = true;

bool BitAdd(bool b1, bool b2){
    if(b1 == true && b2 == true){
        if(C == true){
            C = true;
            return true;
        }
        else{
            C = true;
            return false;
        }
    }
    
    if((b1 == false && b2 == true) || (b1 == true && b2 == false))
    {
        if(C == true){
            C = true;
            return false;
        }
        else{
            C = 0;
            return true;
        }
    }
    if(b1 == false && b2 == false)
    {
        if(C == true){
            C = false;
            return true;
        }
        else{
            C = false;
            return false;
        }
    }
    
return false;
}

void ConvertDecToBinary(int number, bool output[]){
    if(number == 0)
        output[0] = 0;
    else{
        for (int i= 0; number > 0; i++) {
            output[CellSize-1-i] = number % 2;
            number /= 2;
        }
    }
}

int main() {
    int number = 0;
    
    
    cout << "1 + 1 = " << BitAdd(1, 1) << ", C= " << C << endl;
    
    
    cout << endl;
    return 0;
}

