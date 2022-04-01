#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "MyFunctions.h"

using namespace std;

struct Student {
    char* name = new char[50];
    int id;
    float gpa;
};

int main() {
    Student astudent;
    int n;


    cout << "\n\n\t====== INPUT A STUDENT ======" << endl << endl;
    cout << "STUDENT 0:" << endl;
    InputAStudent(astudent);


    cout << "\n\n\t====== OUTPUT A STUDENT ======" << endl << endl;
    cout << "STUDENT 0:" << endl;
    OutputAStudent(astudent);


    cout << "\n\n\t====== CHECK A STUDENT'S ID ======" << endl << endl;
    if (CheckID(astudent)) {
        cout << "The student's ID is valid!" << endl;
    }
    else {
        cout << "The student's ID is invalid!" << endl;
    }


    cout << "\n\n\t====== FIX A STUDENT'S NAME ======" << endl << endl;
    FixName(astudent);
    cout << "STUDENT 0:" << endl;
    OutputAStudent(astudent);


    cout << "\n\n\t====== CHECK A STUDENT'S NAME ======" << endl << endl;
    if (CheckName(astudent)) {
        cout << endl << "The student's name contains that string!" << endl;
    }
    else {
        cout << endl << "The student's name does not contain that string!" << endl;
    }


    cout << "\n\n\t====== INPUT STUDENTS ======" << endl << endl;
    cout << "Input the number of students: ";
    cin >> n;
    Student* students = new Student[n];
    students = CreateStudentArray(n);
    InputStudents(students, n);


    cout << "\n\n\t====== OUTPUT STUDENTS ======" << endl;
    OutputStudents(students, n);


    cout << "\n\n\t====== FIND THE STUDENT WITH THE HIGHEST AVERAGE POINT ======" << endl << endl;
    FindAStudent(students, n);


    cout << "\n\n\t====== SORT STUDENTS IN ASCENDING ORDER BY NAME ======" << endl << endl;
    cout << "Do you want to sort the array in Ascending or Descending order? (A/D): ";
    char ans;
    cin >> ans;

    while (ans != 'A' && ans != 'D') {
        cout << endl << "Please input \"A\" for Ascending order and \"D\" for Desending order! (A/D): ";
        cin >> ans;
    }

    if (ans == 'A') {
        cout << endl << "ASCENDING:" << endl;
        qsort(students, n, sizeof(Student), SortAsc);
        OutputStudents(students, n);
    }
    if (ans == 'D') {
        cout << endl << "DESCENDING:" << endl;
        qsort(students, n, sizeof(Student), SortDesc);
        OutputStudents(students, n);
    }


    cout << "\n\n\t====== FIND 5 STUDENTS WITH THE HIGHEST AVERAGE POINTS (ID PRIORITY) ======" << endl;
    FindStudents(students, n);


    DeleteStudentArray(students);

    return 0;
}