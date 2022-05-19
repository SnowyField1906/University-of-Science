#ifndef MyFunctions_h
#define MyFunctions_h

struct Header;

struct DIB;

struct BMP;

struct Pixel;


// hàm trả về tổng byte của ảnh
int getSize(int height, int width, int padding, int bpp);

// hàm trả về padding của ảnh
int getPadding(int width, int bpp);

// hàm trả về vị trí index trong mảng một chiều tại toạ độ (x, y)
int getIndex(int width, int x, int y);

// hàm trả về giá trị trung bình của một pixel
Pixel getAverage(Pixel srcPixel, Pixel dstPixel);


// hàm đọc file input
void readBMP(const char* filename, BMP& bmp);

// hàm xuất file output
void exportBMP(const char* filename, BMP bmp);

// hàm trả về mảng pixel từ mảng màu của ảnh 24-bit/32-bit
Pixel* convertToPixelArray(BMP bmp);

// hàm trả về mảng pixel đã resize từ mảng pixel gốc
Pixel* resizePixelArray(Pixel* srcPixel, int height, int width, int scale);

// hàm trả về mảng màu của ảnh 8-bit đã resize từ mảng màu gốc
char* resize8BitArray(char* srcArray, int height, int width, int scale);

// hàm chuyển ảnh sang 8-bit
void convertTo8Bit(BMP srcBMP, BMP& dstBMP, Pixel* srcPixel);

// hàm resize ảnh
void resize(BMP srcBMP, BMP& dstBMP, int scale);

// hàm in thông tin ảnh
void outputInfomations(BMP bmp);

// hàm báo lỗi invalid nếu command line argument không hợp lệ
void invalid();

#endif /* MyFunctions_h */