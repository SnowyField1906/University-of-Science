#include <iostream>
#include <fstream>
#include "MyFunctions.h"

using namespace std;

int main() {
    ifstream FileIn;
    FileIn.open("input.txt", ios_base::in);
    
    int list[100];
    int n;
    In(FileIn, n, list);

    ofstream FileOut;
    FileOut.open("output.txt", ios_base::out);
    Out(FileOut, n, list);

    FileIn.close();
    FileOut.close();

    return 0;
}