#include <iostream>
using namespace std;

int main() {
    int km;
    cout << "Nhap so km: "; cin >> km;

    if (km <= 1) {
        cout << "Tien taxi la: " << 15000;
    }
    if ((2 <= km) && (km <= 5)) {
        cout << "Tien taxi la: " << 15000 + (km - 1)*13500;
    }
    if ((6 <= km) && (km <= 120)) {
        cout << "Tien taxi la: " << 15000 + 4*13500 + (km - 5)*11000;
    }
    if (km > 120) {
        cout << "Tien taxi la: " << (15000 + 4*13500 + (km - 5)*11000)/10;
    }

    return 0;
}
    