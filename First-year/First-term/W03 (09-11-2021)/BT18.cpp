#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    if (((0 < a) && (a <= pow(10, 9))) && ((0 < b) && (b <= pow(10, 9)))) {
        a = a + b;
        b = a - b;
        a = a - b;
        cout << a << " " << b;
    }
    else {
        cout << "Vui long nhap dung gia tri";
    }
    return 0;
}