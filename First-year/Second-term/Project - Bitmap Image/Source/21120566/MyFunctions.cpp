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


// hàm trả về tổng byte của ảnh
int getSize(int height, int width, int padding, int bpp) {
    return height * width * bpp / 8 + height * padding;
}

// hàm trả về padding của ảnh
int getPadding(int width, int bpp) {
    return ((width * bpp / 8) % 4 == 0) ? 0 : (4 - (width * bpp / 8) % 4);
}

// hàm trả về vị trí index trong mảng một chiều tại toạ độ (x, y)
int getIndex(int width, int x, int y) {
    return y * width + x;
}

// hàm trả về giá trị trung bình của một pixel
Pixel getAverage(Pixel srcPixel, Pixel dstPixel) {
    dstPixel.A = (dstPixel.A + srcPixel.A) / 2;
    dstPixel.B = (dstPixel.B + srcPixel.B) / 2;
    dstPixel.G = (dstPixel.G + srcPixel.G) / 2;
    dstPixel.R = (dstPixel.R + srcPixel.R) / 2;
    return dstPixel;
}


// hàm đọc file input
void readBMP(const char* filename, BMP& bmp) {

    // mở file input dưới dạng binary
    ifstream fin(filename, ios::binary);

    // xuất lỗi nếu file không tồn tại và kết thúc chương trình
    if (!fin) {
        cout << "File not found!" << endl;
        exit(-1);
    }

    // đọc Header của file input
    fin.read((char*)&bmp.header, 14);

    // nếu ảnh không là ảnh BMP: xuất lỗi và kết thúc chương trình
    if (bmp.header.signature[0] != 'B' || bmp.header.signature[1] != 'M') {
        cout << "This is not a BMP file." << endl;
        exit(-1);
    }

    // đọc DIB của file input
    fin.read((char*)&bmp.dib, 40);

    // nếu DIB lớn hơn 40 bytes: đọc phần dư của DIB
    if (bmp.dib.dibSize > 40) {
        bmp.pDIBReserved = new char[bmp.dib.dibSize - 40];
        fin.read(bmp.pDIBReserved, bmp.dib.dibSize - 40);
    }

    // nếu không: gán con trỏ pDIBReserved cho NULL
    else {
        bmp.pDIBReserved = NULL;
    }

    // tính size ảnh của file input
    int padding = getPadding(bmp.dib.width, bmp.dib.bitsPerPixel);
    bmp.dib.imageSize = getSize(bmp.dib.height, bmp.dib.width, padding, bmp.dib.bitsPerPixel);

    // cấp phát vùng nhớ lưu dữ liệu ảnh của file input
    bmp.pImageData = new char[bmp.dib.imageSize];

    // đọc dữ liệu ảnh của file input
    fin.read(bmp.pImageData, bmp.dib.imageSize);

    // đóng file input
    fin.close();
}

// hàm xuất file output
void exportBMP(const char* filename, BMP bmp) {

    // mở/tạo file output dưới dạng binary
    ofstream fout(filename, ios::binary);

    // viết Header và DIB của ảnh output
    fout.write((char*)&bmp.header, 14);
    fout.write((char*)&bmp.dib, 40);

    // nếu DIB lớn hơn 40 bytes: viết phần dư của DIB
    if (bmp.dib.dibSize > 40) {
        fout.write(bmp.pDIBReserved, bmp.dib.dibSize - 40);
    }

    // nếu file output là ảnh 8-bit: tạo và viết bảng màu
    if (bmp.dib.bitsPerPixel == 8) {
        char* palette = new char[1024];
        for (int i = 0; i < 256; i++) {
            palette[i * 4] = palette[i * 4 + 1] = palette[i * 4 + 2] = (char)i;
            palette[i * 4 + 3] = 0;
        }
        fout.write(palette, 1024);
        delete[] palette;
    }

    // viết dữ liệu ảnh của file output
    fout.write(bmp.pImageData, bmp.dib.imageSize);

    // đóng file output
    fout.close();
}

// hàm trả về mảng pixel từ mảng màu của ảnh 24-bit/32-bit
Pixel* convertToPixelArray(BMP bmp) {

    // gán lại các giá trị
    int width = bmp.dib.width;
    int height = bmp.dib.height;
    int padding = getPadding(width, bmp.dib.bitsPerPixel);

    // cấp phát mảng pixel mới
    Pixel* newPixel = new Pixel[height * width];

    // thuật toán (1): chuyển từ mảng màu sang mảng pixel
    int alpha = bmp.dib.bitsPerPixel / 32;
    int i = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = getIndex(width, x, y);
            newPixel[index].A = bmp.pImageData[i];
            i += alpha;
            newPixel[index].B = bmp.pImageData[i++];
            newPixel[index].G = bmp.pImageData[i++];
            newPixel[index].R = bmp.pImageData[i++];
        }
        i += padding;
    }

    // trả về mảng pixel
    return newPixel;
}

