//Kiểm tra mảng có phải là một cấp số cộng hay không

#include <iostream>

using namespace std;

void Input(int list[], int &n) {
    cout << "Input number: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Input the number " << i + 1 << ": "; cin >> list[i];
    }
}

bool Check(int list[], int n) {
    int delta = list[1] - list[0];
    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (list[i] - list[i - 1] != delta) {
            flag = false;
        }
    }
    return flag;
}

int main() {
    int list[100];
    int n;
    Input(list, n);
    
    if (Check(list, n)) {
        cout << "This array is a arithmetic progression!";
    }

    else {
        cout << "This array is not a arithmetic progression!";
    }

    return 0;
}