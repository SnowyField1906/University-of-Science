#ifndef MyFunctions_h
#define MyFunctions_h

using namespace std;

struct SinhVien;

////////// ĐỌC SINH VIÊN TỪ FILE //////////

void InputAStudent(ifstream& fin, SinhVien& student);

void InputStudents(ifstream& fin, SinhVien*& students, int n);

////////// XUẤT SINH VIÊN //////////

void OutputAStudent(SinhVien student);

void OutputStudents(SinhVien* students, int n);

#endif /* MyFunctions_h */