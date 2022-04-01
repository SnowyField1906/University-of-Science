//Thêm xoá phần tử trong mảng

#include <iostream>

using namespace std;

void Input(int list[], int &n) {
    cout << "Input the number: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Input the number " << i + 1 << ": "; cin >> list[i];
    }
}

void Output(int list[], int n) {
    for (int i = 0; i < n; i++) {
        cout << list[i] << "  ";
    }
}

void Add(int list[], int &n, int pos, int val) {
    for (int i = n - 1; i >= pos; i--) {
        list[i + 1] = list[i];
    }
    list[pos] = val;
    n++;
}

void Remove(int list[], int &n, int pos) {
    pos--;
    for (int i = pos; i < n; i++) {
        list[i] = list[i + 1];
    }
    n--;
}

int main() {
    int n, pos, val;
    int list[100];

    cout << "---Input---" << endl;
    Input(list, n);
    cout << "\n---Output---" << endl;
    Output(list, n);
    cout << "\n---Add---" << endl;
    cout << "Input the position: "; cin >> pos;
    cout << "Input the value: "; cin >> val;
    Add(list, n, pos, val);
    Output(list, n);
    cout << "\n---Remove---" << endl;
    cout << "Input the position: "; cin >> pos;
    Remove(list, n, pos);
    Output(list, n);
}