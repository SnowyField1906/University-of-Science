#include <iostream>
using namespace std;

int main() {
    int n, next, i;
    cout << "Nhap n: "; cin >> n;

    cout << n << " so hang dau cua chuoi Fibonacci: ";

    if (n <= 2) {
        int i = 0;
        for (i = 0; i < n; i++) {
            cout << i << " ";
        }
    }

    else {
        int u = 0, v = 1;
        cout << "0 1 ";
        for (i = 0; i <= n-3; i++) {
            next = u + v;
            u = v;
            v = next;
            cout << v << " ";
        }
    }
    
    return 0;
}