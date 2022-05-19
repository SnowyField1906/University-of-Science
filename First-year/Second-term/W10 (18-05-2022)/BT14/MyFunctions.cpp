#include <iostream>
#include <string.h>
#include "MyFunctions.h"

using namespace std;

struct Book {
    char title[200];
    char ISBN[10];
    char author[40];
    char language[30];
    int year;
    int price;
    int stock;
}; // do trong đề thầy không nói là cấp phát động hay không nên em cấp phát tĩnh ạ

struct Node {
    Book data;
    Node* pNext;
};

struct List {
    Node* pHead;
    Node* pTail;
};

// hàm khởi tạo list rỗng
void initList(List& list) {
    list.pHead = NULL;
    list.pTail = NULL;
}

// hàm check xem list rỗng hay không
bool isEmpty(List list) {
    return (list.pHead == NULL && list.pTail == NULL);
}

// hàm tạo một node mới với data là book
Node* createNode(Book book) {
    Node* node = new Node;
    node->data = book;
    node->pNext = NULL;
    return node;
}

// hàm thêm 1 node vào cuối list
void insertTail(List& list, Book book) {
    Node* newTail = createNode(book);
    if (isEmpty(list)) {
        list.pHead = list.pTail = newTail;
    }
    else {
        list.pTail->pNext = newTail;
        list.pTail = newTail;
    }
}

// hàm xoá một node
void deleteNode(List& list, Node* node) {
    // nếu list chỉ còn một node
    if (list.pHead == list.pTail) {
        delete list.pHead;
        list.pHead = list.pTail = NULL;
        return;
    }
    // nếu node ở cuối list
    if (node == list.pTail) {
        Node* node = list.pHead;
        while (node->pNext != list.pTail) {
            node = node->pNext;
        }
        delete list.pTail;
        node->pNext = NULL;
        list.pTail = node;
        return;
    }
    // nếu node ở đầu list
    if (node == list.pHead) {
        Node* node = list.pHead;
        list.pHead = list.pHead->pNext;
        delete node;
        return;
    }
    // nếu node ở vị trí khác
    Node* qNext = node->pNext;
    *node = *qNext;
    delete qNext;
}

// hàm nhập book
void inputBook(List& list) {
    Book book;
    cin.ignore();
    cout << "Title: "; cin.getline(book.title, 200);
    cout << "ISBN: "; cin.getline(book.ISBN, 10);
    cout << "Author: "; cin.getline(book.author, 40);
    cout << "Language: "; cin.getline(book.language, 30);
    cout << "Year: "; cin >> book.year;
    cout << "Price: "; cin >> book.price;
    cout << "Stock: "; cin >> book.stock;

    Node* node = list.pHead;
    while (node != NULL) {
        // check nếu ISBN được nhập trùng với ISBN của một node trong list
        if (strcmp(node->data.ISBN, book.ISBN) == 0) {
            cout << book.ISBN << " already exists, its stock level will be updated instead!" << endl;
            node->data.stock++;
            return;
        }
        node = node->pNext;
    }
    cout << "New book is added!" << endl;
    insertTail(list, book);
}

// hàm bán book
void sellBook(List list, char ISBN[]) {
    Node* node = list.pHead;
    while (node != NULL) {
        // check nếu ISBN được nhập trùng với ISBN của một node trong list
        if (strcmp(node->data.ISBN, ISBN) == 0) {
            if (node->data.stock > 0) {
                node->data.stock--;
                cout << "Successfully sold 1 book!" << endl;
                return;
            }
            else {
                cout << "OUT OF STOCK." << endl;
                return;
            }
        }
        node = node->pNext;
    }
    cout << "Book not found!" << endl;
}

// hàm check xem name có tồn tại trong title hay không
bool contain(char title[], char name[]) {
    int i = 0;
    while (title[i] != '\0') {
        if (title[i] == name[0]) {
            int j = 0;
            while (title[i] != '\0' && name[j] != '\0' && title[i] == name[j]) {
                i++;
                j++;
            }
            if (name[j] == '\0') {
                return true;
            }
        }
        i++;
    }
    return false;
}

// hàm tìm kiếm book theo name
void findBook(List list, char name[]) {
    Node* node = list.pHead;
    int i = 1;
    bool flag = false;
    while (node != NULL) {
        if (contain(node->data.title, name)) {
            flag = true;
            cout << "BOOK " << i++ << ":" << endl;
            cout << "\tTitle: " << node->data.title << endl;
            cout << "\tISBN: " << node->data.ISBN << endl;
        }
        node = node->pNext;
    }
    if (!flag) {
        cout << "No book found!" << endl;
    }
}

// hàm xoá book có stock nhỏ hơn k
bool removeBookLessThanK(List& list, Node* node, int k, bool flag) {
    if (node == NULL) {
        // mặc định là false
        return false;
    }
    // đệ quy quay lui
    flag = removeBookLessThanK(list, node->pNext, k, flag) || flag;
    // flag sẽ bằng false nếu tất cả trường hợp đều cho ra false
    // flag sẽ bằng true nếu có ít nhất một trường hợp cho ra true
    if (node->data.stock < k) {
        deleteNode(list, node);
        // return true nếu có một giá trị nào đó được xoá
        return true;
    }
    return flag;
}

// hàm in ra danh sách book
void outputList(List list) {
    Node* node = list.pHead;
    int i = 1;
    while (node != NULL) {
        cout << "BOOK " << i++ << ": " << endl;
        cout << "\tTitle: " << node->data.title << endl;
        cout << "\tISBN: " << node->data.ISBN << endl;
        cout << "\tAuthor: " << node->data.author << endl;
        cout << "\tLanguage: " << node->data.language << endl;
        cout << "\tYear Published: " << node->data.year << endl;
        cout << "\tPrice: " << node->data.price << endl;
        cout << "\tStock level: " << node->data.stock << endl;
        node = node->pNext;
    }
}

// hàm menu
void Menu(List& list) {
    cout << "1. Print all books" << endl;
    cout << "2. Input a book" << endl;
    cout << "3. Sell a book" << endl;
    cout << "4. Find a book" << endl;
    cout << "5. Remove books less than k" << endl;
    cout << "0. Exit" << endl << endl;

    int choice;
    cout << "Enter your choice: "; cin >> choice;
    switch (choice) {
    case 1:
        if (isEmpty(list)) {
            cout << "List is empty." << endl;
        }
        else {
            outputList(list);
        }
        break;
    case 2:
        inputBook(list);
        break;
    case 3:
        if (isEmpty(list)) {
            cout << "List is empty." << endl;
        }
        else {
            char ISBN[10];
            cin.ignore();
            cout << "Input the ISBN: "; cin.getline(ISBN, 10);
            sellBook(list, ISBN);
        }
        break;
    case 4:
        if (isEmpty(list)) {
            cout << "List is empty." << endl;
        }
        else {
            char name[200];
            cin.ignore();
            cout << "Input the name: "; cin.getline(name, 200);
            findBook(list, name);
        }
        break;
    case 5:
        if (isEmpty(list)) {
            cout << "List is empty." << endl;
        }
        else {
            int k;
            cout << "Input the stock level: "; cin >> k;
            if (removeBookLessThanK(list, list.pHead, k, false)) {
                cout << "Removed uccessfully!" << endl;
            }
            else {
                cout << "No book removed!" << endl;
            }
        }
        break;
    case 0:
        exit(-1);
        break;
    default:
        cout << "Input invalid!" << endl;
        break;
    }
}