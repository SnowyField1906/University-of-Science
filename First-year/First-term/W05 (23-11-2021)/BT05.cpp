#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int x, n;
	cout << "Nhap x: "; cin >> x;
    cout << "Nhap n: "; cin >> n;

    int i = 0, S = 0;
    while (i <= n) {
        S += pow(x, i);
        i ++;
    }

    cout << "Gia tri cua bieu thuc la: S = " << S;
    
    return 0;
}