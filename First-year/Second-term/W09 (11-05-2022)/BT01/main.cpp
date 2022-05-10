#include <iostream>
#include "MyFunctions.h"

using namespace std;

int main() {
    // nhập số đĩa
    int n;
    cout << "Input the number of disks: "; cin >> n;

    // gọi hàm đệ quy với 3 cột có tên lần lượt là A, B, C
    tower(n, 'A', 'B', 'C');

    return 0;
}