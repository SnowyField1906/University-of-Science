//Tính tổng: S = 1/1 + 2/(1+2) + 3/(1+2+3) + ... + n/(1+2+3+...+n)

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double i, j;
    double S = 0, P;
    cout << "Input number: "; cin >> n;

    for (i = 1; i <= n; i++) {
        P = 0;
        for (j = 1; j <= i; j++) {
            P += j;
        }
        S += i/P;
    }

    cout << fixed << setprecision(3) << "S = " << S;

    return 0;
}