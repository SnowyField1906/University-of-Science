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

int main() {
    List list;
    initList(list);

    while (true) {
        Menu(list);
        cout << endl;
    }

    return 0;
}