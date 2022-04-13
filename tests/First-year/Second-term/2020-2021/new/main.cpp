#include <iostream>
struct MyArr {
int* p;
};
int main() {
    MyArr* a = new MyArr;
    a->p = new int[100];
    delete[] a;
    return 0;
}