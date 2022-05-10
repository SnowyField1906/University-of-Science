#include <iostream>
#include <math.h>
#include "MyFunctions.h"

using namespace std;

// bài 1
int S1(int n) {
	if (n == 1) {
		return 1;
	}
	return n * n + S1(n - 1);
}
double S2(double n) {
	if (n == 1) {
		return 1;
	}
	return 1 / n + S2(n - 1);
}
double S3(double n) {
	if (n == 1) {
		return 0.5;
	}
	return 1 / (2 * n) + S3(n - 1);
}
int S4(int x, int n) {
	if (n == 1) {
		return x * x;
	}
	return pow(x, 2 * n) + S4(x, n - 1);
}
int fibo(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	return fibo(n - 1) + fibo(n - 2);
}

// bài 2
int numberOfDigits(int n) {
	if (n == 0) {
		return 0;
	}
	return numberOfDigits(n / 10) + 1;
}
int totalEven(int n) {
	if (n == 0) {
		return 0;
	}
	return totalEven(n / 10) + ((n % 2 == 0) ? n % 10 : 0);
}
int firstNumber(int n) {
	if (n / 10 == 0) {
		return n;
	}
	return firstNumber(n / 10);
}
int reverse(int n) {
	if (n / 10 == 0) {
		return n;
	}
	return (n % 10) * (int)pow(10, numberOfDigits(n) - 1) + reverse(n / 10);
}
int maxDigits(int n) {
	if (n / 10 == 0) {
		return n;
	}
	return max(n % 10, maxDigits(n / 10));
}
bool checkOdd(int n) {
	if (n == 0) {
		return true;
	}
	return checkOdd(n / 10) && (n % 2 != 0);
}

// bài 3
void inputArray(int*& p, int n) {
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
}
void outputArray(int* p, int n) {
	if (n > 0) {
		outputArray(p, n - 1);
		cout << p[n - 1] << " ";
	}
}
void reverseArray(int* p, int n) {
	if (n > 0) {
		cout << p[n - 1] << " ";
		reverseArray(p, n - 1);
	}
}
int maxOfArray(int* p, int n) {
	if (n == 0) {
		return p[0];
	}
	return max(maxOfArray(p, n - 1), p[n - 1]);
}
bool checkPrime(int a, int i) {
	if (a <= 1) {
		return false;
	}
	if (a == i) {
		return true;
	}
	return (a % i == 0) ? false : checkPrime(a, i + 1);
}
int countPrime(int* p, int n) {
	if (n == 0) {
		return 0;
	}
	return checkPrime(p[n - 1], 2) ? (countPrime(p, n - 1) + 1) : countPrime(p, n - 1);
}
int countUnique(int* p, int n) {
	if (n == 0) {
		return 0;
	}
	bool flag = true;
	for (int i = n - 2; i >= 0; i--) {
		if (p[i] == p[n - 1]) {
			flag = false;
			break;
		}
	}
	return flag ? (countUnique(p, n - 1) + 1) : countUnique(p, n - 1);
}
bool checkDivisible(int* p, int n) {
	if (n == 1) {
		return (p[0] % 7 == 0) ? true : false;
	}
	return checkDivisible(p, n - 1) && (p[n - 1] % 7 == 0);
}
void sortAsc(int*& p, int n) {
	if (n != 1) {
		sortAsc(p, n - 1);
		if (p[n - 1] < p[n - 2]) {
			swap(p[n - 1], p[n - 2]);
			sortAsc(p, n - 1);
		}
	}
}

