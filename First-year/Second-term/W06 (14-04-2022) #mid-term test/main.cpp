#include <iostream>
#include <string.h>
#include "MyFunctions.h"

using namespace std;

struct Cat {
    int id;
    char* type = new char[10];
    char* color = new char[10];
    float weight;
};

////////////////////////

int main() {
    int n = 0;
    Cat* catList = NULL;
    Cat* newCatList = NULL;

    catList = createArray(n);

    menu(catList, newCatList, n);
    
    for (int i = 0; i < n; i++) {
        delete[] catList[i].type;
        delete[] catList[i].color;
    }

    deleteArray(catList);
    cout << sizeof(newCatList);

    return 0;
}