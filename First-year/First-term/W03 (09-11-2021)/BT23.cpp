#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

#define PI 3.14

int main() {
    double edge, radius;
	cin >> edge >> radius;
	
	if (((0 < edge) && (edge <= pow(10, 9))) && ((0 < radius) && (radius <= pow(10, 9)))) {
		cout << fixed << setprecision(2) << PI*pow(radius, 2)/2 + 3*sqrt(3)/4*pow(edge, 2);
	}
	else {
		cout << "Vui long nhap dung gia tri";
	}
    return 0;
}