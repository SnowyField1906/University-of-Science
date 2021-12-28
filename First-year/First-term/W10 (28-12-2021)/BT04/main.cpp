#include <iostream>
#include <fstream>
#include "MyFunctions.h"

using namespace std;

int main() {
    ofstream FileOut;
    
    cout << "Nhap van ban: ";
    string s;
    getline(cin, s);
    
    Out(FileOut);
    FileOut << s;

    FileOut.close();

    return 0;
}