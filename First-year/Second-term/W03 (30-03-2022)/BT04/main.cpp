#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "MyFunctions.h"

using namespace std;

int main() {
    int N = 0;

    int *array = NULL;

    char ans;

    cout << endl << "\t====== INPUT ======" << endl << endl;
    InputArray(array, N);

    cout << endl << "\t====== OUTPUT ======" << endl << endl;
    OutputArray(array, N);

    cout << endl << "Do you want to sort the array in Ascending or Descending order? (A/D): ";
    cin >> ans;

    while (ans != 'A' && ans != 'D') {
        cout << endl << "Please input \"A\" for Ascending order and \"D\" for Desending order! (A/D): ";
        cin >> ans;
    }

    if (ans == 'A') {
        cout << endl << "\t====== SORT ASCENDING ======" << endl << endl;
        qsort(array, N, sizeof(int), SortAsc);
        OutputArray(array, N);
    }

    if (ans == 'D') {
        cout << endl << "\t====== SORT DESCENDING ======" << endl << endl;
        qsort(array, N, sizeof(int), SortDesc);
        OutputArray(array, N);
    }
    
    DeleteArray(array);

    return 0;
}