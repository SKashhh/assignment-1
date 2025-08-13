/*
4) Implement the logic to
a. Reverse the elements of an array
b. Find the matrix multiplication
c. Find the Transpose of a Matrix
*/
//a)
#include <iostream>
using namespace std;

int arr[100];
int size, i, temp;

void createarray() {
    cout << "Enter number of elements in array: ";
    cin >> size;
    cout << "Enter the elements:\n";
    for (i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void displayarray() {
    cout << "Array: ";
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reversearray() {
    for (i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    createarray();
    cout << "Original ";
    displayarray();
    reversearray();
    cout << "Reversed ";
    displayarray();
    return 0;
}
//b)
#include <iostream>
using namespace std;

int mat1[10][10], mat2[10][10], result[10][10];
int r1, c1, r2, c2, i, j, k;

int main() {
    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter elements of first matrix:\n";
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            cin >> mat1[i][j];

    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;
    if (c1 != r2) {
        cout << "Matrix multiplication not possible\n";
        return 0;
    }

    cout << "Enter elements of second matrix:\n";
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            cin >> mat2[i][j];

    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (k = 0; k < c1; k++)
                result[i][j] += mat1[i][k] * mat2[k][j];
        }

    cout << "Resultant matrix:\n";
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    return 0;
}
//c)
#include <iostream>
using namespace std;

int mat[10][10], transpose[10][10];
int r, c, i, j;

int main() {
    cout << "Enter rows and columns of the matrix: ";
    cin >> r >> c;

    cout << "Enter elements of the matrix:\n";
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            cin >> mat[i][j];

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            transpose[j][i] = mat[i][j];

    cout << "Transpose of the matrix:\n";
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++)
            cout << transpose[i][j] << " ";
        cout << endl;
    }

    return 0;
}
