#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e;
    cout << "Nhap so thu nhat: "; cin >> a;
    cout << "Nhap so thu hai: "; cin >> b;
    cout << "Nhap so thu ba: "; cin >> c;
    cout << "Nhap so thu tu: "; cin >> d;

    if (a > b) {
    	e = a;
    	a = b;
    	b = e;
	}
	if (b > c) {
    	e = b;
    	b = c;
    	c = e;
	}
	if (c > d) {
    	e = c;
    	c = d;
    	d = e;
    }
    if (a > b) {
    	e = a;
    	a = b;
    	b = e;
	}
	if (b > c) {
    	e = b;
    	b = c;
    	c = e;
	}
	if (c > d) {
    	e = c;
    	c = d;
    	d = e;
    }
	if (a > b) {
    	e = a;
    	a = b;
    	b = e;
	}
	if (b > c) {
    	e = b;
    	b = c;
    	c = e;
	}
	if (c > d) {
    	e = c;
    	c = d;
    	d = e;
    }
	cout << "Sap xep theo thu tu tang dan: " << a << ", " << b << ", " << c << ", " << d;

    return 0;
}
