#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n, max1, max2;
    int a = 1;
    bool end = false;
    cout << "Nhap vao so nguyen n: "; cin >> n;

    if (10 <= n && n <= 100000) {
        if (n%10 != 0) {
            max1 = a;
            max2 = a;
            while(n > 0) {
                a = n%10;
                if (end == false) {
                    if (a != 0) {
                        if (a > max1) {
                            max1 = a;
                        }
                        else if (a > max2) {
                            max2 = a;
                        }
                        cout << a;
                        end = true;
                    }
                    else {
                        cout << "Vui long nhap dung gia tri";
                    }
                }

                else {
                    if (a > max1) {
                        max1 = a;
                    }
                    else if (a > max2) {
                        max2 = a;
                    }
                    cout << a;
                }

                n = n/10;
            }
            cout << "\nSo lon thu nhat la: " << max1 << endl;
            cout << "So lon thu nhi la: " << max2;
        }
        else {
            cout << "Vui long nhap dung gia tri";
        }
    }

    else {
        cout << "Vui long nhap dung gia tri";
    }

    return 0;
}