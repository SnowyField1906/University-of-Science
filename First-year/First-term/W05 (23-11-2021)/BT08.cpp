#include <iostream>
using namespace std;

int main() {
    int a, b, UCLN, BCNN;
    cout << "Nhap so thu nhat: "; cin >> a;
    cout << "Nhap so thu hai: "; cin >> b;

    int i = 1;
    while (i <= (a+b)/2) {
        if ((a%i == 0) and (b%i == 0)) {
            UCLN = i;
        }
        i ++;
    }

    BCNN = (a*b)/UCLN;

    cout << "UCLN cua 2 so a va b la: " << UCLN << endl;
    cout << "BCNN cua 2 so a va b la: " << BCNN;
    
    return 0;
}