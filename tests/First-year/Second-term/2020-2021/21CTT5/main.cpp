#include <iostream>
#include <stdlib.h>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Record {
    Date date;
    float weight;
    float height;
};

void InputARecord(Record &record) {
    cout << "\tInput the date:" << endl;
    cout << "\t\tDay: "; cin >> record.date.day;
    cout << "\t\tMonth: "; cin >> record.date.month;
    cout << "\t\tYear: "; cin >> record.date.year;
    cout << "\tInput the weight: "; cin >> record.weight;
    cout << "\tInput the height: "; cin >> record.height;
}

void InputRecords(Record *&record, int n) {
    for (int i = 0; i < n; i++) {
        cout << "RECORD " << i + 1 << ": " << endl;
        InputARecord(record[i]);
        cout << endl;
    }
}

void OutputARecord(Record record) {
    cout << "\tDate: " << record.date.day << "/" << record.date.month << "/" << record.date.year << endl;
    cout << "\tWeight: " << record.weight << endl;
    cout << "\tHeight: " << record.height << endl;
}

void OutputRecords(Record *record, int n) {
    for (int i = 0; i < n; i++) {
        cout << "RECORD " << i + 1 << ": " << endl;
        OutputARecord(record[i]);
        cout << endl;
    }
}

int SortDateAsc(const void *a, const void *b) {
    if (((Record*)a)->date.year != ((Record*)b)->date.year) {
        return ((Record*)a)->date.year - ((Record*)b)->date.year;
    }
    if (((Record*)a)->date.month != ((Record*)b)->date.month) {
        return ((Record*)a)->date.month - ((Record*)b)->date.month;
    }
    if (((Record*)a)->date.day != ((Record*)b)->date.day) {
        return ((Record*)a)->date.day - ((Record*)b)->date.day;
    }
    return 0;
}

int SortDateDesc(const void *a, const void *b) {
    if (((Record*)a)->date.year != ((Record*)b)->date.year) {
        return ((Record*)b)->date.year - ((Record*)a)->date.year;
    }
    if (((Record*)a)->date.month != ((Record*)b)->date.month) {
        return ((Record*)b)->date.month - ((Record*)a)->date.month;
    }
    if (((Record*)a)->date.day != ((Record*)b)->date.day) {
        return ((Record*)b)->date.day - ((Record*)a)->date.day;
    }
    return 0;
}

void DeleteARecord(Record *&record, int &n, int index) {
    n--;
    Record *newrecord = new Record[n];
    int j = 0;
    for (int i = 0; i < n + 1; i++) {
        if (i == index) {
            continue;
        }
        newrecord[j++] = record[i];
    }
    delete[] record;
    record = newrecord;
}

void DeleteSameMonth(Record *&record, int &n) {
    for (int i = 0; i < n - 1; i++) {
        if (record[i].date.month == record[i + 1].date.month && record[i].date.year == record[i + 1].date.year) {
            DeleteARecord(record, n, i + 1);
            i--;
        }
    }
}

int main() {
    int n;
    cout << "Input the number of records: "; cin >> n; cout << endl;
    Record *record = new Record[n];

    InputRecords(record, n);
    cout << endl << "====== SORT ASCENDING BY DATE ======" << endl << endl;
    qsort(record, n, sizeof(Record), SortDateAsc);
    OutputRecords(record, n);

    cout << endl << "====== SORT DESCENDING BY DATE ======" << endl << endl;
    qsort(record, n, sizeof(Record), SortDateDesc);
    OutputRecords(record, n);

    cout << endl << "====== DELETE SAME MONTH ======" << endl << endl;
    DeleteSameMonth(record, n);
    OutputRecords(record, n);

    delete[] record;

    return 0;
}