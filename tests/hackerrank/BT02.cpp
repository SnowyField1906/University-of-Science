//Tạo các cặp giá trị cách nhau 1 đơn vị trong một list

#include <iostream>

using namespace std;

void Input(int list[], int &n) {
    cout << "Number of n: n = "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "The element of " << i + 1 << ": "; cin >> list[i];
    }
}


void Sort(int list[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1]);
            }
        }
   }
}

void Output(int list[], int n) {
    cout << "[";
    for (int i = 0; i <= n - 2; i++) {
        cout << list[i] << ", ";
    }
    cout << list[n - 1] << "]";
}

void List(int newlist[], int list[], int n, int &a) {
    a = 0;
    for (int i = 0; i < n; i++) {
        if (list[i + 1] - list[i] == 1) {
            newlist[a++] = list[i];
            newlist[a++] = list[i + 1];
        }
    }
}

int main() {
    int n, a;
    int list[100];
    int newlist[100];

    Input(list, n);
    Sort(list, n);
    cout << "\nAfter sorting: ";
    Output(list, n);
    List(newlist, list, n, a);
    cout << "\nNew list: ";
    Output(newlist, a);

    return 0;
}