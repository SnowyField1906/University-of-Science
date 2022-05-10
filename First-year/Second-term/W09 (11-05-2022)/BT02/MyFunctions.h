#ifndef MyFunctions_h
#define MyFunctions_h

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

// in ra solution của một trường hợp nào đó thoả mãn
void outputSolutions(int** board, int N);

// kiểm tra nếu quân cờ có thể đặt được ở vị trí (x, y)
bool isValid(int** board, int N, int y, int x);

// hàm đệ quy
bool putQueens(int** board, int N, int y);

#endif /* MyFunctions_h */