#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int money, i;
    cin >> money;

    if ((0 < money) && (money <= pow(10, 9))) {
        i = 0;
        while (money >= 500000) {
            money -=  500000;
            i += 1;
        }
        cout << "500000: " << i << endl;
        
        i = 0;
        while (money >= 200000) {
            money -=  200000;
            i += 1;
        }
        cout << "200000: " << i << endl;

        i = 0;
        while (money >= 100000) {
            money -=  100000;
            i += 1;
        }
        cout << "100000: " << i << endl;

        i = 0;
        while (money >= 50000) {
            money -=  50000;
            i += 1;
        }
        cout << "50000: " << i << endl;

        i = 0;
        while (money >= 20000) {
            money -=  20000;
            i += 1;
        }
        cout << "20000: " << i << endl;

        i = 0;
        while (money >= 10000) {
            money -=  10000;
            i += 1;
        }
        cout << "10000: " << i << endl;

        i = 0;
        while (money >= 5000) {
            money -=  5000;
            i += 1;
        }
        cout << "5000: " << i << endl;

        i = 0;
        while (money >= 2000) {
            money -=  2000;
            i += 1;
        }
        cout << "2000: " << i << endl;

        i = 0;
        while (money >= 1000) {
            money -=  1000;
            i += 1;
        }
        cout << "1000: " << i << endl;
    }
    else {
        cout << "Vui long nhap dung gia tri";
    }
    return 0;
}