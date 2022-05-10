#include <iostream>
#include "MyFunctions.h"

using namespace std;

/*
        MÔ PHỎNG BÀN CỜ board[y][x] (theo trục toạ độ)
            (y: số hàng, tăng dần cho đến khi = N)
            (x: số cột, tăng dần cho đến khi = N)

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
    cout << "Solution #" << k++ << ": " << endl;
    // in ra bàn cờ
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "  " << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// kiểm tra nếu quân cờ có thể đặt được ở vị trí (x, y)
bool isValid(int** board, int N, int y, int x) {
    int i, j;

    // kiểm tra cột (trục Oy)
    for (i = 0; i < y; i++) {
        if (board[i][x] == 1) {
            return false;
        }
    }

    // không cần kiểm tra hàng vì mỗi vòng đệ quy mới là sẽ chuyển sang hàng mới

    // kiểm tra đường chéo chính
    // bắt đầu từ hàng hiện tại cột hiện tại đến khi một trong 2 hàng hoặc cột bằng 0
    for (i = y, j = x; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // kiểm tra đường chéo phụ
    // bắt đầu từ hàng hiện tại cột hiện tại đến khi một trong 2 [hàng bằng 0] hoặc [cột đạt cực đại]
    for (i = y, j = x; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    // trả về true nếu vượt qua hết các điều kiện
    return true;
}

// hàm đệ quy
bool putQueens(int** board, int N, int y) {
    // y bắt đầu từ 0 nên nếu y = N - 1 thì đã đủ hàng
    // nếu số hàng y bằng với số quân cờ đã nhập thì return true ngay vì đã đủ
    if (y == N) {
        outputSolutions(board, N);
        return true;
    }

    // flag ban đầu sẽ mặc định là false
    bool flag = false;

    // cho i chạy từ cột đầu tiên đến cột cuối cùng (= N)
    for (int i = 0; i < N; i++) {
        // kiểm tra nếu quân cờ có thể đặt được ở hàng thứ y cột i hay không
        if (isValid(board, N, y, i)) {
            // nếu thoả thì đặt quân cờ ở hàng thứ y cột i
            board[y][i] = 1;

            // nếu đặt được thì chuyển đến hàng tiếp theo
            flag = putQueens(board, N, y + 1) || flag;
            // các stack hàm sẽ bắt đầu xoá dần và flag sẽ bắt đầu được tính toán tại đây sau lần return cuối cùng
            // flag sẽ bằng false nếu tất cả trường hợp đều cho ra false
            // flag sẽ bằng true nếu có ít nhất một trường hợp cho ra true

            // nếu không đến được outputSolution() (y không thể bằng N) thì bỏ đi quân cờ hiện tại vì trường hợp này sai và đến cột tiếp theo
            board[y][i] = 0;
        }
        // kết thúc 1 vòng lặp, chuyển đến cột tiếp theo
    }

    return flag;
}