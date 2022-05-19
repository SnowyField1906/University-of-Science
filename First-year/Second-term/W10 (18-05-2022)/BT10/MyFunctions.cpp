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

// hàm tạo một node mới với data là một int
Node* createNode(int a) {
    Node* node = new Node;
    node->data = a;
    node->pNext = NULL;
    return node;
}

// hàm check xem list có rỗng hay không
bool isEmpty(List list) {
    return (list.pHead == NULL && list.pTail == NULL);
}

// hàm thêm một node vào cuối list
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

// hàm chuyển list thành number
int listToNumber(Node *node) {
    int n = 0;
    while (node != NULL) {
        n = n * 10 + node->data;
        node = node->pNext;
    }
    return n;
}