#include <iostream>
#include <iomanip>
#include "MyFunctions.h"

using namespace std;

/*
        MÔ PHỎNG BÀN CỜ board[y][x] (theo trục toạ độ)
            (y: số hàng, tối đa = N)
            (x: số cột, tối đa = N)

       x1   x2   x3   x4   x5
    y1 0    0    0    0    0

    y2 0    0    0    0    0

    y3 0    0    0    0    0

    y4 0    0    0    0    0

    y5 0    0    0    0    0
*/
 
int main() {
    // nhập số hàng/cột của bàn cờ
    int N;
    cout << "Enter the size of chessboard: ";
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

    // gọi hàm đệ quy, vị trí đầu tiên của quân Mã là (0, 0) và số bước đã đi là 1
    // nếu false thì cout không có trường hợp nào thoả
    if(!putKnight(board, N, 0, 0, 1)) {
        cout << "Solution does not exist." << endl;;
    };

    // huỷ mảng con trỏ 2 chiều
    for (int i = 0; i < N; i++) {
        delete[] board[i];
    }
    delete[] board;
 
    return 0;
}