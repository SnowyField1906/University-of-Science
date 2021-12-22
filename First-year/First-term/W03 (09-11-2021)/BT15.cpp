#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

#define PI 3.14
#define e 2.71

int main() {
    double x, y1, y2;
    cin >> x;
    y1 = 4*(pow(x, 2) + 10*x*sqrt(x) + 3*x + 1);
    y2 = (sin(PI*pow(x, 2)) + sqrt(pow(x, 2) + 1))/(pow(e, 2*x) + cos(PI/4*x));

    if (0 <= x && x <= pow(10, 9)) {
        cout << fixed << setprecision(10) << y1 << " " << y2;
    }
    else {
        cout << "Vui long nhap dung gia tri";
    }
    return 0;
}