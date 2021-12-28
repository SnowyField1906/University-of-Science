#include <iostream>
#include <fstream>
#include "MyFunctions.h"

using namespace std;

void Swap(int &x, int &y) {
    int e;
    e = x;
    x = y;
    y = e;
}

void Sort(int n, int list[]) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++)  {
            if (list[i] >= list[j]) {
                Swap(list[i], list[j]);
            }
        }
    }
}

void In(ifstream &FileIn, int &n, int list[]) {
    FileIn >> n;
    for (int i = 0; i < n; i++) {
        FileIn >> list[i];
    }
}

void Out(ofstream &FileOut, int n, int list[]) {
    Sort(n, list);
    for (int i = 0; i < n; i++)
    {
        FileOut << list[i] << " ";
    }
}