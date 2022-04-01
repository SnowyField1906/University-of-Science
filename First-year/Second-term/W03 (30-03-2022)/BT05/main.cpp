#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "MyFunctions.h"

using namespace std;

struct AStudent  {
    char *name = new char[50];
    int id;
    float math;
    float literature;
};

struct Students {
    int n;
    AStudent *astudent;
};

int main() {
    Students students;
    cout << "Input the number of students: ";
    cin >> students.n;

    students.astudent = CreateArray(students.n);

    cout << "\n\n\t====== INPUT STUDENTS ======" << endl << endl;
    InputStudents(students);

    cout << "\n\n\t====== OUTPUT STUDENTS ======" << endl << endl;
    OutputStudents(students);

    cout << "\n\n\t====== SORT STUDENTS IN ASCENDING ORDER BY NAME ======" << endl << endl;
    qsort(students.astudent, students.n, sizeof(AStudent), SortAsc);
    OutputStudents(students);

    cout << "\n\n\t====== SORT STUDENTS IN DESCENDING ORDER BY NAME ======" << endl << endl;
    qsort(students.astudent, students.n, sizeof(AStudent), SortDesc);
    OutputStudents(students);

    DeleteArray(students.astudent);

    return 0;
}