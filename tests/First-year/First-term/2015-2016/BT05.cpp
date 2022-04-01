//Tạo struct danh sách các học sinh được đọc và ghi trên file

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string id;
    string name;
    float score;
};

void Input(Student &st, ifstream &In) {
    getline(In, st.id, '|');
    getline(In, st.name, '|');
    In >> st.score;
}

void ReadFile(Student st[100], ifstream &In, int &n) {
    In >> n;
    for (int i = 0; i < n; i++) {
        Input(st[i], In);
    }
}

void WriteFile(Student st[100], ofstream &Out, int n) {
    int a = 0;
    for (int i = 0; i < n; i++) {
        if (st[i].score >= 8) {
            a++;
        }
    }
    Out << a;
    for (int i = 0; i < n; i++) {
        if (st[i].score >= 8) {
            Out << st[i].id << "|" << st[i].name << "|" << st[i].score;
        }
    }
}

int main() {
    Student st[100];
    int n;
    ifstream In;
    ofstream Out;

    In.open("input.txt", ios_base::in);
    Out.open("output.txt", ios_base::out);

    ReadFile(st, In, n);
    if (!In.fail()) {
        cout << "Read file successfully!" << endl;
    }
    else {
        cout << "Something went wrong.." << endl;
    }
    WriteFile(st, Out, n);
    if (!Out.fail()) {
        cout << "Write file successfully!" << endl;
    }
    else {
        cout << "Something went wrong.." << endl;
    }

    In.close();
    Out.close();

    return 0;
}