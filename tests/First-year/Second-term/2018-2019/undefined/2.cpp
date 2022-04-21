#include <iostream>
#include <fstream>

using namespace std;

struct Point {
    float x;
    float y;
};

struct Polygon {
    int number;
    Point *n = new Point[10];
};

void InputPolygon(Polygon *&poly1, int n) {
    for (int i = 0; i < n; i++) {
        cout << "n" << i + 1 << ": "; cin >> poly1[i].number;
        for (int j = 0; j < poly1[i].number; j++) {
            cin >> poly1[i].n[j].x;
            cin >> poly1[i].n[j].y;
        }
        cout << endl;
    }
}

void Write(char *filename, Polygon *&poly1, int n) {
    ofstream fin(filename, ios::binary);
    // for (int i = 0; i < n; i++) {
    //     fin.write((char *)&(poly1[i].number), sizeof(int));
    //     for (int j = 0; j < poly1[i].number; j++) {
    //         fin.write((char *)&(poly1[i].n[j].x), sizeof(float));
    //         fin.write((char *)&(poly1[i].n[j].y), sizeof(float));
    //     }
    // }
    fin.write((char *)poly1, n*sizeof(Polygon));
}

void Read(char *filename, Polygon *&poly2, int n) {
    ifstream fout(filename, ios::binary);
    // for (int i = 0; i < n; i++) {
    //     fout.read((char *)&(poly2[i].number), sizeof(int));
    //     for (int j = 0; j < poly2[i].number; j++) {
    //         fout.read((char *)&(poly2[i].n[j].x), sizeof(float));
    //         fout.read((char *)&(poly2[i].n[j].y), sizeof(float));
    //     }
    // }
    fout.read((char *)poly2, n*sizeof(Polygon));
}

void OutputPolygon(Polygon *&poly2, int n) {
    for (int i = 0; i < n; i++) {
        cout << "n" << i + 1 << ": " << poly2[i].number << " ";
        for (int j = 0; j < poly2[i].number; j++) {
            cout << poly2[i].n[j].x << " ";
            cout << poly2[i].n[j].y << " ";
        }
        cout << endl;
    }
}



int main() {
    int n;
    cin >> n;
    Polygon *poly1 = new Polygon[n];
    Polygon *poly2 = new Polygon[n];

    InputPolygon(poly1, n);
    Write((char*)"DAGIAC.BIN", poly1, n);
    Read((char*)"DAGIAC.BIN", poly2, n);
    cout << "OUT" << endl;
    OutputPolygon(poly2, n);
    return 0;
}