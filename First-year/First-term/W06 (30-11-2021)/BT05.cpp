#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int x, n, i;
	cout << "Nhap x: "; cin >> x;
    cout << "Nhap n: "; cin >> n;

    int S = 0;
    for (i = 0; i <= n; i++) {
        S += pow(x, i);
    }

    cout << "Gia tri cua bieu thuc la: S = " << S;
    
    return 0;
}