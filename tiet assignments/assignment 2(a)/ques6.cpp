/*
Write a program to implement the following operations on a Sparse Matrix, assuming the matrix is represented using a triplet.
(a) Transpose of a matrix.
(b) Addition of two matrices.
(c) Multiplication of two matrices.*/
#include <iostream>
using namespace std;

// Structure for sparse matrix in triplet form
struct SparseMatrix {
    int row;
    int col;
    int value;
};

void printSparse(SparseMatrix mat[], int n) {
    cout << "Row Col Value" << endl;
    for (int i = 0; i <= n; i++) {
        cout << mat[i].row << " " << mat[i].col << " " << mat[i].value << endl;
    }
}

// Function for transpose
void transpose(SparseMatrix a[], SparseMatrix b[]) {
    int n = a[0].value;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

    int k = 1;
    for (int i = 0; i < a[0].col; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j].col == i) {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].value = a[j].value;
                k++;
            }
        }
    }
}

// Function for addition of two sparse matrices
void add(SparseMatrix a[], SparseMatrix b[], SparseMatrix c[]) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        cout << "Addition not possible!" << endl;
        return;
    }

    c[0].row = a[0].row;
    c[0].col = a[0].col;

    int i = 1, j = 1, k = 1;
    while (i <= a[0].value && j <= b[0].value) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].value = a[i].value + b[j].value;
            i++; j++; k++;
        }
        else if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            c[k] = a[i];
            i++; k++;
        }
        else {
            c[k] = b[j];
            j++; k++;
        }
    }

    while (i <= a[0].value) {
        c[k] = a[i];
        i++; k++;
    }
    while (j <= b[0].value) {
        c[k] = b[j];
        j++; k++;
    }

    c[0].value = k - 1;
}

// Function for multiplication
void multiply(SparseMatrix a[], SparseMatrix b[], SparseMatrix c[]) {
    if (a[0].col != b[0].row) {
        cout << "Multiplication not possible!" << endl;
        return;
    }

    SparseMatrix temp[100];
    int k = 1;

    for (int i = 1; i <= a[0].value; i++) {
        for (int j = 1; j <= b[0].value; j++) {
            if (a[i].col == b[j].row) {
                int r = a[i].row;
                int ccol = b[j].col;
                int val = a[i].value * b[j].value;

                bool found = false;
                for (int x = 1; x < k; x++) {
                    if (temp[x].row == r && temp[x].col == ccol) {
                        temp[x].value += val;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    temp[k].row = r;
                    temp[k].col = ccol;
                    temp[k].value = val;
                    k++;
                }
            }
        }
    }

    temp[0].row = a[0].row;
    temp[0].col = b[0].col;
    temp[0].value = k - 1;

    for (int i = 0; i <= temp[0].value; i++) {
        c[i] = temp[i];
    }
}

int main() {
    // Example sparse matrix A
    SparseMatrix A[10] = {
        {3, 3, 4},   // rows, cols, non-zero count
        {0, 0, 5},
        {0, 2, 8},
        {1, 1, 3},
        {2, 0, 6}
    };

    // Example sparse matrix B
    SparseMatrix B[10] = {
        {3, 3, 3},
        {0, 1, 7},
        {1, 2, 9},
        {2, 2, 4}
    };

    cout << "Matrix A:" << endl;
    printSparse(A, A[0].value);

    cout << "Matrix B:" << endl;
    printSparse(B, B[0].value);

    // Transpose
    SparseMatrix T[10];
    transpose(A, T);
    cout << "Transpose of A:" << endl;
    printSparse(T, T[0].value);

    // Addition
    SparseMatrix C[20];
    add(A, B, C);
    cout << "A + B:" << endl;
    printSparse(C, C[0].value);

    // Multiplication
    SparseMatrix M[30];
    multiply(A, B, M);
    cout << "A * B:" << endl;
    printSparse(M, M[0].value);

    return 0;
}
