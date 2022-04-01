//Dùng struct để xác định 2 đường tròn có cắt nhau hay không với tâm và bán kính

#include <iostream>
#include <math.h>

using namespace std;

struct O {
    double x;
    double y;
};

struct C {
    struct O o;
    double R;
};

void Input(C &c) {
    cout << "Enter the x-axis of the center: "; cin >> c.o.x;
    cout << "Enter the y-axis of the center: "; cin >> c.o.y;
    cout << "Enter the radius: "; cin >> c.R;
}

void Output(C c) {
    cout << "The center: (" << c.o.x << ", " << c.o.y << ")" << endl;
    cout << "The radius: " << c.R << endl;
}

void Intersect(C c1, C c2) {
    double delta_R;
    if (c1.R > c2.R) {
        delta_R = c1.R - c2.R;
    }
    else {
        delta_R = c2.R - c1.R;
    }

    double distance = sqrt(pow((c1.o.x - c2.o.x), 2) + pow((c1.o.y - c2.o.y), 2));

    if (distance > delta_R) {
        cout << "The two circles are not intersected";
    }
    else {
        cout << "The two circles are intersected";
    }
}

int main() {
    struct C c1;
    struct C c2;

    cout << "---Enter the first circle---" << endl;
    Input(c1);
    cout << "\n---Enter the second circle---" << endl;
    Input(c2);
    cout << "\n---The first circle---" << endl;
    Output(c1);
    cout << "\n---The second circle---" << endl;
    Output(c2);
    cout << "\n---Intersecting check---" << endl;
    Intersect(c1, c2);

    return 0;
}