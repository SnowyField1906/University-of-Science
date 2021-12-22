#include <iostream>
#include <math.h>
#include "MyFunctions.h"
using namespace std;

int main() {
	int n, a, b, x, y;

    cout << "---KIEM TRA SO DOI XUNG---" << endl;
	ktSoDoiXung(n);

    cout << "\n---KIEM TRA SO HOAN HAO---" << endl;
    ktSoHoanHao(x);

    cout << "\n---TIM CHU SO LON NHAT---" << endl;
    timChuSoLonNhat(n);

    cout << "\n---DEM SO AM---" << endl;
    demSoAm();

    cout << "\n---TIM UOC CHUNG LON NHAT---" << endl;
    timUCLN(a, b);

    cout << "\n---TIM BOI CHUNG NHO NHAT---" << endl;
    timBCNN(x, y);

    cout << "\n---HOAN VI SO NGUYEN---" << endl;
    hoanviSoNguyen();

    cout << "\n---CHUYEN NHI PHAN---" << endl;
    chuyenNhiPhan();

    cout << "\n---TINH F---" << endl;
    tinhF(n);

	return 0;
}