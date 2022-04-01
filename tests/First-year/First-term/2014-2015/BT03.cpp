//Dùng struct tính chu vi đa giác n đỉnh

#include <iostream>

using namespace std;

struct Polygon {
    int n;
    double l[100];
};

void Input(Polygon &p) {
    cout << "Input the number of edge: "; cin >> p.n;
    for (int i = 0; i < p.n; i++) {
        cout << "Input the edge " << i + 1 << ": "; cin >> p.l[i];
    }
}

double Perimeter(Polygon p) {
    double peri = 0;
    for (int i = 0; i < p.n; i++) {
        peri += p.l[i];
    }
    return peri;
}

int main() {
    Polygon p;
    cout << "---Input---" << endl;
    Input(p);
    cout << "\n---Perimeter---" << endl;
    cout << "The perimeter of the polygon is " << Perimeter(p);

    return 0;
}