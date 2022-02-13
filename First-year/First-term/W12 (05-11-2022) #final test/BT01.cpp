#include <iostream>
#include <math.h>

using namespace std;

void Input(double &n) {
    cout << "Moi nhap n = "; cin >> n;
}

double TongS(double n) {
    double S = 0;
    int i;
    for (i = 1; i <= n; i++) {
        if (i%2 == 0) {
            S -= ((2.0*i - 1.0)*(i + 1.0)*(i + 1.0))/(2.0*i);
        }
        else {
             S += ((2.0*i - 1.0)*(i + 1.0)*(i + 1.0))/(2.0*i);
        }
    }
    return S;
}

int main() {
    double n;
    Input(n);
    cout << "Tong S la: S = " << TongS(n) << endl;

    return 0;
}