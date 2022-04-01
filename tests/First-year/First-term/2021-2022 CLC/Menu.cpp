

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Question1() {
    int n;
    string x;

    ifstream In;
    ofstream Out;

    In.open("input.txt", ios_base::in);
    Out.open("output.txt", ios_base::out);

    In >> n;
    In >> x;

    string A[n][n];
    int row = 0, column = 0, rowmax = 0, columnmax = 0, a = 0, flagrow = 0, flagcolumn = 0;
    // int rowlist[n][n], columnlist[n][n], diagonallist[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            In >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == x) {
                while (A[i][j + a++] == x) {
                    column++;
                }
                if (row > rowmax) {
                    columnmax = column;
                    flagrow = i;
                    flagcolumn = j;
                }
            }
            else {
                column = 0;
            }
            a = 0;
        }
    }

    for (int j = flagcolumn; j <= columnmax; j++) {
        A[0][j] = "oo";
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Out << A[i][j] << " ";
        }
        Out << endl;
    }

    In.close();
    Out.close();
}

void Question2() {
    ifstream In;

    In.open("paragraph.txt", ios_base::in);

    string list[100];
    int count = 0;
    int temp = 0;

    for (temp = 0; temp < 100; temp++) {
        getline(In, list[temp]);
        if (!getline(In, list[temp])) {
            break;
        }
    }

    for (int i = 0; i < temp; i++) {
        for (int j = 0; j < (int)list[i].length(); j++) {
            if (isspace((list[i])[j])) {
                count++;
            }
        }
    }
            
    cout << "The number of word: " << count << endl;  

    In.close();
}

void Menu(int &q, bool listq[]) {
    cout << "---MENU---" << endl;
    cout << "1. Cau 1" << endl;
    cout << "2. Cau 2" << endl;
    cout << "3. Cau 3" << endl;
    cout << "4. Cau 4" << endl;
    cout << "Choose the question: "; cin >> q;
    switch(q) {
        case 1:
            Question1();
            listq[0] = true;
            break;
        case 2:
            Question2();
            listq[1] = true;
            break;
        case 3:
            Question3();
            listq[2] = true;
            break;
        case 4:
            Question4();
            listq[3] = true;
            break;
    }
}

int main() {
    int q = 1;
    bool listq[5] {false, false, false, false};

    while (1 <= q && q <= 4) {
        for (int i = 0; i < 4; i++) {
            if (!listq[i]) {
                cout << "The question " << i + 1 << " has not done yet!" << endl;
            }
        }
        Menu(q, listq);
    }


    return 0;
}