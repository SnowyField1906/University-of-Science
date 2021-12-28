#include <iostream>
#include <fstream> 
#include "MyFunctions.h"

using namespace std;

int main() {
    ifstream FileIn1;
    ifstream FileIn2;
    In1(FileIn1);
    In2(FileIn2);

    string s1, s2;
    getline(FileIn1, s1);
    getline(FileIn2, s2);

    ofstream FileOut;
    Out(FileOut);

    FileOut << s1 + s2;

    FileIn1.close();
    FileIn2.close();
    FileOut.close();
    
    return 0;
}