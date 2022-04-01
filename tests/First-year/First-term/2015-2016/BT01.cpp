//         5
//       4 5 4
//     3 4 5 4 3
//   2 3 4 5 4 3 2
// 1 2 3 4 5 4 3 2 1

#include <iostream>

using namespace std;

int main() {
    int i, j, k, l;
    int n = 4;
    for (k = 1; k <= 5; k++) {
        for (i = n; i > 0; i--) {
            cout << " ";
        }
        for (j = n + 1; j <= 5; j++) {
            cout << j;
        }
        for (l = 4; l > n; l--) {
            cout << l;
        }
        n--;
        cout << endl;
    }
    return 0;
}