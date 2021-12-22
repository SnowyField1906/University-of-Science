#include <iostream>
using namespace std;
 
int main() {
    int n;
    cout << "Nhap n: "; cin >> n;
 
    int i = 2;
    bool prime = true;
    while (i <= n/2) {
        if (n%i == 0) {
            prime = false;
            break;
        }
        i ++;
    }

    if (prime == true) {
        cout << n << " la so nguyen to";
    }
    else {
        cout << n << " khong phai la so nguyen to";
    }
    
   return 0;
}