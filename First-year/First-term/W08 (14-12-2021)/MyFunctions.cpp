#inclue "MyFunctions.h"
#include <math.h>

void nhapSoDuong_1(int &n) {
	cout << "Nhap so duong n: "; cin >> n;
}

void nhapSoDuong_2(int &x) {
	cout << "Nhap so duong n: "; cin >> x;
}

void nhapHaiSoDuong_1(int &a, int &b) {
	cout << "Nhap so duong a: "; cin >> a;
	cout << "Nhap so duong b: "; cin >> b;
}

void nhapHaiSoDuong_2(int &x, int &y) {
	cout << "Nhap so duong a: "; cin >> x;
	cout << "Nhap so duong b: "; cin >> y;
}

void ktSoDoiXung(int n) {
    nhapSoDuong_1(n);
    int r, x, s = 0;

    if (10 <= n && n <= 10000000) {
        for(x = n; n != 0; n /= 10) {
            r = n%10;
            s = s*10 + r;
        }
        if (x == s) {
            cout << x << " la so doi xung" << endl;
        }
        else {
            cout << x << " khong la so doi xung" << endl;
        }
    }
    else {
        cout << "Ban da nhap sai gia tri!" << endl;
    }
}

void ktSoHoanHao(int x) {
    nhapSoDuong_2(x);
    int i, s = 0;

    if (1 <= x && x <= 100000000) {
        for (i = 1; i <= x; i++) {
            if (x%i == 0) { 
                s += i;
            }
        }
        if (s == 2*x) {
            cout << x << " la so hoan hao" << endl;
        }
        else {
            cout << x << " khong la so hoan hao" << endl;
        }
    }
    else {
        cout << "Ban da nhap sai gia tri!" << endl;
    }
}


void timChuSoLonNhat(int n) {
    nhapSoDuong_1(n);
    int i, r, max = 0;

    if (n > 0) {
        for (i = n; n != 0; n /= 10) {
            r = n%10;
            if (r > max) {
                max = r;
            }
        }
        cout << max << " la so lon nhat" << endl;
    }
    else {
        cout << "Ban da nhap sai gia tri!" << endl;
    }

void demSoAm() {
    double dem = 0, i = 1, k;

    while (k != 0) {
        cout << "Nhap so thu " << i++ << ": "; cin >> k;
        if (k < 0) {
            dem++;
        }
    }
    cout << "Co " << dem << " so am" << endl;
}

void timUCLN(int a, int b) {
    nhapHaiSoDuong_1(a, b);
    int k, ucln;

    if (n > 0) {
        for (k = 1; k <= a + b; k++) {
            if (a%k == 0 && b%k == 0) {
                ucln = k;
            }
        }
        cout << "Uoc chung lon nhat cua " << a << " va " << b << " la " << ucln <<  endl;
    }

void timBCNN(int x, int y) {
    nhapHaiSoDuong_2(x, y);
    int max = y, k, bcnn;

    if (n > 0) {
        if (x > y) {
            max = a;
        }
        
        for (int i = max; i <= x*y; i++) {
            if (i % x == 0 && i % y == 0) {
                bcnn = i;
                break;
            }
        }
        cout << "Boi chung nho nhat cua " << x << " va " << y << " la " << bcnn << endl;
    }
}

void hoanviSoNguyen() {
    int a, b;

    cout << "Nhap so nguyen a: "; cin >> a;
    cout << "Nhap so nguyen b: "; cin >> b;

    a = a + b;
    b = a - b;
    a = a - b;
    cout << "Sau khi hoan vi: a = " << a << ", b = " << b << endl;
}

void chuyenNhiPhan() {
    long long np = 0;
    int p = 0, x, n;

    cout << "Nhap so nguyen n: "; cin >> n;

    x = n;

    if (-255 <= n && n <= 255) {
        while (n > 0) {
            np += (n % 2) * pow(10, p);
            ++p;
            n /= 2;
        }
        cout << "So nhi phan cua " << x << " la " << np << endl;
    }
    else {
        cout << "Ban da nhap sai gia tri" << endl;
    }
}

void tinhF(int n) {
    nhapSoDuong_1(n);
    int a = 1, b = 2, i, f;

    if (n == 0 || n == 1) {
        cout << "Gia tri cua F la: " << n + 1 << endl;
    }
    else {
        for (i = 3; i <= n; i++) {
            f = 3*b - 2*a;
            a = b;
            b = f;
        }
        cout << "Gia tri cua F la: " << f << endl;
    }
}