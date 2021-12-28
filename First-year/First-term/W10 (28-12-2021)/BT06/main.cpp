#include <iostream>
#include <fstream>
#include <string>
#include "MyFunctions.h"

using namespace std;

int main() {
    ifstream FileIn;
    In(FileIn);
    
    string s;
    string out = "";
    bool x;
    int dem = 0, i, j;
    getline(FileIn, s);
    for (i = 0; i < s.length(); i++) {
        if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) {
            x = true;
            for (j = 0; j < out.length(); j++) {
                if (s[i] == out[j] || s[i] == out[j]) {
                    x = false;
                }
            }
            if (x) {
                out += s[i];
            }
        }
    }

    ofstream FileOut;
    Out(FileOut);
    FileOut << "Co " << out.length() << " ki tu chu cai xuat hien (bao gom ca ki tu in hoa)";

    //chỗ này em không biết thầy yêu cầu "kí tự chữ cái" khác với từ như thế nào
    //nên em làm đếm số kí tự chữ cái xuất hiện trong input.txt
    //nếu không phải thì thầy châm chước cho em vì em không hiểu đề yêu cầu gì ạ

    FileIn.close();
    FileOut.close();

    return 0;
}