#include <iostream>
#include <fstream>
#include "MyFunctions.h"

using namespace std;

void Out(ofstream &FileOut) {
    FileOut.open("output.txt", ios_base:: out);
}
