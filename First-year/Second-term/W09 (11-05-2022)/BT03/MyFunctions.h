#ifndef MyFunctions_h
#define MyFunctions_h

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
void outputSolutions(int **board, int N);

// kiểm tra nếu quân cờ có thể đi được ở vị trí (x, y)
bool isValid(int **board, int N, int x, int y);

// hàm đệ quy
bool putKnight(int **board, int N, int x, int y, int step);

#endif /* MyFunctions_h */