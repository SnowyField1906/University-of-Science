//Strut đa thức tính tổng

#include <iostream>

using namespace std;

struct P {
    float a[100];
    int n;
};

void Input(P &p) {
    int i;
    cout << "Nhap bac n cua da thuc: n = "; cin >> p.n;
    cout << "Nhap he so bac 0: "; cin >> p.a[0];
    if (p.n >= 1) {
        for (i = 1; i <= p.n; i++) {
            cout << "Nhap he so bac " << i << ": "; cin >> p.a[i];
        }
    }
}

void Output(P p) {
    int i;
    cout << "Da thuc co dang: " << p.a[0];
    for (i = 1; i <= p.n; i++)
        cout << " + " << p.a[i] << "x^" << i;
}

void Sum(P p, P q) {
    int i;
    cout << "P(x) + Q(x) = " << p.a[0] + q.a[0];
    for (i = 1; i <= ((p.n < q.n)?p.n:q.n); i++) {
        cout << " + " << p.a[i] + q.a[i] << "x^" << i;
    }
    for (i = ((p.n < q.n)?p.n:q.n) + 1; i <= ((p.n > q.n)?p.n:q.n); i++) {
        if (p.n < q.n) {
            cout << " + " << q.a[i] << "x^" << i;
        }
        else {
            cout << " + " << p.a[i] << "x^" << i;
        }
    }
}

int main() {
    P p, q;
    cout << "---Da thuc P(x)---" << endl;
    Input(p);
    Output(p);
    cout << "\n---Da thuc Q(x)---" << endl;
    Input(q);
    Output(q);
    cout << "\n---Tong hai da thuc---" << endl;
    Sum(p, q);

    return 0;
}