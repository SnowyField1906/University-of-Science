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

// hàm tạo list tổng
void listOfSum(Node *node, List &list2) {
    int sum = 0;
    while (node != NULL) {
        sum += node->data;
        insertTail(list2, sum);
        node = node->pNext;
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