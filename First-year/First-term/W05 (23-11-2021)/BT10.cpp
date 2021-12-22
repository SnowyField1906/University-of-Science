#include <iostream>
using namespace std;
 
int main() {
    int n;
    cout << "Nhap n: "; cin >> n;
    
    int a = 2;
    cout << "Cac so nguyen to nho hon n la: ";
    while (a < n) {
        int i = 2;
        bool prime = true;
        while (i <= a/2) {
            if (a%i == 0) {
                prime = false;
                break;
            }
            i ++;
        }

        if (prime == true) {
            cout << a << " ";
        }
        a ++;
    }
    
   return 0;
}