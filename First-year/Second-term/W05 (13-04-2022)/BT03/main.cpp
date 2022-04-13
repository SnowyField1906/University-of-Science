#include <iostream>
#include <fstream>
#include "MyFunctions.h"

using namespace std;

//em nhận thấy rằng khi mở file ở dạng nhị phân
//thì một dấu xuống hàng nó sẽ tính 2 kí tự
//còn khi mở file ở dạng thường thì một dấu xuống hàng nó sẽ tính 1 kí tự
//nên nếu có sai số thì do đây chứ không phải chương trình lỗi ạ

int main() {
    fstream fin("file.cpp", ios::in);
    if (fin.is_open()) {
        cout << "Open file successfully!" << endl;
    }
    else {
        cout << "Open file unsuccessfully..." << endl;
    }

    cout << endl << "The file includes " << Count(fin) << " character(s)!";

    fin.close();

    return 0;
}