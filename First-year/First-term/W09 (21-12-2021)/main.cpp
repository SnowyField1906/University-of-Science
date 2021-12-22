#include<iostream>
#include "MyFunctions.h"

using namespace std;


int main() {
    int n;
    int list[100];

    cout << "Nhap vao so ki tu cua mang: "; NhapMang(n, list) << endl;
    cout << "Cac gia tri cua mang la: "; XuatMang(n, list) << endl;

    cout << "Gia tri lon nhat cua mang la: " << Max(n, list) << endl;

    cout << "Tong cac so khong am cua mang la: " << KhongAm(n, list) << endl;

    //Phần này em không biết là vị trí chẵn theo thực tế (vị trí thứ hai: list[3], vị trí thứ tư: list[5],...) hay vị trí chẵn theo C++ (list[0], list[2],...)
    //Nên cho phép em được làm vị trí chẵn theo C++ nha thầy, nếu thầy yêu cầu vị trí chẵn theo thực tế thì thầy châm chước cho em vì em không biết
    cout << "Tong cac phan tu tai vi tri chan cua mang la: " << ViTriChan(n, list) << endl;

    cout << "So cac so nguyen to co trong mang la: " << SoNguyenTo(n, list) << endl;

    cout << "So am lon nhat co trong mang la: " << AmMax(n, list) << endl;

    cout << "So khong am nho nhat co trong mang la: " << KhongAmMin(n, list) << endl;

    if (TangDan(n, list)) {
        cout << "Mang tren la mang tang dan" << endl;
    }
    else {
        cout << "Mang tren khong phai la mang tang dan" << endl;
    }

    cout << "Tong cac so chinh phuong co trong mang la: " << ChinhPhuong(n, list);

    return 0;
}