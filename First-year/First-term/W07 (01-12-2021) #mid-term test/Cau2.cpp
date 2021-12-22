#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double x, n, i, S;
    cout << "Nhap vao x: "; cin >> x;
    cout << "Nhap vao n: "; cin >> n;
    for (i = 1; i <= n; i++) {
        S +=  pow(i, 2)*pow(x, i)*pow(-1, i + 1);
    }
    cout << "Gia tri bieu thuc la: " << S;

    return 0;   
}