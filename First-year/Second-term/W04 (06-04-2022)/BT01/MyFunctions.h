#ifndef MyFunctions_h
#define MyFunctions_h

struct Student;

void DeleteStudentArray(Student*& students);

void InputAStudent(Student& student);

void OutputAStudent(Student student);

bool CheckID(Student astudent);

void FixName(Student& astudent);

bool CheckName(Student astudent);

Student* CreateStudentArray(int n);

void InputStudents(Student*& students, int n);

void OutputStudents(Student* students, int n);

void FindAStudent(Student* students, int n);

int SortAsc(const void* a, const void* b);

int SortDesc(const void* a, const void* b);

int Sort(const void* a, const void* b);

void FindStudents(Student* students, int n);

#endif /* MyFunctions_h */