#include <iostream>
using namespace std;

int main() {
    int i, j;
    for (i = 2; i <= 9; i++) {
        cout << "\nBang cuu chuong " << i << ":" << endl;
        for (j = 1; j <= 10; j++) {
            cout << "  " << i << " x " << j << " = " <<  i*j << endl;
        }
    }

    return 0;
}