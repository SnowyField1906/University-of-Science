//Viết hàm tìm chữ số xuất hiện ít nhất trong mảng 2 chiều MxN

#include <iostream>

using namespace std;

void Input(int matrix[100][100], int &m, int &n) {
    cout << "Input the number of row: "; cin >> m;
    cout << "Input the number of column: "; cin >> n;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Input row " << i + 1 << " column " << j + 1 << ": "; cin >> matrix[i][j];
        }
    }
}

void Output(int matrix[100][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

void Count(int matrix[100][100], int m, int n) {
    int min = 100;
    int minvalue = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int temp = 0;
            for (int ii = 0; ii < m; ii++) {
                for (int jj = 0; jj < n; jj++) {
                    if (matrix[ii][jj] == matrix[i][j]) {
                        temp++;
                    }
                }
            }
            if (temp < min) {
                min = temp;
                minvalue = matrix[i][j];
            }
        }
    }
    cout << "The number " << minvalue << " appears least with " << min << " time(s)!";
}

int main() {
    int m, n;
    int matrix[100][100];

    cout << "---Input---" << endl;
    Input(matrix, m, n);
    cout << "\n---Output---" << endl;
    Output(matrix, m, n);
    // cout << "\n---Sort---" << endl;
    // // SortMatrixColumnAscend(matrix, m, n);
    // Output(matrix, m, n);
    cout << "\n---Count---" << endl;
    Count(matrix, m, n);

    return 0;
}