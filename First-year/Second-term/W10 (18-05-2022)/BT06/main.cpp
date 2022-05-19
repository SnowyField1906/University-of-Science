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
    List list1;
    initList(list1);

    int n;
    cout << "Input the number of elements: "; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        insertTail(list1, a);
    }

    List list2;
    initList(list2);

    listOfSum(list1.pHead, list2);

    cout << "Output: "; outputList(list2);

    return 0;
}