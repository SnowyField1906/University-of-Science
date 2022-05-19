#include <iostream>
#include "MyFunctions.h"

using namespace std;

struct Stack {
    int* data;
    int top;
    int capacity;
};

void init(Stack& s, int capacity) {
    s.capacity = capacity;
    s.data = new int[s.capacity];
    s.top = -1;
}

bool isFull(Stack s) {
    return s.top == s.capacity - 1;
}

bool push(Stack& s, int x) {
    if (isFull(s)) {
        return false;
    }
    s.top++;
    s.data[s.top] = x;
    return true;
}

int pop(Stack& s) {
    int item = s.data[s.top];
    s.top--;
    return item;
}

bool isEmpty(Stack s) {
    return s.top == -1;
}

void empty(Stack& s) {
    if (s.data != NULL) {
        delete[] s.data;
        s.top == -1;
    }
}

int size(Stack s) {
    return s.capacity;
}

void outputStack(Stack s) {
    for (int i = s.top; i >= 0; i--) {
        cout << s.data[i] << " ";
    }
    cout << endl;
}

void menu(Stack& s) {
    cout << endl << "1. Add an integer to stack" << endl;
    cout << "2. Remove the top element from stack" << endl;
    cout << "3. Check whether a stack is empty or not" << endl;
    cout << "4. Make a stack empty" << endl;
    cout << "5. Get the number of elements in the stack" << endl;
    cout << "6. Output the stack" << endl;
    cout << "0. Exit" << endl;

    cout << "Enter your choice: ";

    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        int x;
        cout << "Enter an integer: "; cin >> x;
        if (push(s, x)) {
            cout << "Add successfully!" << endl;
        }
        else {
            cout << "Stack is full!" << endl;
        }
        break;
    case 2:
        if (isEmpty(s)) {
            cout << "Stack is empty!" << endl;
        }
        else {
            cout << "The removed number: " << pop(s) << endl;
        }
        break;
    case 3:
        if (isEmpty(s)) {
            cout << "Stack is empty!" << endl;
        }
        else {
            cout << "Stack is not empty!" << endl;
        }
        break;
    case 4:
        if (isEmpty(s)) {
            cout << "Stack is empty!" << endl;
        }
        else {
            empty(s);
            cout << "Emptied successfully!";
        }
        break;
    case 5:
        cout << "Number of elements in stack: " << s.top + 1 << "/" << size(s) << endl;
        break;
    case 6:
        if (isEmpty(s)) {
            cout << "Stack is empty" << endl;
        }
        else {
            outputStack(s);
        }
        break;
    case 0:
        cout << "Exiting..." << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
}