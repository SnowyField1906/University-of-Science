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

// hàm thêm một node vào cuối list
void insertTail(List &list, int a);

// hàm chuyển list thành number
int listToNumber(Node *node);

#endif /* MyFunctions_h */