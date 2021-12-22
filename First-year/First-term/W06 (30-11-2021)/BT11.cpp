#include <iostream>
using namespace std;

int main() {
    int i;
    for (i = 1; i <= 255; i++) {
        cout << i << ": " << (char)i << endl;
    }
    
    return 0;
}