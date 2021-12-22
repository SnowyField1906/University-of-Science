#include<iostream>
#include "MyFunctions.h"

using namespace std;

void NhapMang(int &n, int list[]) {
    cin >> n;
    cout << "Nhap vao cac ki tu cua mang: " << endl;

    for (int i = 0; i < n; i++) {
        cout << "Phan tu thu " << i+1 << " = "; cin >> list[i];
    }
}

void XuatMang(int &n, int list[]) {
    for (int i = 0; i < n; i++) {
        cout << list[i] << " ";
    }
}

int Max(int n, int list[]) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max <= list[i]) {
            max = list[i];
        }
    }
    return max;
}

int KhongAm(int n, int list[]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (list[i] >= 0) {
            sum += list[i];
        }
    }
    return sum;
}

int ViTriChan(int n, int list[]) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (i%2 == 0) {
			sum = sum + list[i];
        }
    }
    return sum;
}

bool KiemTraSoNguyenTo(int n) {
    int i;
    if (n <= 1) {
        return false;
    }
    for (i = 2; i <= sqrt(n); i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

int SoNguyenTo(int n, int list[]) {
    int prime = 0;
    for (int i = 0; i < n; i++) {
        if (KiemTraSoNguyenTo(list[i])) {
            prime++;
        }
    }
   return prime;
}

int AmMax(int n, int list[]) {
    int a;
    for (int i = 0; i < n; i++) {
        if (list[i] < 0) {
            a = list[i];
        }
    }
    for (int j = 0; j < n; j++) {
        if (list[j] > a && list[j] < 0) {
            a = list[j];
        }
    }
    return a;
}

int KhongAmMin(int n, int list[]) {
    int a;
    for (int i = 0; i < n; i++) {
        if (list[i] >= 0) {
            a = list[i];
        }
    }
    for (int j = 0; j < n; j++) {
        if (list[j] < a && list[j] >= 0) {
            a = list[j];
        }
    }
    return a;
}

bool TangDan(int n, int list[]) {
    for (int i = 0; i < n-1; i++) {
        if(list[i] > list[i+1]) {
            return false;
        }
    }
    return true;
}

int ChinhPhuong(int n, int list[]) {
    int a = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        if (list[i] < 0) {
                continue;
            }
        for (j = 0; j <= sqrt(list[i]); j++) {
            if (pow(j, 2) == list[i]) {
                a += list[i];
            }
        }
    }
    return a;
}