// menu
void Menu1() {
	int n, x;
	cout << endl << "1. Find sum of S(n) = 1^2 + 2^2 + ... + n^2" << endl
		<< "2. Find sum of S(n) = 1 + 1/2 + ... + 1/n" << endl
		<< "3. Find sum of S(n) = 1/2 +1/4 + ... + 1/2n" << endl
		<< "4. Find sum of S(x,n) = x^2 + x^4 + ... + x^2n" << endl
		<< "5. Find the nth term in the Fibonacci sequence" << endl
		<< "6. Go back" << endl << "0. End the program" << endl;
	int choice = 1;
	while (choice != 6 && choice != 0) {
		cout << endl << "Enter your choice (0..6): "; cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 0) {
			cout << "Wrong input, please input again (0..6): "; cin >> choice;
		}
		switch (choice) {
		case 1:
			cout << "Enter n: "; cin >> n;
			cout << "Sum of S(n) = " << S1(n) << endl;
			break;
		case 2:
			cout << "Enter n: "; cin >> n;
			cout << "Sum of S(n) = " << S2(n) << endl;
			break;
		case 3:
			cout << "Enter n: "; cin >> n;
			cout << "Sum of S(n) = " << S3(n) << endl;
			break;
		case 4:
			cout << "Enter x and n: "; cin >> x >> n;
			cout << "Sum of S(x, n) = " << S4(x, n) << endl;
			break;
		case 5:
			cout << "Enter n: "; cin >> n;
			cout << "The " << n << "th term in the Fibonacci sequence is " << fibo(n) << endl;
			break;
		case 6:
			cout << endl; mainMenu();
		}
	}
}
void Menu2() {
	int n;
	cout << endl << "1. Find the number of digits in a number" << endl
		<< "2. Find the sum of all even numbers of a number" << endl
		<< "3. Find the first number of a number" << endl
		<< "4. Find the reverse of a number" << endl
		<< "5. Find the maximum digit of a number" << endl
		<< "6. Check if all digits of a number are odd" << endl
		<< "7. Go back" << endl << "0. End the program" << endl;
	int choice = 1;
	while (choice != 7 && choice != 0) {
		cout << endl << "Enter your choice (0..7): "; cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 0) {
			cout << "Wrong input, please input again (0..7): "; cin >> choice;
		}
		switch (choice) {
		case 1:
			cout << "Enter n: "; cin >> n;
			cout << "The number of digits of " << n << " is " << numberOfDigits(n) << endl;
			break;
		case 2:
			cout << "Enter n: "; cin >> n;
			cout << "The sum of all even numbers in " << n << " is " << totalEven(n) << endl;
			break;
		case 3:
			cout << "Enter n: "; cin >> n;
			cout << "The first number of " << n << " is " << firstNumber(n) << endl;
			break;
		case 4:
			cout << "Enter n: "; cin >> n;
			cout << "The reverse of " << n << " is " << reverse(n) << endl;
			break;
		case 5:
			cout << "Enter n: "; cin >> n;
			cout << "The maximum digit of " << n << " is " << maxDigits(n) << endl;
			break;
		case 6:
			cout << "Enter n: "; cin >> n;
			cout << "All digits of the number " << n << " are " << ((checkOdd(n)) ? "odd" : "not odd") << endl;
			break;
		case 7:
			cout << endl; mainMenu();
		}
	}
}
void Menu3() {
	int n;
	int* p = NULL;
	cout << endl << "1. Input the array" << endl
		<< "2. Output the array" << endl
		<< "3. Output the reversed array" << endl
		<< "4. Find the maximum number in the array" << endl
		<< "5. Count prime numbers in the array" << endl
		<< "6. Count unique numbers in the array" << endl
		<< "7. Check if the array is divisible by 7" << endl
		<< "8. Sort the array in ascending order" << endl
		<< "9. Go back" << endl << "0. End the program" << endl;
	int choice = 1;
	while (choice != 9 && choice != 0) {
		cout << endl << "Enter your choice (0..9): "; cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 0) {
			cout << "Wrong input, please input again (0..9): "; cin >> choice;
		}
		switch (choice) {
		case 1:
			cout << "Enter n: "; cin >> n;
			p = new int[n];
			inputArray(p, n);
			break;
		case 2:
			if (p == NULL) {
				cout << "The array is empty" << endl;
			}
			else {
				outputArray(p, n); cout << endl;
			}
			break;
		case 3:
			if (p == NULL) {
				cout << "The array is empty" << endl;
			}
			else {
				reverseArray(p, n); cout << endl;
			}
			break;
		case 4:
			if (p == NULL) {
				cout << "The array is empty" << endl;
			}
			else {
				cout << "The maximum number in the array is " << maxOfArray(p, n) << endl;
			}
			break;
		case 5:
			if (p == NULL) {
				cout << "The array is empty" << endl;
			}
			else {
				cout << "There are " << countPrime(p, n) << " prime numbers in the array" << endl;
			}
			break;
		case 6:
			if (p == NULL) {
				cout << "The array is empty" << endl;
			}
			else {
				cout << "There are " << countUnique(p, n) << " unique numbers in the array" << endl;
			}
			break;
		case 7:
			if (p == NULL) {
				cout << "The array is empty" << endl;
			}
			else {
				cout << "The array " << (checkDivisible(p, n) ? "is" : "is not") << " divisible by 7" << endl;
			}
			break;
		case 8:
			if (p == NULL) {
				cout << "The array is empty" << endl;
			}
			else {
				sortAsc(p, n);
				outputArray(p, n); cout << endl;
			}
			break;
		case 9:
			cout << endl; mainMenu();
		}
	}
}
void mainMenu() {
	int choice;
	cout << "1. Assignment 1" << endl << "2. Assignment 2" << endl << "3. Assignment 3" << endl << "0. End the program" << endl;
	cout << endl << "Choose the assignment (0..3): "; cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 0) {
		cout << "Wrong input, please input again (0..3): "; cin >> choice;
	}
	switch (choice) {
	case 1:
		Menu1();
		break;
	case 2:
		Menu2();
		break;
	case 3:
		Menu3();
		break;
	}
}