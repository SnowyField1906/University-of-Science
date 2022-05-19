#include <iostream>
#include "MyFunctions.h"

using namespace std;

struct Node {
    int data;
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

// hàm check xem list có rỗng hay không
bool isEmpty(List list) {
    return (list.pHead == NULL && list.pTail == NULL);
}

// hàm tạo một node mới với data là một int
Node* createNode(int a) {
    Node* node = new Node;
    node->data = a;
    node->pNext = NULL;
    return node;
}

// hàm thêm một node vào đầu list
void insertHead(List &list, int a) {
    Node *newHead = createNode(a);
    if(isEmpty(list)) {
        list.pHead = list.pTail = newHead;
    }
    else {
        newHead->pNext = list.pHead;
        list.pHead = newHead;
    }
}

// hàm chuyển number thành list
void numberToList(List &list, int n) {
    if (!n) {
        insertHead(list, 0);
    }
    else {
        while (n > 0) {
            insertHead(list, n % 10);
            n /= 10;
        }
    }
}

// hàm in ra các phần tử của list
void outputList(List list) {
    Node* node = list.pHead;
    while (node != NULL) {
        cout << node->data << " ";
        node = node->pNext;
    }
}