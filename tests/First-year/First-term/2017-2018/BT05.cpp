//Đọc file list.txt và truy xuất những file có ngày tạo sau 23/01/2022 vào new.txt

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Date {
    int dd;
    int mm;
    int yyyy;
};

void Read1line(Date &d, ifstream &In) {
    string dd, mm, yyyy = "";
    string line = "";
    getline(In, line);
    for (int i = 0; i <= 1; i++) {
        dd += line[i];
    }
    for (int i = 3; i <= 4; i++) {
        mm += line[i];
    }
    for (int i = 6; i <= 10; i++) {
        yyyy += line[i];
    }

    d.dd = stoi(dd);
    d.mm = stoi(mm);
    d.yyyy = stoi(yyyy);
}

void Read(Date d[100], ifstream &In, int &k) {
    string garbage[100];
    getline(In, garbage[0], '\n');
    getline(In, garbage[1], '\n'); 
    getline(In, garbage[2], '\n'); 
    getline(In, garbage[3], '\n');
    for (int i = 5; i <= 10; i++) {
        Read1line(d[k], In);
        k++;
    }
}

void Write(Date d[100], ofstream &Out, int k) {
    for (int i = 0; i < k; i++) {
        if (d[i].dd >= 23) {
            Out << d[i].dd << "/" << d[i].mm << "/" << d[i].yyyy << endl;
        }
    } 
}

int main() {
    ifstream In;
    ofstream Out;
    
    Date d[100];
    int k = 0;

    In.open("list.txt", ios_base::in);
    if (In.fail()) {
        cout << "Read failed.." << endl;
    }
    else {
        cout << "Read sucessfully!" << endl;
    }
    
    Out.open("new.txt", ios_base::out);
    if (Out.fail()) {
        cout << "Write failed.." << endl;
    }
    else {
        cout << "Write sucessfully!" << endl;
    }

    Read(d, In, k);
    Write(d, Out, k);

    In.close();
    Out.close();

    return 0;
}