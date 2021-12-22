#include <iostream>
using namespace std;

int main() {
    int i = 0;
    while (i <= 255) {
        cout << i << ": " << (char)i << endl;
        i ++;
    }
    
    return 0;
}