#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main() {
    float percent, quota;
    cin >> percent >> quota;
    if (((0 < percent) && (percent <= pow(10, 9))) && ((0 < quota) && (quota <= pow(10, 9)))) {
        cout << fixed << setprecision(2) << quota/(percent/100);
    }
    else {
        cout << "Vui long nhap dung gia tri";
	}
    return 0;
}