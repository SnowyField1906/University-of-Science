#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: "; cin >> n;

    double i = 2, S = 1;
    while (i <= n) {
        S += 1/((i-1)*i);
        i ++;
    }

    cout << "Gia tri cua bieu thuc la: S = " << S;
    
    return 0;
}