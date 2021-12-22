#include <iostream>
#include <math.h>
using namespace std;

void tong() {
    double n1, n2, i;
    int b, a;
    cout << "Nhap vao so nguyen n: "; cin >> n1;
    
    n2 = n1;
    int len = 1;
    if (10 <= n1 && n1 <= 100000) {
        while (n1 >= 10) {
            n1 = n1/10;
            len++;
        }
        for (i = len; i >= 0; i = i - 1) {
            b = (int)pow(10, len-1);
            a = (int)(n2/b)%10;
            if (a == 1) cout << "One ";
            if (a == 2) cout << "Two ";
            if (a == 3) cout << "Three ";
            if (a == 4) cout << "Four ";
            if (a == 5) cout << "Five ";
            if (a == 6) cout << "Six ";
            if (a == 7) cout << "Seven ";
            if (a == 8) cout << "Eight ";
            if (a == 9) cout << "Nine ";
            if (a == 0) cout << "Zero ";
            n2 /= 10;
        }

    }
    else {
        cout << "Vui long nhap dung gia tri";
    }
}

int main() {
    tong();
    return 0;
}