#include<iostream>
using namespace std;

int main() {
    int plate;
    int n = 0;
    cin >> plate;
    
    if ((10000 <= plate) && (plate <= 99999)) {
        while (plate > 0) {
            n = n + plate % 10;
            plate = plate / 10;
        }
        cout << n % 10;
    }
    else {
        cout << "Vui long nhap dung gia tri";
    }
    return 0;
}