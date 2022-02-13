#include <iostream>

using namespace std;

void NhapMang(int list[], int &n) {
    cout << "Nhap so luong phan tu: "; cin >> n;
    if (n <= 10) {
        cout << "Ban da nhap sai gia tri quy dinh!";
    }
    else {
        for (int i=0; i<n; i++) {
            cout << "Nhap list[" << i << "] = "; cin >> list[i];
        }
    }
}

int SoChinhPhuong(int list[], int n) {
    int CP = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= list[i]; j++) {
            if (j*j == list[i]) {
                CP += list[i];
                break;
            }
        }
    }
    return CP;
}

bool TangDan(int list[], int n) {
    for (int i = 0; i < n-3; i++) {
        if ((list[i] < list[i + 1]) && (list[i + 1] < list[i + 2])) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    int list[50];
    NhapMang(list, n);
    cout << "Tong cac so chinh phuong la: " << SoChinhPhuong(list, n) << endl;
    if (TangDan(list, n)) {
        cout << "Mang tren co it nhat 3 phan tu tang dan!" << endl;
    }
    else {
        cout << "Mang tren khong co 3 phan tu nao tang dan!" << endl;
    }
    return 0;
}