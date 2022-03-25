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


///////////// C�U 1 /////////////

void InputABook(ABook &abook) {
    cin.ignore();
    cout << "\tInput the book's ID: "; cin.getline(abook.id, 8);
    cout << "\tInput the book's name: "; cin.getline(abook.name, 51);
    cout << "\tInput the book's author: "; cin.getline(abook.author, 51);
    cout << "\tInput the book's publisher: "; cin.getline(abook.publisher, 51);
    cout << "\tInput the book's price: "; cin >> abook.price;
    cout << "\tInput the book's page: "; cin >> abook.page;
    cout << "\tInput the book's year: "; cin >> abook.year;
    cout << endl;

    bool space = false;
    for (int i = 0; i < strlen(abook.id); i++) {
        if (abook.id[i] == ' ') {
            space = true;
            break;
        }
    }
    if (space) {
        cout << "Wrong input, please input again" << endl << endl;
        InputABook(abook);
    }
}

void InputBooks(Books &books) {
    for (int i = 0; i < books.n; i++) {
        cout << "BOOK " << i + 1 << ": " << endl;
        InputABook(books.abook[i]);
    }
}


///////////// C�U 2 /////////////

void OutputABook(ABook abook) {
    cout << "\tThe book's ID: " << abook.id << endl;
    cout << "\tThe book's name: " << abook.name << endl;
    cout << "\tThe book's author: " << abook.author << endl;
    cout << "\tThe book's publisher: " << abook.publisher << endl;
    cout << "\tThe book's price: " << abook.price << " ngan dong" << endl;
    cout << "\tThe book's page: " << abook.page << endl;
    cout << "\tThe book's year: " << abook.year << endl << endl;
}

void OutputBooks(Books books) {
    for (int i = 0; i < books.n; i++) {
        cout << "BOOK " << i + 1 << ": " << endl;
        OutputABook(books.abook[i]);
    }
}


///////////// C�U 3 /////////////

void Sort(Books &books) {
    for (int i = books.n - 1; i >= 1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (books.abook[j].year > books.abook[j + 1].year) {
                swap(books.abook[j], books.abook[j + 1]);
            }
        }
    }
}   


///////////// C�U 4 /////////////

void Find(Books books) {
    int limit;
    cout << "Input the limit: ";
    cin >> limit;
    cout << endl;

    for (int i = books.n - 1; i >= 1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (books.abook[j].price < books.abook[j + 1].price) {
                swap(books.abook[j], books.abook[j + 1]);
            }
        }
    }
    bool flag = true;
    for (int i = 0; i < books.n; i++) {
        if (books.abook[i].page < limit) {
            OutputABook(books.abook[i]);
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "There is no book having less than " << limit << " page(s)!" << endl;
    }

    Sort(books);
}


///////////// C�U 5 /////////////

void Add(Books &books) {
    int index;
    cout << "Input the index: "; cin >> index;
    while (index < 1 || index > books.n) {
        cout << endl << "Wrong index, please input again!" << endl << endl;
        cout << "Input the index: "; cin >> index;
    }
    cout << endl;

    Books newbooks;
    newbooks.abook = new ABook[books.n + 1];

    int j = -1;
    for (int i = 0; i < books.n + 1; i++) {
        if (i == index - 1) {
            InputABook(newbooks.abook[index - 1]);
            continue;
        }
        newbooks.abook[i] = books.abook[++j];
    }

    delete[] books.abook;

    books.abook = newbooks.abook;
    books.n = books.n + 1;
}


///////////// C�U 6 /////////////

void Remove(Books &books) {
    int year;
    cout << "Input the year: ";
    cin >> year;
    cout << endl;

    Books newbooks;
    newbooks.n = 0;
    for (int i = 0; i < books.n; i++) {
        if (books.abook[i].year >= year) {
            newbooks.n = newbooks.n + 1;
        }
    }
    newbooks.abook = new ABook[newbooks.n];

    int j = -1;
    for (int i = 0; i < books.n; i++) {
        if (books.abook[i].year < year) {
            continue;
        }
        newbooks.abook[++j] = books.abook[i];
    }

    delete[] books.abook;

    books.abook = newbooks.abook;
    books.n = newbooks.n;
}
