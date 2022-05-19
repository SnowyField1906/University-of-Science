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
    cout << "Input the number of elements: "; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        insertTail(list, a);
    }

    cout << "Output: " << listToNumber(list.pHead) << endl;

    return 0;
}