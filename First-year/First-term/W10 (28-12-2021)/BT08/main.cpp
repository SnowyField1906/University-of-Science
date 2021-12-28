#include <iostream>
#include <fstream>
#include <string>
#include "MyFunctions.h"

using namespace std;

int main() {
    ifstream FileIn;
    In(FileIn);

    string s;
    getline(FileIn, s);
    for (int i = 0; i < s.size(); i++) {
        if ('a' <= s[i] && s[i] <= 'z') {
            s[i] -= 32;
        }
    }

    ofstream FileOut;
    Out(FileOut);
    FileOut << s;
    
    FileIn.close();
    FileOut.close();

    return 0;
}