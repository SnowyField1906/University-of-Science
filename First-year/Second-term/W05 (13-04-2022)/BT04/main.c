#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE* p = fopen("file.bin", "wb");
    char* c = "abcdefghijklmnopqrstuwxyz";
    if (p != NULL) { // mở file thành công
        // ghi c dưới dạng chuỗi byte (char)
        fwrite(c, sizeof(char), sizeof(c), p);
        fclose(p);
    }
}

// file sẽ xuất ra với dòng chữ "abcd"
// khi mở bằng HexEdit, nó sẽ gồm 4 số "61 62 63 64"