#include <iostream>
#include <fstream>
#include <math.h>
#include "MyFunctions.h"

using namespace std;

int main() {
    ifstream FileIn;
    FileIn.open("input.txt", ios_base::in);

    double a, b, c, delta;
    FileIn >> a >> b >> c;

    ofstream FileOut;
    Out(FileOut);

    delta = pow(b,2) - 4*a*c;

    if (delta < 0) {
        FileOut <<"Phuong trinh vo nghiem";
    }

    else if (delta == 0) {
        FileOut <<"Phuong trinh co nghiem kep: x1 = x2 = " << -b/(2*a);
    }

    else {
        FileOut << "Phuong trinh co 2 nghiem phan biet:" << endl;
        FileOut << "x1 = " << (-b + sqrt(delta))/2*a << endl;
        FileOut << "x2 = " << (-b - sqrt(delta))/2*a;
    }

    FileIn.close();
    FileOut.close();

    return 0;
}