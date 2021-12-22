#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    if (((0 < a) && (a <= pow(10, 9))) &&
        ((0 < b) && (b <= pow(10, 9))) &&
        ((0 < c) && (c <= pow(10, 9)))) {
            a = a + b + c;
            c = a - b - c;
            b = a - b - c;
            a = a - b - c;
            cout << a << " " << b << " " << c;
        }
    else {
        cout << "Vui long nhap dung gia tri";
    }
    return 0;
}