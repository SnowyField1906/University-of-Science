//Chuyển đổi mảng hai chiều sang mảng một chiều và xuất ra màn hình

#include <iostream>
#include <math.h>

using namespace std;

#define M 100
#define N 100

void Input(int a[M][N], int &m, int &n) {
    cout << "Input the number of row: "; cin >> m;
    cout << "Inout the number of column: "; cin >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Input the value of row " << i + 1 << ", column " << j + 1 << ": "; cin >> a[i][j];
        }
    }
}

bool convertMatrixToArray(int a[M][N], int m, int n, int b[], int &k) {
    k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            b[k] = a[i][j];
            k++;
        }
    }

    if (m*n > pow(2, 32)) {
        return false;
    }
    else {
        return true;
    }
}

void Output(int a[M][N], int m, int n, int b[], int k) {
    cout << "Before: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "\nAfter: " << endl;
    for (int i = 0; i < k; i++) {
            cout << b[i] << "  ";
    }
}

int main() {
    int a[M][N];
    int b[100];
    int m, n, k;
    cout << "---Input---" << endl;
    Input(a, m, n);
    cout << "\n---Output---" << endl;
    if (convertMatrixToArray(a, m, n, b, k)) {
        Output(a, m, n, b, k);
    }
    else {
        cout << "Out of bound!";
    }
    return 0;
}