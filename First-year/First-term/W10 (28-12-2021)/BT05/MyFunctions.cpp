#include <iostream>
#include <fstream>
#include "MyFunctions.h"

using namespace std;

void In(ifstream &FileIn) {
    FileIn.open("input.txt", ios_base:: in);
}
