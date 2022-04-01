//Tìm các mảng là chuỗi các số giống nhau liên tiếp lớn nhất

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

void Longest(int list[], int n) {
    int count = 1, countmax = 0, times = 0;
    int flag[100];

    for (int i = 0; i < n - 1; i++) {
        count = 0;
        for (int k = i; k < n - 1; k++) {
            if (list[k] == list[k + 1]) {
                count++;
            }
            else {
                break;
            }
        }
        if (count < countmax) {
            continue;
        }
        if (count > countmax) {
            countmax = count;
            times = 0;
            flag[times] = list[i];
        }
        if (count == countmax) {
            times++;
            flag[times] = list[i];
        }
    }

    cout << "The longest array is: " << endl;

    for (int i = 1; i <= times; i++) {
        for (int j = 0; j <= countmax; j++) {
            cout << flag[i] << "  ";
        }
        cout << endl;
    }
}

int main() {
    int list[100];
    int n;

    cout << "---Input---" << endl;
    Input(list, n);
    cout << "---Output---" << endl;
    Output(list, n);
    cout << endl << "---Find---" << endl;
    Longest(list, n);
}