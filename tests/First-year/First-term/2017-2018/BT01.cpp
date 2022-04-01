//Tìm tất cả các cặp số nguyên tố có tổng bằng n theo thứ tự tăng dần bởi số đầu tiên trong cặp

#include <iostream>
#include <string>

using namespace std;


void PrimeList(int list1[], int list2[], int n, int &a, int &b) {
    int i, j;
    bool Prime;
    list1[0] = 2;
    for (i = 3; i < n/2; i++) {
        Prime = true;
        for (j = 2; j < i; j++) {
            if (i%j == 0) {
                Prime = false;
                break;
            }
        }
        if (Prime) {
            list1[a] = i;
            a++;
        }
    }
    for (i = n/2; i < n; i++) {
        Prime = true;
        for (j = 2; j < i; j++) {
            if (i%j == 0) {
                Prime = false;
                break;
            }
        }
        if (Prime) {
            list2[b] = i;
            b++;
        }
    }
}

string PairPrime(int list1[], int list2[], int n, int a, int b) {
    int i, j;
    string pairs = "";
    PrimeList(list1, list2, n, a, b);
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            if (list1[i] + list2[j] == n) {
                pairs += "(" + to_string(list1[i]) + ", " + to_string(list2[j]) + ") "; 
            }
        }
    }
    return pairs;
}

int main() {
    int n;
    int a = 0, b = 0;
    int list1[100];
    int list2[100];

    cout << "Nhap n: n = "; cin >> n;

    if (PairPrime(list1, list2, n, a, b).length() == 0) {
        cout << "Khong tim thay";
    }
    else {
        cout << PairPrime(list1, list2, n, a, b);
    }

    return 0;
}