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

int main() {
    List list;
    initList(list);

    int n;
    cout << "Input the number: "; cin >> n;

    numberToList(list, n);

    cout << "Output: "; outputList(list);

    return 0;
}