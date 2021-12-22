#include <iostream>
using namespace std;

int main() {
    int n, next;
    cout << "Nhap n: "; cin >> n;

    int i = 0;
    if (n <= 2) {
        int i = 0;
        while (i < n) {
            i ++;
        }
        cout << "So thu " << n << " cua chuoi Fibonacci la " << i - 1;
    }

    else {
        int u = 0, v = 1;
        while (i <= n-3) {
            next = u + v;
            u = v;
            v = next;
            i ++;
        }
        cout << "So thu " << n << " cua chuoi Fibonacci la " << next;

    }
    
    return 0;
}