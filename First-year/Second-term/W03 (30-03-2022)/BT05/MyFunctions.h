#ifndef MyFunctions_h
#define MyFunctions_h

#include <iostream>
#include <string>
#include <stdlib.h>
#include "MyFunctions.h"

struct AStudent;

struct Students;

AStudent* CreateArray(int n);

void DeleteArray(AStudent *&astudent);

void InputAStudent(AStudent &astudent);

void InputStudents(Students &students);

void OutputAStudent(AStudent astudent);

void OutputStudents(Students students);

int SortAsc(const void *a, const void *b);

int SortDesc(const void *a, const void *b);


#endif /* MyFunctions_h */