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

// hàm nối 2 list bằng đệ quy
void join2List(Node *first, Node *second);

// hàm in ra các phần tử của list
void outputList(List list);

#endif /* MyFunctions_h */