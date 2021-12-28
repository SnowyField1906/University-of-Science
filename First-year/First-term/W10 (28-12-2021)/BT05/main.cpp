#include <iostream>
#include <fstream>
#include "MyFunctions.h"

using namespace std;

int main() {
    ifstream FileIn;
    In(FileIn);
    
    string s;
    getline(FileIn, s);
    cout << s << endl;

    FileIn.close();

    return 0;
}