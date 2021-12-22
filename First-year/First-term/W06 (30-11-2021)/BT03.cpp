#include <iostream>
using namespace std;

int main() {
    double n, i;
    double S = 1;
    cout << "Nhap n: "; cin >> n;

    for (i=2; i <= n; i++) {
        S += 1/((i-1)*i);
    }
    
    cout << "Gia tri cua bieu thuc la: S = " << S;
    
    return 0;
}