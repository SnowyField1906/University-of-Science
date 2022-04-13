#ifndef MyFunctions_h
#define MyFunctions_h

using namespace std;

struct SinhVien;

////////// NHẬP SINH VIÊN //////////

void InputAStudent(SinhVien& student);

void InputStudents(SinhVien*& students, int n);

////////// XUẤT SINH VIÊN RA MÀN HÌNH VÀ FILE //////////

void OutputAStudent(ofstream& fout, SinhVien student);

void OutputStudents(ofstream& fout, SinhVien* students, int n);

#endif /* MyFunctions_h */