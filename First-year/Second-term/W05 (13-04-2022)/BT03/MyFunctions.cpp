#include <iostream>
#include <fstream>
#include "MyFunctions.h"

using namespace std;

////////// ĐẾM KÍ TỰ //////////

int Count(fstream& fin) {
    char c;
    int count = 0;
    while (fin.get(c)) {
        count++;
    }
    return count;
}