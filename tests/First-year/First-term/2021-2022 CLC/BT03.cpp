//Tạo struct vận động viên, bỏ những vận động viên không có BMI đạt yêu cầu

#include <iostream>

using namespace std;


struct Participant {
    int id;
    float weight;
    float height;
};

void Input(Participant &parti) {
    cout << "Input the ID: "; cin >> parti.id;
    cout << "Input the weight: "; cin >> parti.weight;
    cout << "Input the height: "; cin >> parti.height;
}

void InputList(Participant list[], int &n) {
    cout << "Input the number of participant: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Participant " << i + 1 << ":" << endl;
        Input(list[i]);
    }
}

void OutputList(Participant list[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Participant " << i + 1 << ": " << list[i].id << ", " << list[i].weight << "kg, " << list[i].height << "m" << endl;
    }
}

float BMI(Participant parti) {
    return ((parti.weight)/((parti.height)*(parti.height)));
}

void Remove(Participant list[], int &n, int pos) {
    for (int i = pos; i < n - 1; i++) {
        list[i] = list[i + 1];
    }
    n--;
}

void RemoveParti(Participant list[], int &n) {
    for (int i = 0; i < n; i++) {
        if (18.5 <= BMI(list[i]) && BMI(list[i]) <= 24.9) {
            Remove(list, n, i);
        }
    }
}

int main() {
    Participant list[100];
    int n;

    cout << "---Input participants---" << endl;
    InputList(list, n);
    cout << endl << "---All participants---" << endl;
    OutputList(list, n);
    RemoveParti(list, n);
    cout << endl << "---Participants not having enough BMI---" << endl;
    OutputList(list, n);
}