#include <iostream>
#include <fstream>
#include <string>
#include "MyFunctions.h"

using namespace std;

struct SinhVien {
    char name[10];
    char mssv[10];
    int diemso[3];
};

int main() {
    // mở file
    ifstream fin;
    fin.open("sinhvien.bin", ios::in | ios::binary);
    if (fin.is_open()) {
        cout << "Open file successfully!" << endl;
    }

    // đếm số lượng sinh viên
    int n = 0;
    string s;
    while (!fin.eof()) {
        getline(fin, s);
        n++;
    }
    n /= 5;

    // tạo mảng sinh viên
    SinhVien* students = new SinhVien[n];
    InputStudents(fin, students, n);

    // xuất mảng sinh viên
    cout << endl << "\t====== OUTPUT STUDENTS ======" << endl << endl;
    OutputStudents(students, n);

    fin.close();
    delete[] students;

    return 0;
}