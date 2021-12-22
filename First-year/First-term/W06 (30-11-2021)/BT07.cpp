#include <iostream>
using namespace std;

int main() {
    int S = 0, n;
    for (n = 1; S <= 1000; n++) {
        S += n;
    }

    cout << "Gia tri n thoa man la: n = " << n - 1;
    
    return 0;
}