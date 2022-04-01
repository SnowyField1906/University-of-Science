//Tìm các phần tử bé hơn hai phần tử kề bên trong một list

#include <iostream>

using namespace std;

int Input(int list[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu tai vi tri " << i + 1 << ": "; cin >> list[i];
    }
}

int Check(int list[], int n) {
    if (list[0] < list[1]) {
        cout << 0 << " ";
    }
    if (n > 1) {
        for (int i = 1; i < n - 1; i++) {
            if ((list[i - 1] > list[i]) && (list[i] < list[i + 1])) {
                cout << i << " ";
                }
            }
        if (list[n - 1] < list[n - 2]) {
            cout << n - 1;
        }
    }
}

int main() {
    int n;
    int list[100];

    cout << "Nhap n = "; cin >> n;

    Input(list, n);
    Check(list, n);
    return 0;
}