// hàm trả về mảng pixel đã resize từ mảng pixel gốc
Pixel* resizePixelArray(Pixel* srcPixel, int height, int width, int scale) {

    // gán lại các giá trị, làm tròn trên cho height và width của ảnh mới
    int dstHeight = ceil((double)height / (double)scale);
    int dstWidth = ceil((double)width / (double)scale);

    // cấp phát mảng pixel mới
    Pixel* dstPixel = new Pixel[dstHeight * dstWidth];

    // thuật toán (2): resize mảng pixel
    for (int y = 0; y < dstHeight; y++) {
        for (int x = 0; x < dstWidth; x++) {
            int srcIndex = getIndex(width, x * scale, y * scale);
            int dstIndex = getIndex(dstWidth, x, y);
            dstPixel[dstIndex] = srcPixel[srcIndex];
            for (int j = 0; j < scale && (j + y * scale < height); j++) {
                for (int i = 0; i < scale && (i + x * scale < width); i++) {
                    int srcSubIndex = getIndex(width, i, j);
                    dstPixel[dstIndex] = getAverage(srcPixel[srcIndex + srcSubIndex], dstPixel[dstIndex]);
                }
            }
        }
    }

    // giải phóng con trỏ mảng pixel
    delete[] srcPixel;

    // trả về mảng pixel mới
    return dstPixel;
}

// hàm trả về mảng màu của ảnh 8-bit đã resize từ mảng màu gốc
char* resize8BitArray(char* srcArray, int height, int width, int scale) {

    // gán lại các giá trị, làm tròn trên cho height và width của ảnh mới
    int dstHeight = ceil((double)height / (double)scale);
    int dstWidth = ceil((double)width / (double)scale);

    // cấp phát mảng màu mới
    char* dstArray = new char[dstHeight * dstWidth];

    // thuật toán (3): resize mảng màu
    for (int y = 0; y < dstHeight; y++) {
        for (int x = 0; x < dstWidth; x++) {
            int srcIndex = getIndex(width, x * scale, y * scale);
            int dstIndex = getIndex(dstWidth, x, y);
            dstArray[dstIndex] = srcArray[srcIndex];
            for (int j = 0; j < scale && (j + y < height); j++) {
                for (int i = 0; i < scale && (i + x < width); i++) {
                    int srcSubIndex = getIndex(width, i, j);
                    dstArray[dstIndex] = (srcArray[srcIndex + srcSubIndex] + dstArray[dstIndex]) / 2;
                }
            }
        }
    }

    // trả về mảng màu mới
    return dstArray;
}

// hàm chuyển ảnh sang 8-bit
void convertTo8Bit(BMP srcBMP, BMP& dstBMP, Pixel* srcPixel) {

    // gán lại các giá trị
    dstBMP.header = srcBMP.header;
    dstBMP.dib = srcBMP.dib;
    dstBMP.dib.bitsPerPixel = 8;

    // nếu DIB lớn hơn 40 bytes: gán (copy) lại phần dư của DIB
    if (srcBMP.dib.dibSize > 40) {
        dstBMP.pDIBReserved = new char[srcBMP.dib.dibSize - 40];
        memcpy(dstBMP.pDIBReserved, srcBMP.pDIBReserved, srcBMP.dib.dibSize - 40);
    }

    // nếu không: gán con trỏ cho NULL
    else {
        dstBMP.pDIBReserved = NULL;
    }

    // gán lại các giá trị
    int dstHeight = dstBMP.dib.height;
    int dstWidth = dstBMP.dib.width;
    int dstPadding = getPadding(dstWidth, dstBMP.dib.bitsPerPixel);

    // cấp phát dữ liệu ảnh
    dstBMP.dib.imageSize = getSize(dstHeight, dstWidth, dstPadding, dstBMP.dib.bitsPerPixel);
    dstBMP.pImageData = new char[dstBMP.dib.imageSize];

    // thuật toán (4): lấy trung bình cộng của từng pixel
    int i = 0;
    if (dstBMP.dib.bitsPerPixel == 24) {
        for (int y = 0; y < dstHeight; y++) {
            for (int x = 0; x < dstWidth; x++) {
                int index = getIndex(dstWidth, x, y);
                dstBMP.pImageData[i++] = (srcPixel[index].B + srcPixel[index].G + srcPixel[index].R) / 3;
            }
            i += dstPadding;
        }
    }
    else {
        for (int y = 0; y < dstHeight; y++) {
            for (int x = 0; x < dstWidth; x++) {
                int index = getIndex(dstWidth, x, y);
                dstBMP.pImageData[i++] = (srcPixel[index].A + srcPixel[index].B + srcPixel[index].G + srcPixel[index].R) / 4;
            }
            i += dstPadding;
        }
    }

    // giải phóng con trỏ mảng pixel
    delete[] srcPixel;
}

