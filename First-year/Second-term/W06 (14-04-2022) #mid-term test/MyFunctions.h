#ifndef MyFunctions_h
#define MyFunctions_h

struct Cat;

///////////////////
char* trimCharArray(char*& c);
void inputACat(Cat& catList);
void outputACat(Cat catList);
void outputCats(Cat* catList, int n);
///////////////////

////// CÂU 1 //////
Cat* createArray(int n);

////// CÂU 2 //////
bool checkEmpty(Cat* catList, int n);

////// CÂU 3 //////
void appendACat(Cat*& catList, Cat* newCatList, int& n);

////// CÂU 4 //////
void popACat(Cat*& catList, Cat* newCatList, int& n);

////// CÂU 5 //////
void findLeastWeightCat(Cat*& catList, int& n);

////// CÂU 6 //////
void updateColor(Cat*& catList, int n);

////// CÂU 7 //////
void sortByWeight(Cat*& catList, int n);

//// CÂU 8 //////
void findMostWeightCats(Cat* catList, Cat* newCatList, int& n);

////// CÂU 9 //////
void deleteArray(Cat*& catList);

///////////////////
void menu(Cat*& catList, Cat* newCatList, int& n);

#endif /* MyFunctions_h */