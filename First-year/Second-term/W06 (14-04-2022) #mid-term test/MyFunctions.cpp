#include <iostream>
#include <string.h>
#include "MyFunctions.h"

using namespace std;

struct Cat {
    int id;
    char* type = new char[10];
    char* color = new char[10];
    float weight;
};

///////////////////
char* trimCharArray(char*& c) {
    char* c2 = new char[strlen(c)];
    strcpy_s(c2, strlen(c) + 1, c);
    c2[strlen(c)] = '\0';
    return c2;
}
void inputACat(Cat& catList) {
    cout << "\tInput the ID: "; cin >> catList.id;
    cin.ignore();
    cout << "\tInput the type: "; cin.getline(catList.type, 10);
    cout << "\tInput the color: "; cin.getline(catList.color, 10);
    cout << "\tInput the weight: "; cin >> catList.weight;
    catList.type = trimCharArray(catList.type);
    catList.color = trimCharArray(catList.color);
}
void outputACat(Cat catList) {
    cout << "\tID: " << catList.id << endl;
    cout << "\tTpe: " << catList.type << endl;
    cout << "\tColor: " << catList.color << endl;
    cout << "\tWeight: " << catList.weight << endl;
}
void outputCats(Cat* catList, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Cat " << i + 1 << ":" << endl;
        outputACat(catList[i]);
    }
}
///////////////////

////// CÂU 1 //////
Cat* createArray(int n) {
    if (n <= 0) {
        return NULL;
    }
    else {
        Cat* catList = new Cat[n];
        return catList;
    }
}

////// CÂU 2 //////
bool checkEmpty(Cat* catList, int n) {
    if (catList == NULL || n == 0) {
        return true;
    }
    else {
        return false;
    }
}

////// CÂU 3 //////
void appendACat(Cat*& catList, Cat* newCatList, int& n) {
    n++;
    newCatList = createArray(n);

    for (int i = 0; i < n - 1; i++) {
        newCatList[i] = catList[i];
    }
    inputACat(newCatList[n - 1]);
    catList = newCatList;
}

////// CÂU 4 //////
void popACat(Cat*& catList, Cat* newCatList, int& n) {
    n--;
    newCatList = createArray(n);
    for (int i = 0; i < n; i++) {
        newCatList[i] = catList[i];
    }
    catList = newCatList;
}

////// CÂU 5 //////
void findLeastWeightCat(Cat*& catList, int& n) {
    float min = catList[0].weight;
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (catList[i].weight < min) {
            min = catList[i].weight;
            index = i;
        }
    }
    cout << "The least weight cat is: \nCat " << index + 1 << ":" << endl;
    outputACat(catList[index]);
}

////// CÂU 6 //////
void updateColor(Cat*& catList, int n) {
    int index;
    cout << "Input the index (1.." << n << "): "; cin >> index;
    while (index < 1 || index > n) {
        cout << "Wrong input, please input again! (1.." << n << "): "; cin >> index;
    }
    char* color = new char[10];
    cin.ignore();
    cout << "Input the new color: "; cin.getline(color, 10);
    catList[index - 1].color = trimCharArray(color);
}

////// CÂU 7 //////
void sortByWeight(Cat*& catList, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (catList[i].weight > catList[j].weight) {
                Cat temp = catList[i];
                catList[i] = catList[j];
                catList[j] = temp;
            }
        }
    }
}

//// CÂU 8 //////
void findMostWeightCats(Cat* catList, Cat* newCatList, int& n) {
    newCatList = createArray(n);
    for (int i = 0; i < n; i++) {
        newCatList[i] = catList[i];
    }
    sortByWeight(newCatList, n);
    cout << "The most weights cat is: " << endl;
    for (int i = n - 1; i > n - 4; i--) {
        cout << "Cat " << i + 1 << ": " << endl;
        outputACat(newCatList[i]);
    }
    delete[] newCatList;
}


////// CÂU 9 //////
void deleteArray(Cat*& catList) {
    if (catList != NULL) {
        delete[] catList;
        catList = NULL;
    }
    catList = NULL;
}

///////////////////

void menu(Cat*& catList, Cat* newCatList, int& n) {
    cout << "2: Check if the array was empty" << endl
        << "3: Append a cat" << endl
        << "4: Pop a cat" << endl
        << "5: Find the least weight cat" << endl
        << "6: Update the cat's color" << endl
        << "7: Sort ascending array by weight" << endl
        << "8: Find 3 most weight cats" << endl
        << "9: Output the array" << endl;
    int action;
    cout << endl << "Please choose an action (2..9): "; cin >> action;

    while (action < 1 || action > 10) {
        cout << "Wrong input! please input again (2..9): "; cin >> action;
    }

    switch (action) {
    case 2:
        if (checkEmpty(catList, n)) {
            cout << "The array is empty!" << endl;
        }
        else {
            cout << "The array is not empty!" << endl;
        }
        break;
    case 3:
        appendACat(catList, newCatList, n);
        cout << "Appended successfully!" << endl;
        break;
    case 4:
        if (n <= 0) {
            cout << "The array is empty!" << endl;
        }
        else {
            popACat(catList, newCatList, n);
            cout << "Popped successfully!" << endl;
        }
        break;
    case 5:
        findLeastWeightCat(catList, n);
        break;
    case 6:
        updateColor(catList, n);
        cout << "Updated successfully!" << endl;
        break;
    case 7:
        sortByWeight(catList, n);
        cout << "Sorted successfully!" << endl;
        break;
    case 8:
        if (n < 3) {
            cout << "Not enough cat!" << endl;
        }
        else {
            findMostWeightCats(catList, newCatList, n);
        }
        break;
    case 9:
        if (n <= 0) {
            cout << "The array is empty!" << endl;
        }
        else {
            outputCats(catList, n);
        }
        break;
    }

    char answer;
    cout << endl << "Do you want to continue? (Y/N): "; cin >> answer;
    while (answer != 'Y' && answer != 'N') {
        cout << "Wrong input! please input again (Y/N): "; cin >> answer;
    }
    if (answer == 'Y') {
        cout << endl;
        menu(catList, newCatList, n);
    }
}