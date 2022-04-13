#include <iostream>
#include <fstream>
#include "MyFunctions.h"

using namespace std;

struct SinhVien {
    char name[10];
    char mssv[10];
    int diemso[3];
};

////////// NHẬP SINH VIÊN //////////

void InputAStudent(SinhVien& student) {
    cout << "\tInput the student's name: "; cin.getline(student.name, 50);
    cout << "\tInput the student's ID: "; cin >> student.mssv;
    cout << "\tInput the student's point:" << endl;
    cout << "\t\t1: "; cin >> student.diemso[0];
    cout << "\t\t2: "; cin >> student.diemso[1];
    cout << "\t\t3: "; cin >> student.diemso[2];
}

void InputStudents(SinhVien*& students, int n) {
    for (int i = 0; i < n; i++) {
        cout << endl << "STUDENT " << i + 1 << ": " << endl;
        cin.ignore();
        InputAStudent(students[i]);
    }
}

////////// XUẤT SINH VIÊN RA MÀN HÌNH VÀ FILE //////////

void OutputAStudent(ofstream& fout, SinhVien student) {
    // in ra màn hình
    cout << "\tThe student's name: " << student.name << endl;
    cout << "\tThe student's ID: " << student.mssv << endl;
    cout << "\tThe student's point: " << student.diemso[0] << ", "
        << student.diemso[1] << ", " << student.diemso[2] << endl << endl;

    // in ra file
    fout << "{\n\tname: " << student.name << ",\n\tid: " << student.mssv << ",\n\tpoint: {"
        << student.diemso[0] << ", " << student.diemso[1] << ", " << student.diemso[2] << "},\n}," << endl;
}

void OutputStudents(ofstream& fout, SinhVien* students, int n) {
    for (int i = 0; i < n; i++) {
        cout << "STUDENT " << i + 1 << ": " << endl;
        OutputAStudent(fout, students[i]);
    }
}