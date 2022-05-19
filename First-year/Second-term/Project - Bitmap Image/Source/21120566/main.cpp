#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include <iomanip>
#include "MyFunctions.h"

using namespace std;

#pragma pack(push, 2)

struct Header {
    char signature[2];  // chữ kí file
    int fileSize;       // kích thước file
    int reserved;       // phần dành riêng
    int dataOffset;     // địa chỉ bắt đầu lưu dữ liệu điểm ảnh
}; // thông tin tổng quát của file (14 bytes)

struct DIB {
    int dibSize;        // kích thước phần DIB
    int width;          // số pixel theo chiều rộng
    int height;         // số pixel theo chiều dài
    short planes;       // số lớp màu
    short bitsPerPixel; // số bit trong một pixel (1, 4, 8, 16, 24, 32)
    int compression;    // cách nén ảnh
    int imageSize;      // kích thước phần dữ liệu điểm ảnh
    int xPixelsPerM;    // độ phân giải theo phương ngang
    int yPixelsPerM;    // độ phân giải theo phương đứng
    int colorsUsed;     // số màu trong bảng màu
    int importantColor; // số màu quan trọng
}; // thông tin chi tiết của file (40 bytes)

struct BMP {
    Header header;      // thông tin tổng quát của file (14 bytes)
    DIB dib;            // thông tin chi tiết của file (40 bytes)
    char* pDIBReserved; // con trở tới vùng nhớ lưu phần dư của DIB
    char* pImageData;   // con trở tới vùng nhớ lưu dữ liệu điểm ảnh
}; // thông tin của file (54 bytes)

struct Pixel {
    unsigned char A;    // màu alpha
    unsigned char B;    // màu lam
    unsigned char G;    // màu lục
    unsigned char R;    // màu đỏ
}; // thông tin một pixel (4 bytes)

#pragma pack(pop)


int main(int argc, char* argv[]) {
    // ignore argv để tránh lỗi 'unused parameter'
    (void)argc;

    // nếu một trong 3 argument đầu không tồn tại: báo lỗi
    if (argv[1] == NULL || argv[2] == NULL || argv[3] == NULL) {
        invalid();
    }

    // lưu con trỏ đường dẫn file input và file output của command line argument
    char* FILE_IN = argv[1];
    char* FILE_OUT = argv[3];

    // khởi tạo biến BMP cho file input và đọc file input
    BMP srcBMP;
    readBMP(FILE_IN, srcBMP);

    // nếu ảnh không phải 8-bit/24-bit/32-bit: báo lỗi
    if (srcBMP.dib.bitsPerPixel != 8 && srcBMP.dib.bitsPerPixel != 24 && srcBMP.dib.bitsPerPixel != 32) {
        cout << "This is not 8 or 24 or 32 bit." << endl;
        return 0;
    }

    // nếu argv[2] là "-conv":
    if (strcmp(argv[2], "-conv") == 0) {

        // nếu ảnh là 8-bit: báo lỗi
        if (srcBMP.dib.bitsPerPixel == 8) {
            cout << "This is already 8 bit." << endl;
        }

        // nếu không:
        else {

            // khởi tạo biến BMP cho file output
            BMP eightBitBMP;

            // chuyển sang 8-bit, xuất file output, in thông báo và thông tin
            convertTo8Bit(srcBMP, eightBitBMP, convertToPixelArray(srcBMP));
            exportBMP(FILE_OUT, eightBitBMP);
            cout << "Converted image to 8-bit." << endl << endl;
            outputInfomations(eightBitBMP);

            // giải phóng con trỏ (1)
            delete[] eightBitBMP.pDIBReserved;
            delete[] eightBitBMP.pImageData;
        }
    }

    // nếu argv[2] là "-zoom":
    else if (strcmp(argv[2], "-zoom") == 0) {

        // check command line argument (4): check xem argv[4] có tồn tại hay không
        if (argv[4] == NULL) {
            invalid();
        }

        // khởi tạo biến BMP cho file output và nhận giá trị scale
        BMP resizeBMP;

        int scale = atoi(argv[4]);

        // resize ảnh, xuất file output, in thông báo và thông tin
        resize(srcBMP, resizeBMP, scale);
        exportBMP(FILE_OUT, resizeBMP);
        cout << "Resized image." << endl << endl;
        outputInfomations(resizeBMP);

        // giải phóng con trỏ (2)
        delete[] resizeBMP.pDIBReserved;
        delete[] resizeBMP.pImageData;
    }

    // nếu không: báo lỗi
    else {
        invalid();
    }

    // giải phóng con trỏ (3)
    delete[] srcBMP.pDIBReserved;
    delete[] srcBMP.pImageData;

    return 0;
}