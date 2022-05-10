#include <iostream>
#include "MyFunctions.h"

using namespace std;

// hàm đệ quy
void tower(int n, char first, char second, char third) {
    // nếu chỉ còn một dĩa trên cột hiện tại
    if (n == 1) {
        // in ra bước giải cuối cùng
        cout << "Move disk " << n << " from " << first << " to " << second << endl;

        // kết thúc hàm hiện tại
        return;
    }

    // cho đĩa hiện tại sang đĩa thứ 3 (đĩa sau đĩa vừa được đặt)
    tower(n - 1, first, third, second);

    // in ra bước giải hiện tại
    cout << "Move disk " << n << " from " << first << " to " << second << endl;

    // đĩa thứ 3 (đĩa sau đĩa vừa được đặt) sang đĩa thứ 2 (đĩa vừa mới được đặt)
    tower(n - 1, third, second, first);
}