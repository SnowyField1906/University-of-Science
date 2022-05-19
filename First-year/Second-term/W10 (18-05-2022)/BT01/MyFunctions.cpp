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

// hàm check xem list rỗng hay không
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

// hàm thêm 1 node vào cuối list
void insertTail(List& list, int a) {
    Node* newTail = createNode(a);
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

// hàm xoá node có data bằng a
void removeAllX(List& list, Node* node, int a) {
    if (node == NULL) {
        return;
    }
    removeAllX(list, node->pNext, a);
    if (node->data == a) {
        deleteNode(list, node);
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