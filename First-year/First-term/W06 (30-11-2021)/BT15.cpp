#include <iostream>
using namespace std;

int main() {
    int n, next, i;
    cout << "Nhap n: "; cin >> n;

    if (n <= 2) {
        int i = 0;
        for (i = 0; i < n; i++) {
        }
        cout << "So thu " << n << " cua chuoi Fibonacci la " << i - 1;
    }

    else {
        int u = 0, v = 1;
        for (i = 0; i <= n-3; i++) {
            next = u + v;
            u = v;
            v = next;
        }
        cout << "So thu " << n << " cua chuoi Fibonacci la " << next;

    }
    
    return 0;
}