//Chuyển đổi một số nguyên N thành chuỗi ký tự biểu diễn thập phân của nó

#include <iostream>
#include <math.h>

using namespace std;

string Convert(int n) {
    string str = ((n > 0)?"":"-");
    n = abs(n);
    int num = n;
    int temp = 0;
    int i = 0;
    int list[100];
    while (n > 0) {
        n = n/10;
        temp++;
    }
    for (i = temp; i > 0; i--) {
        list[temp - i] = num/((int)pow(10, i - 1));
        num -= list[temp - i]*((int)pow(10, i - 1));
    }
    for (i = 0; i < temp; i++) {
        switch(list[i]) {
            case 1:
                str += "1"; break;
            case 2:
                str += "2"; break;
            case 3:
                str += "3"; break;
            case 4:
                str += "4"; break;
            case 5:
                str += "5"; break;
            case 6:
                str += "6"; break;
            case 7:
                str += "7"; break;
            case 8:
                str += "8"; break;
            case 9:
                str += "9"; break;
            case 0:
                str += "0"; break;
        }
    }
    return str;
}


int main() {
    int n;

    cout << "Input number: n = "; cin >> n;
    cout << "\nThe converted string: " << Convert(n);

    return 0;
}