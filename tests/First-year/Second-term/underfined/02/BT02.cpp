#include <iostream>
#include <fstream>

using namespace std;

void convertTextToBinary(char*filename1, char*filename2) {
    ifstream fin(filename1);
    ofstream fout(filename2, ios::binary);

    int M, N;
    int **matrix = new int*[M];
    for (int i = 0; i < M; i++)
    {
        matrix[i] = new int[N];
    }

    fin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fin >> matrix[i][j];
        }
    }

    fout.write((char *)&M, sizeof(int));
    fout.write((char *)&N, sizeof(int));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fout.write((char *)&(matrix[i][j]), sizeof(int));
        }
    }
    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    fin.close();
    fout.close();
}

void convertBinaryToText(char*filename1, char*filename2) {
    ifstream fin(filename2, ios::binary);
    ofstream fout(filename1);

    int M, N;
    fin.read((char *)&M, sizeof(int));
    fin.read((char *)&N, sizeof(int));

    int **matrix = new int *[M];
    for (int i = 0; i < M; i++) {
        matrix[i] = new int[N];
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fin.read((char *)&(matrix[i][j]), sizeof(int));
        }
    }

    fout << M << " " << N << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fout << matrix[i][j] << " ";
        }
        fout << endl;
    }

    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    fin.close();
    fout.close();
}

int main() {
    convertTextToBinary((char *)"convertTextToBinary.txt", (char *)"convertTextToBinary.bin");
    convertBinaryToText((char *)"convertBinaryToText.txt", (char *)"convertBinaryToText.bin");
    return 0;
}