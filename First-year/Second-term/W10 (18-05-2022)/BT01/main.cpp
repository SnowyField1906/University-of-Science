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
    outputList(list);

    int x;
    cout << endl << "Input x: "; cin >> x;
    removeAllX(list, list.pHead, x);

    cout << "Output: "; outputList(list);

    return 0;
}