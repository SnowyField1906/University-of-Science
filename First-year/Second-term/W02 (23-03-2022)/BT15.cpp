#include <iostream>
#include <string>
using namespace std;


struct ABook {
    char id[7];
    char name[50];
    char author[50];
    char publisher[50];
    long price;
    int page;
    int year;
};

struct Books {
    int n;
    ABook *abook;
};


///////////// CÂU 1 /////////////

void InputABook(ABook &abook) {
    cout << "\tInput the book's ID: ";
    cin >> abook.id; fflush(stdin);
    cout << "\tInput the book's name: ";
    cin.getline(abook.name, 50); fflush(stdin);
    cout << "\tInput the book's author: ";
    cin.getline(abook.author, 50); fflush(stdin);
    cout << "\tInput the book's publisher: ";
    cin >> abook.publisher; fflush(stdin);
    cout << "\tInput the book's price: ";
    cin >> abook.price;
    cout << "\tInput the book's page: ";
    cin >> abook.page;
    cout << "\tInput the book's year: ";
    cin >> abook.year;
    cout << endl;
}

void InputBooks(Books &books) {
    for (int i = 0; i < books.n; i++) {
        cout << "BOOK " << i + 1 << ": " << endl;
        InputABook(books.abook[i]);
    }
}


///////////// CÂU 2 /////////////

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


///////////// CÂU 3 /////////////

void Sort(Books &books) {
    for (int i = books.n - 1; i >= 1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (books.abook[j].year > books.abook[j + 1].year) {
                swap(books.abook[j], books.abook[j + 1]);
            }
        }
    }
}


///////////// CÂU 4 /////////////

void Find(Books books) {
    int k;
    cout << "Input the limit: ";
    cin >> k;
    cout << endl;

    for (int i = books.n - 1; i >= 1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (books.abook[j].price < books.abook[j + 1].price) {
                swap(books.abook[j], books.abook[j + 1]);
            }
        }
    }
    for (int i = 0; i < books.n; i++) {
        if (books.abook[i].page < k) {
            OutputABook(books.abook[i]);
            break;
        }
    }

    Sort(books);
}


///////////// CÂU 5 /////////////

void Add(Books &books) {
    int index;
    cout << "Input the index: ";
    cin >> index;
    cout >> endl;

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


///////////// CÂU 6 /////////////

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


////////////////////////


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