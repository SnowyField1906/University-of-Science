#include <iostream>
using namespace std;
 
int main() {
    int n, a, i;
    cout << "Nhap n: "; cin >> n;
    cout << "Cac so nguyen to nho hon n la: ";

    for (a = 2; a < n; a++) {
        bool prime = true;
        for (i = 2; i <= a/2; i++) {
            if (a%i == 0) {
                prime = false;
                break;
            }
        }

        if (prime == true) {
            cout << a << " ";
        }
    }
    
   return 0;
}