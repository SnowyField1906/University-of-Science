#ifndef MyFunctions_h
#define MyFunctions_h

struct Book;

struct Node;

struct List;

// hàm khởi tạo list rỗng
void initList(List& list);

// hàm check xem list rỗng hay không
bool isEmpty(List list);

// hàm tạo một node mới với data là book
Node* createNode(Book book);

// hàm thêm 1 node vào cuối list
void insertTail(List& list, Book book);

// hàm xoá một node
void deleteNode(List& list, Node* node);

// hàm nhập book
void inputBook(List& list);

// hàm bán book
void sellBook(List list, char ISBN[]);

// hàm check xem name có tồn tại trong title hay không
bool contain(char title[], char name[]);

// hàm tìm kiếm book theo name
void findBook(List list, char name[]);

// hàm xoá book có stock nhỏ hơn k
bool removeBookLessThanK(List& list, Node* node, int k, bool flag);

// hàm in ra danh sách book
void outputList(List list);

// hàm menu
void Menu(List& list);

#endif /* MyFunctions_h */