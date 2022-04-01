int GCD(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int LCM(int a, int b) {
    int tmp;
    int ab = a*b;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return ab/a;
}

void Fact(int n){
    int dem;
    for (int i = 2; i <= n; i++) {
        dem = 0;
        while (n % i == 0){
            ++dem;
            n /= i;
        }
        if (dem) {
            cout << i;
            if(dem > 1) cout << "^" << dem;
            if(n > i){
                cout << " * ";
            }
        }
    }
}

void ReverseList(int list[], int n) {    
    for (int i = 0; i < n / 2; ++i) {
        int temp = list[i];
        list[i] = list[n - i - 1];
        list[n - i - 1] = temp;
    }
    for (int i = 0; i < n; ++i) {
        cout << list[i] << " ";
    }
}

int ReverseInt(int n){ 
  int reverse = 0; 
  while (n > 0) {
    reverse = reverse * 10 + n % 10;
    n /= 10;
  }
  return reverse;
}

void SortListAscend(int list[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1]);
            }
        }
   }
} //Descend: change ">" into "<" in if-statement

void SortMatrixAscend(int matrix[100][100], int m, int n){
	int k = m*n;
	for (int i = 0; i < k - 1; i++){
		for (int j = i + 1; j < k; j++){
			if (matrix[i/n][i%n] > matrix[j/n][j%n]){
				int temp = matrix[i/n][i%n];
				matrix[i/n][i%n] = matrix[j/n][j%n];
				matrix[j/n][j%n] = temp;
			}
		}
	}
} //Descend: change ">" into "<" in if-statement 

void SortMatrixRowAscend(int matrix[100][100], int m, int n) {
    for (int k = 0; k < m; k++) {
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 0; j <= i - 1; j++) {
                if (matrix[k][j] > matrix[k][j + 1]) {
                    swap(matrix[k][j], matrix[k][j + 1]);
                }
            }
        }
    }
} //Descend: change ">" into "<" in if-statement

void SortMatrixColumnAscend(int matrix[100][100], int m, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = m - 1; i >= 1; i--) {
            for (int j = 0; j <= i - 1; j++) {
                if (matrix[j][k] > matrix[j + 1][k]) {
                    swap(matrix[j][k], matrix[j + 1][k]);
                }
            }
        }
    }
} //Descend: change ">" into "<" in if-statement

void sapxep(SV a[], int n){
    //Sap xep theo DTB tang dan
    SV tmp;
    for(int i = 0;i < n;++i){
        for(int j = i+1; j < n;++j){
            if(a[i].dtb > a[j].dtb){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            else if(a[i].dtb == a[j].dtb){
                if(a[i].age > a[j].age){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                }
            }
        }
    }
}