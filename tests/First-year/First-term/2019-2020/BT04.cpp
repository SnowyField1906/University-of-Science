//Viết struct sinh viên gồm msvv (string), họ tên (string), điểm tb (double), nhập và xuất 10 sinh viên có điểm trung bình cao nhất ưu tiên sinh viên có msvv nhỏ hơn

#include <iostream>
#include <string>

using namespace std;

struct Student {
    string id;
    string name;
    double avgscore;
};

void Input(Student &st) {
    cout << "ID: "; cin >> st.id;
    cout << "Full name: "; cin >> st.name; //getline(cin, st.name, '\n');
    cout << "Average score: "; cin >> st.avgscore;
}

void InputListStudent(Student st[], int &n) {
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << endl;
        Input(st[i]);
        cout << endl;
    }
}

void SortID(Student st[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (stoi(st[j].id) > stoi(st[j + 1].id)) {
                swap(st[j], st[j + 1]);
            }
        }
    }
}

void SortAVGScore(Student st[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (st[j].avgscore < st[j + 1].avgscore) {
                swap(st[j], st[j + 1]);
            }
        }
    }
}

void Output(Student st[]) {
    for (int i = 0; i < 10; i++) {
        cout << "The student " << i + 1 << ": " << st[i].id << ", " << st[i].name << ", " << st[i].avgscore << endl; 
    }
}

int main() {
    Student st[100];
    int n;

    cout << "---Input---" << endl;
    cout << "Input the number of student: "; cin >> n;
    InputListStudent(st, n);

    cout << "\n---Output---" << endl;
    Output(st);

    return 0;
}