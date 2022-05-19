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
    cout << "LIST 1:" << endl;
    List list1;
    initList(list1);
    int n1;
    cout << "Input the number of elements: "; cin >> n1;
    for (int i = 0; i < n1; i++) {
        int a; cin >> a;
        insertTail(list1, a);
    }

    cout << "LIST 2:" << endl;
    List list2;
    initList(list2);
    int n2;
    cout << "Input the number of elements: "; cin >> n2;
    for (int i = 0; i < n2; i++) {
        int a; cin >> a;
        insertTail(list2, a);
    }

    join2List(list1.pHead, list2.pHead);

    cout << "Output: "; outputList(list1);

    return 0;
}