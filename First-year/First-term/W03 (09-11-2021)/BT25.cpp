#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main() {
    double km, hour, minute, second, pace, speed;
    cin >> km >> hour >> minute >> second;
    
    if (((0 < km) && (km <= pow(10, 9))) &&
        ((0 < hour) && (hour <= pow(10, 9))) &&
        ((0 < minute) && (minute <= pow(10, 9))) &&
        ((0 < second) && (second <= pow(10, 9)))) {
            speed = km/(hour + minute/60 + second/60/60);
            pace = (hour*60 + minute + second/60)/km;
            cout << fixed << setprecision(2) << speed << " " << pace;
        }
    else {
        cout << "Vui long nhap dung gia tri";
    }
    return 0;
}