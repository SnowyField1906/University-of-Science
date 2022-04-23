#include <iostream>

using namespace std;

char* normalize(char *src) {
    int n = 0, i = 0;
    while (src[n]) {
        n++;
    }
    char *normalized = new char[n];
    int begin, mid, end;
    for (begin = 0; begin < n; begin++) {
        if (src[begin] != ' ') {
            break;
        }
    }
    for (end = n - 1; end > begin; end--) {
        if (src[end] != ' ') {
            break;
        }
    }
    end = n - 1 - end;
    for (mid = begin; mid < n - end; mid++) {
        normalized[i++] = src[mid];
        if (src[mid] != ' ') {
            continue;
        }
        else {
            while (src[mid + 1] == ' ') {
                mid++;
            }
        }
    }
    return normalized;
}

int main() {
    char *src = (char*)"  kY    tHUat   lAp trINh ";
    cout << normalize(src);
    return 0;
}

