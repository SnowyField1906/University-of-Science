#ifndef MyFunctions_h
#define MyFunctions_h

// bài 1
int S1(int n);

double S2(double n);

double S3(double n);

int S4(int x, int n);

int fibo(int n);

// bài 2
int numberOfDigits(int n);

int totalEven(int n);

int firstNumber(int n);

int reverse(int n);

int maxDigits(int n);

bool checkOdd(int n);

// bài 3
void inputArray(int*& p, int n);

void outputArray(int* p, int n);

void reverseArray(int* p, int n);

int maxOfArray(int* p, int n);

bool checkPrime(int a, int i);

int countPrime(int* p, int n);

int countUnique(int* p, int n);

bool checkDivisible(int* p, int n);

void sortAsc(int*& p, int n);

// menu
void Menu1();

void Menu2();

void Menu3();

void mainMenu();

#endif /* MyFunctions_h */