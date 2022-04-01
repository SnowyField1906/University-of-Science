#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "MyFunctions.h"

using namespace std;

int* CreateArray(int N) {
    int* array = new int[N];
    if (array == NULL) {
        return NULL;
    }
    else {
        return array;
    }
}

void DeleteArray(int *&array) {
    if (array != NULL) {
        delete[] array;
    }
    array = NULL;
}

void InputArray(int *&array, int &N) {
    cout << "Input the number of variables: ";
    cin >> N;
    array = CreateArray(N);
    for (int i = 0; i < N; i++) {
        cout << "The variable " << i + 1 << ": ";
        cin >> *(array + i);
    }
}

void OutputArray(int *array, int N) {
    if (array != NULL) {
        for (int i = 0; i < N; i++) {
            cout << *(array + i) << " ";
        }
        cout << endl;
    }
    else {
        cout << "NULL";
    }
}

int SortAsc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int SortDesc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}