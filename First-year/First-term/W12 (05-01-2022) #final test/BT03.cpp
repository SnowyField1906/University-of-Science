#include <iostream>

using namespace std;

void NhapMang(int matrix[][50], int &m, int &n) {
    cout << "Nhap so luong dong: "; cin >> m;
    cout << "Nhap so luong cot: "; cin >> n;
    int i, j;
    for (i = 0; i < m; i++) {
        cout << "Dong " << i + 1 << " :" << endl;
        for (j = 0; j < n; j++) {
            cout << "Nhap matrix[" << i << "][" << j << "] = "; cin >> matrix[i][j];
        }
    }
}

double TinhTong(int matrix[][50], int m, int n) {
    int i, j;
    double S = 0;
    for (i = 0; i < n; i++) {
        if (i == 0) {
            for (j = 0; j < m; j++) {
                S += matrix[j][i];
            }
        }
        else {
            if (i%2 == 0) {
            for (j = 0; j < m; j++) {
                    S += matrix[j][i];
                }
            }
        }
    }
    return S;
}

int main() {
    int m, n;
    int matrix[50][50];
    NhapMang(matrix, m, n);
    cout << "Tong cac cot chan la: " << TinhTong(matrix, m, n) << endl;

    return 0;
}