// hàm resize ảnh
void resize(BMP srcBMP, BMP& dstBMP, int scale) {

    // gán lại các giá trị
    dstBMP.header = srcBMP.header;
    dstBMP.dib = srcBMP.dib;

    // nếu DIB lớn hơn 40 bytes: gán (copy) lại phần dư của DIB
    if (srcBMP.dib.dibSize > 40) {
        dstBMP.pDIBReserved = new char[srcBMP.dib.dibSize - 40];
        memcpy(dstBMP.pDIBReserved, srcBMP.pDIBReserved, dstBMP.dib.dibSize - 40);
    }

    // nếu không: gán con trỏ cho NULL
    else {
        dstBMP.pDIBReserved = NULL;
    }

    // gán lại các giá trị, làm tròn trên cho height và width của ảnh mới
    int srcHeight = srcBMP.dib.height;
    int srcWidth = srcBMP.dib.width;
    int dstHeight = dstBMP.dib.height = ceil((double)srcHeight / (double)scale);
    int dstWidth = dstBMP.dib.width = ceil((double)srcWidth / (double)scale);
    int dstPadding = getPadding(dstWidth, dstBMP.dib.bitsPerPixel);

    // cấp phát dữ liệu ảnh
    dstBMP.dib.imageSize = getSize(dstHeight, dstWidth, dstPadding, dstBMP.dib.bitsPerPixel);
    dstBMP.pImageData = new char[dstBMP.dib.imageSize];

    // nếu ảnh là 8-bit:
    if (dstBMP.dib.bitsPerPixel == 8) {

        // cấp phát mảng màu mới
        char* dstArray = resize8BitArray(srcBMP.pImageData, dstHeight, dstWidth, scale);

        // thuật toán (5): gán lại dữ liệu ảnh cho ảnh từ mảng màu
        int i = 0;
        for (int y = 0; y < dstHeight; y++) {
            for (int x = 0; x < dstWidth; x++) {
                int index = getIndex(dstWidth, x, y);
                dstBMP.pImageData[i++] = dstArray[index];
            }
            i += dstPadding;
        }

        // giải phóng con trỏ mảng màu
        delete[] dstArray;
    }

    // nếu không:
    else {

        // cấp phát mảng pixel mới
        Pixel* dstPixel = resizePixelArray(convertToPixelArray(srcBMP), srcHeight, srcWidth, scale);

        // thuật toán (6): gán lại dữ liệu ảnh cho ảnh từ mảng pixel
        int i = 0;
        int alpha = dstBMP.dib.bitsPerPixel / 32;
        for (int y = 0; y < dstHeight; y++) {
            for (int x = 0; x < dstWidth; x++) {
                int index = getIndex(dstWidth, x, y);
                dstBMP.pImageData[i] = dstPixel[index].A;
                i += alpha;
                dstBMP.pImageData[i++] = dstPixel[index].B;
                dstBMP.pImageData[i++] = dstPixel[index].G;
                dstBMP.pImageData[i++] = dstPixel[index].R;
            }
            i += dstPadding;
        }

        // giải phóng con trỏ mảng pixel
        delete[] dstPixel;
    }
}

// hàm in thông tin ảnh
void outputInfomations(BMP bmp) {
    cout << setw(21) << left << "\tSignature: " << bmp.header.signature[0] << bmp.header.signature[1] << endl;
    cout << setw(21) << left << "\tFile size: " << bmp.header.fileSize << " bytes" << endl;
    cout << setw(21) << left << "\tReserved: " << bmp.header.reserved << endl;
    cout << setw(21) << left << "\tOffset: " << bmp.header.dataOffset << endl;
    cout << setw(21) << left << "\tDIB size: " << bmp.dib.dibSize << " bytes" << endl;
    cout << setw(21) << left << "\tSize: " << bmp.dib.width << "x" << bmp.dib.height << " pixels" << endl;
    cout << setw(21) << left << "\tPlanes: " << bmp.dib.planes << endl;
    cout << setw(21) << left << "\tBits per pixel: " << bmp.dib.bitsPerPixel << " bit" << endl;
    cout << setw(21) << left << "\tCompression: " << bmp.dib.compression << endl;
    cout << setw(21) << left << "\tImage size: " << bmp.dib.imageSize << " bytes" << endl;
    cout << setw(21) << left << "\tX pixel per meter: " << bmp.dib.xPixelsPerM << endl;
    cout << setw(21) << left << "\tY pixel per meter: " << bmp.dib.yPixelsPerM << endl;
    cout << setw(21) << left << "\tColors used: " << bmp.dib.colorsUsed << endl;
    cout << setw(21) << left << "\tImportant color: " << bmp.dib.importantColor << endl << endl;
}

// hàm báo lỗi invalid nếu command line argument không hợp lệ
void invalid() {
    cout << "Invalid command." << endl;
    exit(-1);
}