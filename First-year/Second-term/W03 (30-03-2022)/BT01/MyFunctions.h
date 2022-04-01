#ifndef MyFunctions_h
#define MyFunctions_h

#include <iostream>
#include <iomanip>
#include <string>
#include "MyFunctions.h"

struct Dish; //struct dish gồm tên và giá món ăn

struct Serving; //struct serving gồm 1 phần ăn với n món ăn

Dish* CreateDishArray(int n);

void DeleteDishArray(Serving*& serving, int n);

void DeleteServingArray(Serving*& serving);

void Increase(Serving*& serving, int& n);

void Choosing(Serving*& serving, int& n, char type);

void Bill(Serving*& serving, int n);

void Menu();

void Infomation();

#endif /* MyFunctions_h */