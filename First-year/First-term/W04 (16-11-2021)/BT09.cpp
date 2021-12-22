#include <iostream>
using namespace std; 
 
int main() {
    int month, year;
    cout << "Nhap vao mot thang: "; cin >> month;
    cout << "Hay nhap nam cua thang do: "; cin >> year;
 
    switch(month) {
        case 1: 
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << "Thang " << month  << " co 31 ngay";
            break;

        case 2:
            if ((year%400 == 0) || ((year%4 == 0) && (year%100 != 0))) {
                cout << "Thang " << month  << " co 29 ngay";
            }
            else {
                cout << "Thang " << month  << " co 28 ngay";
            }
            break;

        case 4: 
        case 6: 
        case 9:
        case 11: 
            cout << "Thang " << month  << " co 30 ngay";
            break;

        default: 
            cout << "Thang khong hop le";
    }

    return 0;
}