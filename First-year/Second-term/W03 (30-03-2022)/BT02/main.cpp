#include <time.h>
#include <iostream>

using namespace std;

int main() {
     // Hàm khởi tạo ngẫu nhiên
    srand(time(NULL));

    // Đọc số lượng phần tử của mảng và lưu vào n1
    cout << "Enter original array size: ";
    int n1 = 0;
    cin >> n1;

    // Khởi tạo động mảng a1 có n1 phần tử kiểu int
    int *a1 = new int[n1];
    int i;
    for (i = 0; i < n1; i++) {
        // Gán các phần tử trong mảng bằng 100
        a1[i] = 100;

        // Xuất các phần tử trong mảng ra màn hình
        cout << a1[i] << " ";
    }

    // Đọc số lượng phần tử (mới) của mảng, lưu vào n2
    cout << "\nEnter new array size: ";
    int n2 = 0;
    cin >> n2;

    // Cấp phát lại số lượng phần tử của a1 
    a1 = new int[n2]; 

    // Nếu có nhiều phần tử hơn ban đầu, gán các phần 
    // tử mới bằng 0. Lý do, không muốn sử dụng  
    // các phần tử có giá trị rác.  

    if (n2 > n1) {
        for (int i = 0; i < n1; i++) {
            a1[i] = 100;
        }
        for (int i = n1; i < n2; i++) {
            a1[i] = 0;
        }
    }
    else {
        for(int i = 0; i < n2; i++) {
            a1[i] = 100; 
        }
    }


    for(int i = 0; i < n2; i++) {
        // Xuất các phần tử của mảng ra màn hình
        cout << a1[i] << " ";
    }
    cout << endl;

    delete [] a1;

    //Kết thúc chương trình

    return 0;
}