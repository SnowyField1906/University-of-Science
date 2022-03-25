#include <iostream>
#include <string>
#include "MyFunctions.h"

using namespace std;

struct ABook {
    char id[8];
    char name[51];
    char author[51];
    char publisher[51];
    long price;
    int page;
    int year;
};

struct Books {
    int n;
    ABook* abook;
};

int main() {
    Books books;
    cout << "Input the number of books: ";
    cin >> books.n;

    books.abook = new ABook[books.n];

    cout << "\n\n\t====== INPUT BOOKS ======" << endl << endl;
    InputBooks(books);

    cout << "\n\n\t====== OUTPUT BOOKS ======" << endl << endl;
    OutputBooks(books);

    cout << "\n\n\t====== SORT BOOKS IN ASCENDING ORDER BY YEAR ======" << endl << endl;
    Sort(books); OutputBooks(books);

    cout << "\n\n\t====== FIND THE MOST EXPENSIVE BOOK BY PAGE ======" << endl << endl;
    Find(books);

    cout << "\n\n\t====== ADD A BOOK BY INDEX ======" << endl << endl;
    Add(books); OutputBooks(books);

    cout << "\n\n\t====== REMOVE BOOKS BY YEAR ======" << endl << endl;
    Remove(books); OutputBooks(books);

    delete[] books.abook;

    return 0;
}