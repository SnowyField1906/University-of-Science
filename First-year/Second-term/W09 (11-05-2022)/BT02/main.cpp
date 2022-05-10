#include <iostream>
#include "MyFunctions.h"

using namespace std;

/*
        MÔ PHỎNG BÀN CỜ board[y][x] (theo trục toạ độ)
            (y: số hàng, tăng dần cho đến khi = x)
            (x: số cột, tăng dần cho đến khi = x)

       x1   x2   x3   x4   x5
    y1 0    0    0    0    0

    y2 0    0    0    0    0

    y3 0    0    0    0    0

    y4 0    0    0    0    0

    y5 0    0    0    0    0
*/

int main() {
    // nhập số quân hậu, cũng là số hàng và cột của bàn cờ
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;

    // tạo mảng con trỏ 2 chiều
    int** board = new int* [N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N];
    }

    // cho toàn bộ bàn cờ bằng 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    // gọi hàm đệ quy, bắt đầu từ hàng đầu tiên
    // nếu false thì cout không có trường hợp nào thoả
    if (!putQueens(board, N, 0)) {
        cout << "Solution does not exist." << endl;;
    }

    // huỷ mảng con trỏ 2 chiều
    for (int i = 0; i < N; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}