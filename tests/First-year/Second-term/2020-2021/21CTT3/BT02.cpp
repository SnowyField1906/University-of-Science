#include <iostream>
#include <string.h>

using namespace std;

void resize(char *&newsrc, char*&temp, int n) {
    delete[] temp;
    temp = new char[strlen(newsrc) + n];
    strncpy(temp, newsrc, strlen(newsrc));
    delete[] newsrc;
    newsrc = temp;
}

char* replace (char*src, char*sub, char*rep) {
    if (src == NULL) {
        return NULL;
    }
    else {
        char *temp = new char;
        char *newsrc = new char [1];
        int i, j;
        for (i = 0; i < strlen(src); i++) {
            bool flag = true;
            for (j = 0; j < strlen(sub); j++) {
                if (src[i + j] != sub[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                resize(newsrc, temp, strlen(rep));
                strcat(newsrc, rep);
                i += j - 1;
            }
            else {
                resize(newsrc, temp, 1);
                newsrc[strlen(newsrc)] = src[i];
            }
        }
        newsrc[strlen(newsrc)] = '\0';
        return newsrc;
    }
}

int main() {
    char *src = (char*)"blue cat and blue dog";
    char *sub = (char*)"blue";
    char *rep = (char*)"red";
    cout << replace(src, sub, rep);

    return 0;
}