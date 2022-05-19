#ifndef MyFunctions_h
#define MyFunctions_h

struct Stack;

void init(Stack& s, int capacity);

bool isFull(Stack s);

bool push(Stack& s, int x);

int pop(Stack& s);

bool isEmpty(Stack s);

void empty(Stack& s);

int size(Stack s);

void outputStack(Stack s);

void menu(Stack& s);

#endif /* MyFunctions_h */