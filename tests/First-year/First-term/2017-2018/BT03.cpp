//Xoay ma trận vuông 90 độ nếu không phải là ma phương và xoay 180 độ nếu là ma phương

#include <iostream>

using namespace std;

void Input(int A[100][100], int &n) {
    int i, j;
    cout << "Nhap bac n: n = "; cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << "Nhap gia tri o cot " << i + 1 << " hang " << j + 1 << ": "; cin >> A[i][j]; 
        }
    }
}

void Output(int A[100][100], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << A[i][j] << "  ";
        }
        cout << endl;
    }
}

string CheckMagicMatrix(int A[100][100], int n) {
    int i, j;
    int a, b;
    string X = "la";

    int sum = 0;
    int sumtest = 0;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                sum += A[i][j];
            }    
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == n - j - 1) {
                sumtest += A[i][j];
            }    
        }
    }
    if (sum != sumtest) {
        string X = "khong la";
        return X;
    }

    for (i = 0; i < n; i++) {
        sumtest = 0;
        for (j = 0; j < n; j++) {
            sumtest += A[i][j];
        }
        if (sum != sumtest) {
            string X = "khong la";
            return X;
        }
    }

    for (j = 0; j < n; j++) {
        sumtest = 0;
        for (i = 0; i < n; i++) {
            sumtest += A[i][j];
        }
        if (sum != sumtest) {
            string X = "khong la";
            return X;
        }
    }

    return X;
}

void RotateMatrix(int A[100][100], int n) {
    int B[100][100];
    int i, j;
    if (CheckMagicMatrix(A, n) == "la") {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                B[n - i - 1][n - j - 1] = A[i][j]; 
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cout << B[i][j] << "  "; 
            }
            cout << endl;
        }
    }
    if (CheckMagicMatrix(A, n) == "khong la") {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                B[n - j - 1][i] = A[i][j]; 
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cout << B[i][j] << "  "; 
            }
            cout << endl;
        }
    }
}

int main() {
    int n;
    int A[100][100];
    Input(A, n);
    Output(A, n);
    
    cout << "Ma tran tren " << CheckMagicMatrix(A, n) << " ma phuong" << endl;
    cout << "Xoay ma tran mot goc " << ((CheckMagicMatrix(A, n) == "khong la")?"90":"180") << " do" << endl;
    RotateMatrix(A, n);
    return 0;
}