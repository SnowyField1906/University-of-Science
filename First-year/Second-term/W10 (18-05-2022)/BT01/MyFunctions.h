#ifndef MyFunctions_h
#define MyFunctions_h

struct Node;

struct List;

// hàm khởi tạo list rỗng
void initList(List& list);

// hàm check xem list rỗng hay không
bool isEmpty(List list);

// hàm tạo một node mới với data là một int
Node* createNode(int a);

// hàm thêm 1 node vào cuối list
void insertTail(List& list, int a);

// hàm xoá một node
void deleteNode(List& list, Node* node);

// hàm xoá node có data bằng a
void removeAllX(List& list, Node* node, int a);

// hàm in ra danh sách số nguyên
void outputList(List list);

#endif /* MyFunctions_h */