#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include<fstream>
using namespace std;

struct Student {
    string id;
    string name;
    string gpa;
    string address;
    string date_of_birth;
};

void Input(Student &st) {
    cout << "ID: "; cin >> st.id;
    cout << "Name: "; cin.ignore(100, '\n'); getline(cin, st.name);
    cout << "GPA: "; cin >> st.gpa;
    cout << "Address: "; cin.ignore(100, '\n'); getline(cin, st.address);
    cout << "Date of Birth (yyyy/mm/dd): "; cin >> st.date_of_birth;
}

int CountDay(int year, int month, int day) {
    unsigned long int total = day;
    int bonus = 0;
    int monthlist[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < month; i++) {
        total += monthlist[i];
    }
    for (int j = 0; j <= year; j++) {
        if ((year%4 == 0 && year%100 != 0) || (year%400 == 0)) {
            bonus += 1;
        }
    }
    total += year*365 + bonus;

    return total;
}

string FirstName(Student st) {
    string name = st.name;
    string first_name = name.substr(0, name.find(" "));
    return first_name;
}

string LastName(Student st) {
    int i;
    string name = st.name;
    string last_name = ""; 

    for (i = FirstName(st).length() + 1; i < name.length(); i++) {
        last_name += name[i];
    }

    return last_name;
}

string Age(Student st) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string stryear = ""; string strmonth = ""; string strday = "";
    string date_of_birth = st.date_of_birth;
    long int age;
    int i, yearage, monthage, dayage = 0;

    for (i = 0; i <= 3; i++) {
        stryear += date_of_birth[i];
    }
    for (i = 5; i <= 6; i++) {
        strmonth += date_of_birth[i];
    }
    for (i = 8; i <= 9; i++) {
        strday += date_of_birth[i];
    }

    int year = stoi(stryear) - 1900;
    int month = stoi(strmonth);
    int day = stoi(strday);


    yearage = ltm->tm_year - year;

    if (day > ltm->tm_mday) {
        monthage = month - 1;
        dayage = 30 + ltm->tm_mday - day;
    }
    else {
        dayage = ltm->tm_mday - day;
    }
    if (month > ltm->tm_mon) {
        yearage = yearage - 1;
        monthage = 12 + ltm->tm_mon - month;
    }
    else {
        monthage = ltm->tm_mon - monthage;
    }

    return to_string(yearage) + " years, " + to_string(monthage) + " months, " + to_string(dayage) + " days";
}

string Class(Student st) {
    return st.id;
}

void Read(Student &st, ifstream &FileIn) {
    getline(FileIn, st.id, '\n');
    getline(FileIn, st.name, '\n');
    getline(FileIn, st.gpa, '\n');
    getline(FileIn, st.address, '\n');
    getline(FileIn, st.date_of_birth, '\n');
}

void Write(Student &st, ofstream &FileOut) { 
       FileOut << "ID          : " << st.id << endl;
       FileOut << "Full Name   : " << st.name << endl;
       FileOut << "GPA         : " << st.gpa << endl ;
       FileOut << "Address     : " << st.address << endl;
       FileOut << "Day of birth: " << st.date_of_birth << endl;
}


void Output1(Student st) {
    cout << "ID           : " << st.id << endl;
    cout << "Full name    : " << st.name << endl;
    cout << "GPA          : " << st.gpa << endl;
    cout << "Address      : " << st.address << endl;
    cout << "Date of Birth: " << st.date_of_birth << endl;
}

void Output2(Student st) {
    cout << "ID           : " << st.id << endl;
    cout << "First name   : " << FirstName(st) << endl;
    cout << "Last name    : " << LastName(st) << endl;
    cout << "GPA          : " << st.gpa << endl;
    cout << "Address      : " << st.address << endl;
    cout << "Date of Birth: " << st.date_of_birth << endl;
    cout << "Age          : " << Age(st) << endl;
}

int main() {
    Student Thuan;
    Input(Thuan);
    cout << "\n---Output 1---" << endl;
    Output1(Thuan);
    cout << "\n---Output 2---" << endl;
    Output2(Thuan);
    cout << "\n---Output 3---" << endl;
    cout << "You are in K" << Class(Thuan)[0] << Class(Thuan)[1] << " class!" << endl;

    Student student1;
    Student student2;
    cout << "\n---Input 2 students to compare---" << endl;
    cout << "1. Input student 1:" << endl; Input(student1);
    cout << "2. Input student 2:" << endl; Input(student2);

    cout << "\n---Compare 2 students---" << endl;
    cout << "ID: " << student1.id << " and " << student2.id << endl;
    cout << "GPA: " << student1.gpa << " and " << student2.gpa << " ";
    if (student1.gpa > student2.gpa) {
        cout << "(student 1 has higher GPA!)" << endl;
    }
    else if (student1.gpa < student2.gpa) {
        cout << "(student 2 has higher GPA!)" << endl;
    }
    else {
        cout << "(2 students have the same GPA!)" << endl;
    }
    cout << "Name: " << student1.name << " and " << student2.name << endl;
    cout << "First name: " << FirstName(student1) << " and " << FirstName(student2) << endl;
    cout << "Last name: " << LastName(student1) << " and " << LastName(student2) << endl;
    cout << "Date of Birth: " << student1.date_of_birth << " and " << student2.date_of_birth << endl;

    cout << "---Read and write student from input.txt to output.txt---" << endl;
    Student textfile;
    ifstream FileIn;
    FileIn.open("input.txt", ios_base::in);
    if (FileIn.fail()) {
        cout <<"Error!" << endl;
        return 0;
    }
    cout <<"Read successfully!" << endl;
    Read(textfile, FileIn);

    ofstream FileOut;
    FileOut.open("output.txt", ios_base::in);
    if (FileIn.fail()) {
        cout <<"Error!" << endl;
        return 0;
    }
    cout <<"Write successfully!" << endl;
    Read(textfile, FileIn);
    Write(textfile, FileOut);

    FileIn.close();
    FileOut.close();

    // ifstream ifs;
    // ifs.open("input2.txt",ios_base::in);
    // if (ifs.fail() == true)
    //     {
    //         cout <<"File not opened yet!" << endl;
    //         return 0;
    //     }
    // cout <<"File opened successfully!" << endl;
    // Student x;
    // inputStudentByFile(x,ifs);
    // Student y;
    // inputStudentByFile(y,ifs);
    // ofstream ofs;
    // ofs.open("output2.txt",ios_base::out);
    // ofs.close();
    // ifs.close();

    return 0;
}