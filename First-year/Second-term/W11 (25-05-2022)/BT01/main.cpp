#include <iostream>
#include "MyFunctions.h"

using namespace std;

struct Stack {
    int* data;
    int top;
    int capacity;
};


int main() {
    Stack s;
    int capacity;
    cout << "Enter the size of stack: "; cin >> capacity;
    init(s, capacity);

    while (true) {
        menu(s);
    }

    return 0;
}