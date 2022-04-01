#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "MyFunctions.h"

using namespace std;

struct AStudent {
    char *name = new char[50];
    int id;
    float math;
    float literature;
};

struct Students {
    int n;
    AStudent *astudent;
};

AStudent *CreateArray(int n) {
    AStudent *astudent = new AStudent[n];
    if (astudent == NULL) {
        return NULL;
    }
    return astudent;
}

void DeleteArray(AStudent *&astudent) {
    if (astudent != NULL) {
        delete[] astudent;
        astudent = NULL;
    }
    else {
        astudent = NULL;
    }
}

void InputAStudent(AStudent &astudent) {
    cin.ignore();
    cout << "\tInput the student's name: "; cin.getline(astudent.name, 50);
    cout << "\tInput the student's ID: "; cin >> astudent.id;
    cout << "\tInput the student's math point: "; cin >> astudent.math;
    cout << "\tInput the student's literature point: "; cin >> astudent.literature;
    cout << endl;
}

void InputStudents(Students &students) {
    for (int i = 0; i < students.n; i++) {
        cout << "STUDENT " << i + 1 << ": " << endl;
        InputAStudent(students.astudent[i]);
    }
}

void OutputAStudent(AStudent astudent) {
    cout << "\tThe student's name: " << astudent.name << endl;
    cout << "\tThe student's ID: " << astudent.id << endl;
    cout << "\tThe student's author: " << astudent.math << endl;
    cout << "\tThe student's publisher: " << astudent.literature << endl;
}

void OutputStudents(Students students) {
    for (int i = 0; i < students.n; i++) {
        cout << "STUDENT " << i + 1 << ": " << endl;
        OutputAStudent(students.astudent[i]);
    }
}

int SortAsc(const void *a, const void *b) {
    return strcmp(((AStudent*)a)->name, ((AStudent*)b)->name);
}

int SortDesc(const void *a, const void *b) {
    return strcmp(((AStudent*)b)->name, ((AStudent*)a)->name);
}