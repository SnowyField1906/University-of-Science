#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double x, n, i, S;
    cout << "Nhap vao x: "; cin >> x;
    cout << "Nhap vao n: "; cin >> n;
    for (i = 1; i <= n; i++) {
        S +=  1/(i+1)*pow(x, i);
    }
    cout << "Gia tri bieu thuc la: " << S;

    return 0;
}