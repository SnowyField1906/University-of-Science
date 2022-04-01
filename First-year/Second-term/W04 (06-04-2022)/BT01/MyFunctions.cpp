#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "MyFunctions.h"

using namespace std;

////////////////////

struct Student {
    char* name = new char[50];
    int id;
    float gpa;
};

////////////////////

void DeleteStudentArray(Student*& students) {
    if (students != NULL) {
        delete[] students;
        students = NULL;
    }
    else {
        students = NULL;
    }
}

////////// NHẬP SINH VIÊN //////////

void InputAStudent(Student& student) {
    cout << "\tInput the student's name: "; cin.getline(student.name, 50);
    cout << "\tInput the student's ID: "; cin >> student.id;
    cout << "\tInput the student's average point: "; cin >> student.gpa;
}

////////// XUẤT SINH VIÊN //////////

void OutputAStudent(Student student) {
    cout << "\tThe student's name: " << student.name << endl;
    cout << "\tThe student's ID: " << student.id << endl;
    cout << "\tThe student's average point: " << student.gpa << endl;
}

////////// KIỂM TRA MÃ SỐ SINH VIÊN //////////

bool CheckID(Student astudent) {
    if (1 <= astudent.id / pow(10, 6) && astudent.id / pow(10, 6) < 10) {
        return true;
    }
    else
        return false;
}

////////// CHỈNH TÊN SINH VIÊN //////////

void FixName(Student& astudent) {
    for (int i = 0; i < strlen(astudent.name); i++) {
        if (97 <= astudent.name[i] && astudent.name[i] <= 122) {
            if (i == 0) {
                astudent.name[i] = astudent.name[i] - 32;
            }
            else if (astudent.name[i - 1] == 32) {
                astudent.name[i] = astudent.name[i] - 32;
            }
        }
    }
}

////////// KIỂM TRA TÊN SINH VIÊN //////////

bool CheckName(Student astudent) {
    char* characters = new char[50];
    cin.ignore();
    cout << "Input a string: "; cin.getline(characters, 50);

    int j = 0;
    for (int i = 0; i < strlen(astudent.name); i++) {
        if (astudent.name[i] == characters[j]) {
            j++;
            if (j == strlen(characters)) {
                return true;
            }
        }
        else {
            j = 0;
        }
    }

    return false;
}

////////// NHẬP DANH SÁCH SINH VIÊN //////////

Student* CreateStudentArray(int n) {
    Student* student = new Student[n];
    if (student == NULL) {
        return NULL;
    }
    return student;
}

void InputStudents(Student*& students, int n) {
    for (int i = 0; i < n; i++) {
        cout << endl << "STUDENT " << i + 1 << ": " << endl;
        cin.ignore();
        InputAStudent(students[i]);
    }
}

////////// XUẤT DANH SÁCH SINH VIÊN //////////

void OutputStudents(Student* students, int n) {
    for (int i = 0; i < n; i++) {
        cout << endl << "STUDENT " << i + 1 << ": " << endl;
        OutputAStudent(students[i]);
    }
}

////////// TÌM SINH VIÊN CÓ ĐIỂM TRUNG BÌNH CAO NHẤT //////////

void FindAStudent(Student* students, int n) {
    int flag, max = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].gpa > max) {
            max = students[i].gpa;
            flag = i;
        }
    }
    cout << "STUDENT 1:" << endl;
    OutputAStudent(students[flag]);
}

////////// SẮP XẾP DANH SÁCH //////////

int SortAsc(const void* a, const void* b) {
    return strcmp(((Student*)a)->name, ((Student*)b)->name);
}

int SortDesc(const void* a, const void* b) {
    return strcmp(((Student*)b)->name, ((Student*)a)->name);
}

////////// TÌM 5 SINH VIÊN CÓ ĐIỂM TRUNG BÌNH CAO NHẤT //////////

int Sort(const void* a, const void* b) {
    if (((Student*)a)->gpa != ((Student*)b)->gpa) {
        return ((Student*)b)->gpa - ((Student*)a)->gpa;
    }
    if (((Student*)a)->id != ((Student*)b)->id) {
        return ((Student*)a)->id - ((Student*)b)->id;
    }
    return 0;
}

void FindStudents(Student* students, int n) {
    if (n >= 5) {
        qsort(students, n, sizeof(Student), Sort);

        for (int i = 0; i < 5; i++) {
            cout << endl << "STUDENT " << i + 1 << ":" << endl;
            OutputAStudent(students[i]);
        }
    }
    else {
        cout << endl << "Not enough 5 students!";
    }
    
}