#ifndef MyFunctions_h
#define MyFunctions_h

struct Node;

struct List;

// hàm khởi tạo list rỗng
void initList(List &list);

// hàm check xem list có rỗng hay không
bool isEmpty(List list);

// hàm tạo một node mới với data là một int
Node *createNode(int a);

// hàm thêm một node vào đầu list
void insertHead(List &list, int a);

// hàm chuyển number thành list
void numberToList(List &list, int n);

// hàm in ra các phần tử của list
void outputList(List list);

#endif /* MyFunctions_h */