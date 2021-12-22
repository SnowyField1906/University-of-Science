#include <iostream>
    #include <math.h>
using namespace std;

int main() {
    double a, b;
    cout << "Nhap he so a: "; cin >> a;
    cout << "Nhap he so b: "; cin >> b;

    if (a == 0) {
        if (b == 0) {
            cout << "Phuong trinh co vo so nghiem";
        }
        else {
            cout << "Phuong trinh vo nghiem";
        }
    }

    else {
        cout << "Nghiem cua phuong trinh la: x = " << -b/a;
    }
    
    return 0;
}