//Viết hàm in ra các giá trị phân biệt của một dãy số nguyên

#include <iostream>

using namespace std;

void Input(int list[], int &n) {
    cout << "Input number: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Input the number " << i + 1 << ": "; cin >> list[i];
    }
}

void Filter(int list[], int n) {
    int filtered[n];
    int temp = 0;
    bool flag;
    for (int i = 0; i < n; i++) {
        flag = true;
        for (int j = 0; j <= temp; j++) {
            if (list[i] == filtered[j]) {
                flag = false;
            }
        }
        if (flag) {
            filtered[temp] = list[i];
            temp++;
        }
    }
    for (int i = 0; i < temp; i++) {
        cout << filtered[i] << " ";
    }
}

int main() {
    int list[100];
    int n;

    cout << "---Input---" << endl;
    Input(list, n);
    cout << "\n---Filter---" << endl;
    cout << "All numbers existing in list: ";
    Filter(list, n);

    return 0;
}