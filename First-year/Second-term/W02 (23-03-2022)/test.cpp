#include <iostream>
#include <string>
using namespace std;

struct Book{
    char id[7];
    char name[50];
    char authorName[50];
    char publisher[50];
    long long price;
    int pageNumber;
    int yearOfPub;

};

void inputList(Book *p, int n)
{
    p=new Book[n];
    for(int i=0; i<n; i++)
    {
        fflush(stdin);
        cout << "Nhap ma sach thu " << i+1 << ": " ; cin.getline(p->id,7);
        fflush(stdin);
        cout << "Nhap ten sach : "; cin.getline(p->name,50);
        fflush(stdin);
        cout << "Nhap ten tac gia : "; cin.getline(p->authorName,50);
        fflush(stdin);
        cout << "Nhap ten nha xuat ban: "; cin.getline(p->publisher,50);
        cout <<"Nhap gia ban cua sach: "; cin>>p->price;
        cout << "Nhap so trang cua sach: "; cin>>p->pageNumber;
        cout << "Nhap nam xuat ban cua sach: "; cin>>p->yearOfPub;
    }
    delete[] p;
}

void outputList(Book *p,int n)
{
    p=new Book[n];
    for (int i = 0; i < n; i++)
    {
        cout << "======SACH SO " <<i+1 << "=====" << endl;
        cout << "MA SACH: " <<p->id << endl;
        cout << "TEN SACH: " <<p->name << endl;
        cout << "TEN TAC GIA: " << p->authorName<< endl;
        cout << "TEN NHA XUAT BAN: " << p->publisher << endl;
        cout <<"GIA BAN:" <<p->price << " (ngan dong)" << endl;
        cout << "SO TRANG SACH: " << p->pageNumber << " trang" << endl;
        cout << "NAM XUAT BAN: " << p->yearOfPub << endl;
    }  
    delete[] p;
}
int main() {
    int x;
    cin >> x;
    Book *p=new Book[x];
    inputList(p,x);
    outputList(p,x);
    delete[] p;
}