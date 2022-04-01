//Tìm các phần tử có giá trị lớn nhất trong hàng và cột của một ma trận vuông

#include <iostream>

using namespace std;

void Input(int A[100][100], int &n) {
    int i, j;
    cout << "Input n: n = "; cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << "Input the value for column " << i + 1<< " row " << j + 1 << ": "; cin >> A[i][j];
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

void FindMax(int A[100][100], int n) {
    int i, j, k;
    int max, pos;
    bool flag;
    for (i = 0; i < n; i++) {
        max = A[i][0];
        pos = 0;
        flag = true;
        for (j = 0; j < n; j++) {
            if (A[i][j] > max) {
                max = A[i][j];
                pos = j;
            }
        }
        for (k = 0; k < n; k++) {
            if (max < A[k][pos]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << max << " ";
        }
    }
}

int main() {
    int n;
    int A[100][100];
    cout << "---Input---" << endl;
    Input(A, n);
    cout << "\n---Output---" << endl;
    Output(A, n);
    cout << "\n---Max Variables---" << endl;
    FindMax(A, n);
    
    return 0;
}