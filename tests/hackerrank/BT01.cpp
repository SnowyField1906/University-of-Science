//Trò chơi tính điểm theo lượt chọn

#include <iostream>

using namespace std;

void PlayerA(int a[]) {
    for (int i = 0; i <= 2; i ++) {
        cout << "Input the number" << i + 1 << ": "; cin >> a[i];
    }
}

void PlayerB(int b[]) {
    for (int i = 0; i <= 2; i ++) {
        cout << "Input the number" << i + 1 << ": "; cin >> b[i];
    }
}

void Compare(int a[], int b[]) {
    int scoreA = 0; int scoreB = 0;
    for (int i = 0; i <= 2; i++) {
        if (a[i] > b[i]) {
            scoreA++;
        }
        if (a[i] < b[i]) {
            scoreB++;
        }
    }
    cout << "Player A: " << scoreA << endl;
    cout << "Player B: " << scoreB << endl;
}

int main() {
    int a[3];
    int b[3];

    cout << "---Player A---" << endl; PlayerA(a);
    cout << "---Player B---" << endl; PlayerB(b);
    cout << "---Score---" << endl; Compare(a, b);

    return 0;
}