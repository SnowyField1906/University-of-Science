#include <iostream>
#include <iomanip>
#include <string>
#include "MyFunctions.h"

using namespace std;

struct Dish {
    string name;
    int price;
}; //struct dish gồm tên và giá món ăn

struct Serving {
    int n;
    char name;
    Dish *dish;
}; //struct serving gồm 1 phần ăn với n món ăn


Dish *CreateDishArray(int n) {
    Dish *dish = new Dish[n];
    if (dish == NULL) {
        return NULL;
    }
    return dish;
}

void DeleteDishArray(Serving *& serving, int n) {
    for (int i = 0; i < n; i++) {
        if (serving[i].dish != NULL) {
            delete[] serving[i].dish;
            serving[i].dish = NULL;
        }
        else {
            serving[i].dish = NULL;
        }
    }
}

void DeleteServingArray(Serving *&serving) {
    if (serving != NULL) {
        delete[] serving;
        serving = NULL;
    }
    else {
        serving = NULL;
    }
}

void Increase(Serving*& serving, int& n) {
    n++;
    Serving* newserving = new Serving[n];
    for (int i = 0; i < n - 1; i++) {
        newserving[i] = serving[i];
    }
    DeleteServingArray(serving);
    serving = newserving;
}

void Choosing(Serving *&serving, int& n, char type) {
    char answer;

    switch (type) {
        case 'A':
            cout << "Imported serving type A! Do you want to order one more? (Y/N) "; cin >> answer;
            while (answer != 'Y' && answer != 'N') {
                cout << "Wrong input, please input again! (Y/N) "; cin >> answer;
            }

            Increase(serving, n);

            serving[n - 1].n = 3; serving[n - 1].dish = CreateDishArray(serving[n - 1].n);
            serving[n - 1].name = 'A';
            serving[n - 1].dish[0].name = "Burger"; serving[n - 1].dish[0].price = 130;
            serving[n - 1].dish[1].name = "Drink"; serving[n - 1].dish[1].price = 130;
            serving[n - 1].dish[2].name = "Potato"; serving[n - 1].dish[2].price = 120;

            if (answer == 'Y') {
                cout << endl << "Please input a serving type (A/B/C/D) "; cin >> type;
                while (type != 'A' && type != 'B' && type != 'C' && type != 'D') {
                    cout << "Wrong input, please input again! (A/B/C/D) "; cin >> type;
                }

                Choosing(serving, n, type);
            }

            else if (answer == 'N') {
                Choosing(serving, n, 'X');
            }

            break;

        case 'B':
            cout << "Imported serving type B! Do you want to order one more? (Y/N) "; cin >> answer;
            while (answer != 'Y' && answer != 'N') {
                cout << "Wrong input, please input again! (Y/N) "; cin >> answer;
            }

            Increase(serving, n);

            serving[n - 1].n = 3; serving[n - 1].dish = CreateDishArray(serving[n - 1].n);
            serving[n - 1].name = 'B';
            serving[n - 1].dish[0].name = "Cheese burger"; serving[n - 1].dish[0].price = 150;
            serving[n - 1].dish[1].name = "Drink"; serving[n - 1].dish[1].price = 130;
            serving[n - 1].dish[2].name = "Potato"; serving[n - 1].dish[2].price = 120;

            if (answer == 'Y') {
                cout << endl << "Please input a serving type (A/B/C/D) "; cin >> type;
                while (type != 'A' && type != 'B' && type != 'C' && type != 'D') {
                    cout << "Wrong input, please input again! (A/B/C/D) "; cin >> type;
                }

                Choosing(serving, n, type);
            }

            else if (answer == 'N') {
                Choosing(serving, n, 'X');
            }

            break;

        case 'C':
            cout << "Imported serving type C! Do you want to order one more? (Y/N) "; cin >> answer;
            while (answer != 'Y' && answer != 'N') {
                cout << "Wrong input, please input again! (Y/N) "; cin >> answer;
            }

            Increase(serving, n);

            serving[n - 1].n = 3; serving[n - 1].dish = CreateDishArray(serving[n - 1].n);
            serving[n - 1].name = 'C';
            serving[n - 1].dish[0].name = "Chicken burger"; serving[n - 1].dish[0].price = 200;
            serving[n - 1].dish[1].name = "Drink"; serving[n - 1].dish[1].price = 130;
            serving[n - 1].dish[2].name = "Potato"; serving[n - 1].dish[2].price = 120;

            if (answer == 'Y') {
                cout << endl << "Please input a serving type (A/B/C/D) "; cin >> type;
                while (type != 'A' && type != 'B' && type != 'C' && type != 'D') {
                    cout << "Wrong input, please input again! (A/B/C/D) "; cin >> type;
                }

                Choosing(serving, n, type);
            }

            else if (answer == 'N') {
                Choosing(serving, n, 'X');
            }

            break;

        case 'D':
            cout << "Imported serving type D! Do you want to order one more? (Y/N) "; cin >> answer;
            while (answer != 'Y' && answer != 'N') {
                cout << "Wrong input, please input again! (Y/N) "; cin >> answer;
            }

            Increase(serving, n);

            serving[n - 1].n = 4; serving[n - 1].dish = CreateDishArray(serving[n - 1].n);
            serving[n - 1].name = 'D';
            serving[n - 1].dish[0].name = "Chicken burger"; serving[n - 1].dish[0].price = 200;
            serving[n - 1].dish[1].name = "Drink"; serving[n - 1].dish[1].price = 130;
            serving[n - 1].dish[2].name = "Potato"; serving[n - 1].dish[2].price = 120;
            serving[n - 1].dish[3].name = "Ice cream"; serving[n - 1].dish[3].price = 160;


            if (answer == 'Y') {
                cout << endl << "Please input a serving type (A/B/C/D) "; cin >> type;
                while (type != 'A' && type != 'B' && type != 'C' && type != 'D') {
                    cout << "Wrong input, please input again! (A/B/C/D) "; cin >> type;
                }

                Choosing(serving, n, type);
            }

            else if (answer == 'N') {
                Choosing(serving, n, 'X');
            }

            break;

        default:
            Bill(serving, n);
        }
}

