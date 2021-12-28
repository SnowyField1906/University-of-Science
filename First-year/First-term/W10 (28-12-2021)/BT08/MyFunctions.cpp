#include <iostream>
#include <fstream>
#include <string>
#include "MyFunctions.h"

using namespace std;

void In(ifstream &FileIn) {
    FileIn.open("input.txt", ios_base:: in);
}

void Out(ofstream &FileOut) {
    FileOut.open("output.txt", ios_base:: out);
}
