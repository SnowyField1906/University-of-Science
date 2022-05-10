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

// in ra solution của một trường hợp nào đó thoả mãn
void outputSolutions(int** board, int N) {
    // cho biến k làm biến global để không bị mất số thứ tự sau khi kết thúc hàm
    static int k = 1;
    cout << "Solution #" << k++ << ": " << endl << "  ";
    // in ra bàn cờ
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << left << board[i][j];
        }
        cout << endl << "  ";
    }
    cout << endl;
}

// kiểm tra nếu quân cờ có thể đi được ở vị trí (x, y)
bool isValid(int **board, int N, int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N || board[y][x] != 0) {
        return false;
    }
    return true;
}

// hàm đệ quy
bool putKnight(int **board, int N, int x, int y, int step) {
    // cho giá trị tại vị trí (x, y) bằng giá trị của step (số bước đã đi)
    board[y][x] = step;

    if (step == N*N) {
        // nếu số bước đã đi bằng số ô của bàn cờ thì in ra solution
        outputSolutions(board, N);

        // cho giá trị tại vị trí (x, y) bằng 0 rồi trở về stack trước đó để kiểm tra tiếp xem còn trường hợp nào thoả mãn không
        board[y][x] = 0;
        return true;
    }

    // tập hợp tất cả toạ độ mà quân Mã có thể đi
    int movement[8][2] = {
        { 1, 2 }, { 2, 1 }, { -1, 2 }, { -2, 1 }, { -1, -2 }, { -2, -1 }, { 1, -2 }, { 2, -1 }
    };

    bool flag = false;

    // kiểm tra hết tất cả trường hợp mà quân Mã có thể đi tại vị trí (x, y)
    for (int k = 0; k < 8; k++) {
        // toạ độ mới của quân Mã bằng toạ độ hiện tại cộng tương ứng với
        // tập hợp các toạ độ mà quân Mã có thể đi
        int newX = x + movement[k][0];
        int newY = y + movement[k][1];
 
        // kiểm tra nếu quân Mã có thể đi đến ở vị trí (newX, newY) hay không
        if (isValid(board, N, newX, newY)) {
            // nếu được thì tăng step lên 1 và gọi hàm putKnight với toạ độ mới
            flag = putKnight(board, N, newX, newY, step + 1) || flag;
            // các stack hàm sẽ bắt đầu xoá dần và flag sẽ bắt đầu được tính toán tại đây sau lần return cuối cùng
            // flag sẽ bằng false nếu tất cả trường hợp đều cho ra false
            // flag sẽ bằng true nếu có ít nhất một trường hợp cho ra true
        }
        // kết thúc 1 vòng lặp, chuyển đến vị trí tiếp theo mà quân Mã có thể đi
    }

    // Nếu không đến được outputSolution() (step không thể bằng N*N) thì bỏ đi quân nước đi hiện tại vì trường hợp này sai và về stack trước đó
    board[y][x] = 0;

    return flag;
}