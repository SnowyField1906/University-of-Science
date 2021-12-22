#include <iostream>
using namespace std;

int main() {
    int n = 1, S = 0;
    while (S <= 1000) {
        S += n;
        n ++;
    }

    cout << "Gia tri n thoa man la: n = " << n - 1;
    
    return 0;
}