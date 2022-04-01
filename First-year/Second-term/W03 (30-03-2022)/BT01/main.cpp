#include <iostream>
#include <iomanip>
#include <string>
#include "MyFunctions.h"

using namespace std;


// vì em có một chút không hiểu đề nên em đã nảy ra ý tưởng nâng cấp đề lên thành
// viết chương trình cho người dùng gọi nhiều phần ăn và xuất ra
// {hóa đơn} với {tổng tiền} và {tiền phải trả}
// và em vẫn đảm bảo những yêu cầu của thầy trong đề gốc ạ


struct Dish {
    string name;
    int price;
}; //struct dish gồm tên và giá món ăn

struct Serving {
    int n;
    char name;
    Dish *dish;
}; //struct serving gồm 1 phần ăn với n món ăn

int main() {
    Menu();
    Infomation();
  
    int n = 0;
    Serving *serving = new Serving[n + 1];

    char type;
    cout << endl << "Please input a serving type (A/B/C/D) "; cin >> type;
    while (type != 'A' && type != 'B' && type != 'C' && type != 'D') {
        cout << "Wrong input, please input again! (A/B/C/D) "; cin >> type;
    }
    Choosing(serving, n, type);

    DeleteDishArray(serving, n);
    DeleteServingArray(serving);

    return 0;
}