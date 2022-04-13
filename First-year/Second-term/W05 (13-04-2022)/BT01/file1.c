#include <stdio.h>
#include <stdlib.h>
int main(void) {
    FILE *fout;
    int c;
    if ((fout=fopen("file1.txt", "w")) == NULL) {
        printf("Cannot open output file\n");
        exit(1);
    }
    printf("Input string\n");
    //Voi Windows ta cung Ctrl-z de thoat.
    //Voi Linux ta se dung lenh gi? - Ta sẽ dùng Ctrl-D.
    printf("Ctrl-z if you want to exit\n");
    while ((c=getchar()) != EOF) {
        putc(c, fout);
    }
    fclose(fout);
    exit(0);
}