#include <iostream>
#include <fstream>
#include "MyFunctions.h"

using namespace std;

int main() {
    ifstream FileIn;
    In(FileIn);
    
    int a, b, c;
    FileIn >> a >> b >> c;

    ofstream FileOut;
    
    Out(FileOut);
    FileOut << a << " " << b << " " << c;

    FileIn.close();
    FileOut.close();
    
    return 0;
}