void Bill(Serving *&serving, int n) {
    int total = 0;
    cout << endl << "======= YOUR BILL =======" << endl << endl;
    for (int i = 0; i < n; i++) {
        cout << "---------TYPE " << serving[i].name << "---------" << endl;
        for (int j = 0; j < serving[i].n; j++) {
            cout << setw(15) << right << serving[i].dish[j].name << ": " << serving[i].dish[j].price << " JPY" << endl;
        }
    }
    cout << "------------------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < serving[i].n; j++) {
            total += serving[i].dish[j].price;
        }
    }
    cout << setw(17) << right << "TOTAL PRICE: " << total << " JPY" << endl;
    cout << setw(17) << right << "FINAL PRICE: " << total * 90 / 100 << " JPY" << endl;
}

void Menu() {
    cout << endl << "\t\t\t      DISHES' PRICES" << endl << endl;

    cout << setfill('-');
    cout << "\t\t\t" << setw(26) << "-" << endl;
    cout << setfill(' ');

    cout << "\t\t\t|" << setw(16) << right << " Dishes ";
    cout << setw(15) << left << "| Price |" << endl;

    cout << setfill('-');
    cout << "\t\t\t" << setw(26) << "-" << endl;
    cout << setfill(' ');

    cout << "\t\t\t|" << setw(16) << right << "Burger ";
    cout << setw(15) << left << "| 130   |" << endl;

    cout << "\t\t\t|" << setw(16) << right << "Cheese burger ";
    cout << setw(15) << left << "| 150   |" << endl;

    cout << "\t\t\t|" << setw(16) << right << "Chicken burger ";
    cout << setw(15) << left << "| 200   |" << endl;

    cout << "\t\t\t|" << setw(16) << right << "Drink ";
    cout << setw(15) << left << "| 130   |" << endl;

    cout << "\t\t\t|" << setw(16) << right << "Potato ";
    cout << setw(15) << left << "| 120   |" << endl;

    cout << "\t\t\t|" << setw(16) << right << "Ice cream ";
    cout << setw(15) << left << "| 160   |" << endl;

    cout << setfill('-');
    cout << "\t\t\t" << setw(26) << "-" << endl;
    cout << setfill(' ');
}

void Infomation() {
    cout << endl << "\t\t  CHOOSE ONE OF THE SERVING TYPES BELOW:" << endl << endl;

    cout << setfill('-');
    cout << "  " << setw(65) << "-" << endl;
    cout << setfill(' ');

    cout << "  |" << setw(5) << left << " No.";
    cout << setw(15) << left << "| Serving Type";
    cout << setw(43) << left << "| ADish" << left << "|" << endl;

    cout << setfill('-');
    cout << "  " << setw(65) << "-" << endl;
    cout << setfill(' ');

    cout << "  |" << setw(5) << right << "1 ";
    cout << setw(15) << left << "|    Type A";
    cout << setw(16) << left << "| Burger" << setw(27) << ", Drink, Potato";
    cout << "|" << endl;

    cout << "  |" << setw(5) << right << "2 ";
    cout << setw(15) << left << "|    Type B";
    cout << setw(16) << left << "| Cheese burger" << setw(27) << ", Drink, Potato";
    cout << "|" << endl;

    cout << "  |" << setw(5) << right << "3 ";
    cout << setw(15) << left << "|    Type C";
    cout << setw(43) << left << "| Chicken burger, Drink, Potato";
    cout << "|" << endl;

    cout << "  |" << setw(5) << right << "4 ";
    cout << setw(15) << left << "|    Type D";
    cout << setw(43) << left << "| Chicken burger, Drink, Potato, Ice cream";
    cout << "|" << endl;

    cout << setfill('-');
    cout << "  " << setw(65) << "-" << endl;
    cout << setfill(' ');
}