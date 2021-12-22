#include <iostream>
using namespace std;
 
int main() {
    int n, i;
    cout << "Nhap n: "; cin >> n;
 
    bool prime = true;
    for (i = 2; i <= n/2; i++) {
        if (n%i == 0) {
            prime = false;
            break;
        }
    }

    if (prime == true) {
        cout << n << " la so nguyen to";
    }
    else {
        cout << n << " khong phai la so nguyen to";
    }
    
   return 0;
}