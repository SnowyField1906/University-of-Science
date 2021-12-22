#include <iostream>
using namespace std;

int main() {
    int n, next;
    cout << "Nhap n: "; cin >> n;

    cout << n << " so hang dau cua chuoi Fibonacci: ";

    int i = 0;
    if (n <= 2) {
        int i = 0;
        while (i < n) {
            cout << i << " ";
            i ++;
        }
    }

    else {
        int u = 0, v = 1;
        cout << "0 1 ";
        while (i <= n-3) {
            next = u + v;
            u = v;
            v = next;
            cout << v << " ";
            i ++;
        }
    }
    
    return 0;
}