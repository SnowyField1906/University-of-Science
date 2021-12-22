#include <iostream>
using namespace std;

int main() {
    int i = 2;
    while (i <= 9) {
        cout << "\nBang cuu chuong " << i << ":" << endl;
        int j = 1;
        while (j <= 10) {
            cout << "  " << i << " x " << j << " = " <<  i*j << endl;
            j ++;
        }
        i ++;
    }

    return 0;
}