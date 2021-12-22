#include <iostream>
using namespace std;

int main() {
    int n, i;
    cout << "Nhap n: "; cin >> n;

    int Q = 1, S = 0;
    for (i = 1; i <= n; i++) {
        Q *= i;
        S += Q;
    }

    cout << "Gia tri cua bieu thuc la: S = " << S;
    
    return 0;
}