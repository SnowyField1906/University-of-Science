#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main() {
    double edge1, edge2, edge3, p;
    cin >> edge1 >> edge2 >> edge3;
    p = (edge1 + edge2 + edge3)/2;
    
    if (((0 < edge1) && (edge1 <= pow(10, 9))) &&
        ((0 < edge2) && (edge2 <= pow(10, 9))) &&
        ((0 < edge3) && (edge3 <= pow(10, 9)))) {
            cout << fixed << setprecision(2) << edge1 + edge2 + edge3 << " ";
            cout << sqrt(p*(p-edge1)*(p-edge2)*(p-edge3));
    }
    else {
        cout << "Vui long nhap dung gia tri";
    }
    return 0;
}