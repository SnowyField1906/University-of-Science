#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: "; cin >> n;
    
    if ((0 < n) && (n < 10)) {
        switch(n) {
            case 1:
                cout << "n co gia tri la mot"; break;
            case 2:
                cout << "n co gia tri la hai"; break;
            case 3:
                cout << "n co gia tri la ba"; break;
            case 4:
                cout << "n co gia tri la bon"; break;
            case 5:
                cout << "n co gia tri la nam"; break;
            case 6:
                cout << "n co gia tri la sau"; break;
            case 7:
                cout << "n co gia tri la bay"; break;
            case 8:
                cout << "n co gia tri la tam"; break;
            case 9:
                cout << "n co gia tri la chin"; break;
        }
    }
    else {
        cout << "Khong doc duoc";
    }

    return 0;
}