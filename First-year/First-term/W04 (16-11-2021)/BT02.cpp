#include <iostream>
using namespace std;

int main() {
    char n;
    cout << "Nhap mot chu cai: "; cin >> n;

    if ((64 < (int)n) && ((int)n < 91)) {
        cout << "Chu thuong la: " << char(int(n) + 32);
    }
    
    else {
        if ((96 < (int)(n)) && ((int)n < 123)) {
            cout << "Chu hoa la: " << char((int)n - 32);
        }
        else {
            cout << "Vui long nhap chu cai";
        }
    }

    return 0;
}