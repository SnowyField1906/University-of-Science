#include <iostream>
#include <string.h>
using namespace std;

void CheckInt(const char *s, int i, int &count) {
    if (s[i + count] == '0' || s[i + count] == '1' || s[i + count] == '2' || s[i + count] == '3' || s[i + count] == '4' || s[i + count] == '5' || s[i + count] == '6' || s[i + count] == '7' || s[i + count] == '8' || s[i + count] == '9') {
        CheckInt(s, i, ++count);
    }
}

int tongSoNguyen(const char *s) {
    int total = 0;
    for (int i = 0; i < strlen(s); i++) {
        char temp[strlen(s)];
        int count = 0;
        CheckInt(s, i, count);
        if (count == 0) {
            continue;
        }
        memcpy(temp, &s[i], count);
        temp[count] = '\0';
        total += atoi(temp);
        i += count - 1;
    }
    return total;
}

int main() {
    char *s = new char[100];
    cout << "Input the string: ";
    cin >> s;
    cout << "Total: " << tongSoNguyen(s);
    return 0;
}