#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: "; cin >> n;

    int i = 1, Q = 1, S = 0;
    while (i <= n) {
        Q *= i;
        S += Q;
        i ++;
    }

    cout << "Gia tri cua bieu thuc la: S = " << S;
    
    return 0;
}