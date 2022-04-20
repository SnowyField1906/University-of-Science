#include <iostream>
#include <fstream>

using namespace std;

// void import(char* fileA, char *fileB) {
//     int n, m;
//     int *pA, *pB;
//     ofstream finA(fileA, ios::binary);
//     ofstream finB(fileB, ios::binary);
//     cin >> n;
//     pA = new int[n];
//     for (int i = 0; i < n; i++) {
//         cin >> pA[i];
//     }
//     cin >> m;
//     pB = new int[m];
//     for (int i = 0; i < m; i++) {
//         cin >> pB[i];
//     }
//     finA.write((char *)&n, sizeof(int));
//     finA.write((char *)pA, sizeof(int) * n);
//     finB.write((char*)&m, sizeof(int));
//     finB.write((char*)pB, sizeof(int) * m);

//     finA.close();
//     finB.close();
//     delete[] pA;
//     delete[] pB;
// } 

void Append(char* fileA, char* fileB, char* fileC) {
    // import(fileA, fileB);
    int n, m;
    int *pA, *pB, *pC;
    ifstream finA(fileA, ios::binary);
    ifstream finB(fileB, ios::binary);

    finA.read((char*)&n, sizeof(int));
    pA = new int[n];
    finA.read((char*)pA, sizeof(int) * n);
    finA.close();

    finB.read((char*)&m, sizeof(int));
    pB = new int[m];
    finB.read((char*)pB, sizeof(int) * m);
    finB.close();

    pC = new int[n + m];
    for (int i = 0; i < n; i++) {
        pC[i] = pA[i];
    }
    for (int i = 0; i < m; i++) {
        pC[i + n] = pB[i];
    }

    int k = m + n;
    ofstream fout(fileC, ios::binary);
    fout.write((char*)&k, sizeof(int));
    fout.write((char*)pC, sizeof(int) * k);
    fout.close();
    
    delete[] pA;
    delete[] pB;
    delete[] pC;
}

int main() {
    char *fileA = (char*)"fileA.bin";
    char *fileB = (char*)"fileB.bin";
    char *fileC = (char*)"fileC.bin";
    Append(fileA, fileB, fileC);
    return 0;
}