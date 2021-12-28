#include <iostream>
#include <fstream>
#include <string>
#include "MyFunctions.h"

using namespace std;

int main() {
    ifstream FileIn;
    In(FileIn);
    
    string s;
    int dem = 0;
    getline(FileIn, s);
    for (int i = 0; i < s.length(); i++) {
        if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))
            dem++;
    }

    ofstream FileOut;
    Out(FileOut);
    FileOut << "Co " << dem << " tu";

    FileIn.close();
    FileOut.close();

    return 0;
}