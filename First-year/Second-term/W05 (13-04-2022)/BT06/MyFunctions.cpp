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

////////// ĐỌC SINH VIÊN TỪ FILE //////////

void InputAStudent(ifstream& fin, SinhVien& student) {
    string s;

    getline(fin, s, ' ');
    fin.getline(student.name, 10, ',');

    getline(fin, s, ' ');
    fin.getline(student.mssv, 10, ',');

    getline(fin, s, '{');
    fin >> student.diemso[0];
    getline(fin, s, ' ');
    fin >> student.diemso[1];
    getline(fin, s, ' ');
    fin >> student.diemso[2];
}

void InputStudents(ifstream& fin, SinhVien*& students, int n) {
    // reset con trỏ về đầu file
    fin.clear(); fin.seekg(0);

    for (int i = 0; i < n; i++) {
        fin.ignore();
        InputAStudent(fin, students[i]);
    }
}

////////// XUẤT SINH VIÊN //////////

void OutputAStudent(SinhVien student) {
    cout << "\tThe student's name: " << student.name << endl;
    cout << "\tThe student's ID: " << student.mssv << endl;
    cout << "\tThe student's point: " << student.diemso[0] << ", "
        << student.diemso[1] << ", " << student.diemso[2] << endl << endl;
}

void OutputStudents(SinhVien* students, int n) {
    for (int i = 0; i < n; i++) {
        cout << "STUDENT " << i + 1 << ": " << endl;
        OutputAStudent(students[i]);
    }
}