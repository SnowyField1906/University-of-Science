#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int previous, current;
    cin >> previous >> current;
    
    if ((0 <= previous) && (previous <= current) && (current <= pow(10, 9))) {
        cout << current - previous;
    }
    else {
        cout << "Vui long nhap dung gia tri";
    }
    return 0;
}