#include <iostream>
#include <fstream>
#include "MyFunctions.h"

using namespace std;

struct SinhVien {
    char name[10];
    char mssv[10];
    int diemso[3];
};

int main() {
    // tạo/mở file
    ofstream fout;
    fout.open("sinhvien.bin", ios::in | ios::binary);
    if (fout.is_open()) {
        cout << "Open file successfully!" << endl;
    }

    cout << endl << "\t====== INPUT STUDENTS ======" << endl << endl;
    // tạo mảng sinh viên gồm n phần tử
    int n;
    cout << "Input the number of students: "; cin >> n;
    SinhVien* students = new SinhVien[n];
    // nhập mảng sinh viên
    InputStudents(students, n);

    cout << endl << "\t====== OUTPUT STUDENTS ======" << endl << endl;
    // xuất mảng sinh viên gồm n phần tử ra màn hình và file
    OutputStudents(fout, students, n);
    cout << "Export file successfully!" << endl;

    delete[] students;
    fout.close();

    return 0;
}

/* file sinhvien.bin sẽ có dòng text như sau:
{
	name: huu thuan,
	id: 321,
	point: {1, 2, 3},
},
{
	name: thuan huu,
	id: 654,
	point: {4, 5, 6},
},
{
	name: thuan,
	id: 987,
	point: {7, 8, 9},
},

khi mở bằng HexEdit, ta sẽ thấy nó gồm có 152 kí tự bắt đầu bằng "7B 0A 09 ..."
và kết thúc bằng "... 7D 2C 0A"
*/