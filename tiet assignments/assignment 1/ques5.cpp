/*
5) Write a program to find sum of every row and every column in a two-dimensional array.
*/
#include <iostream>
using namespace std;

int mat[10][10];
int r, c, i, j, sum;

int main() {
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    cout << "Enter elements of the matrix:\n";
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            cin >> mat[i][j];

    // Sum of each row
    for (i = 0; i < r; i++) {
        sum = 0;
        for (j = 0; j < c; j++)
            sum += mat[i][j];
        cout << "Sum of row " << i << " = " << sum << endl;
    }

    // Sum of each column
    for (j = 0; j < c; j++) {
        sum = 0;
        for (i = 0; i < r; i++)
            sum += mat[i][j];
        cout << "Sum of column " << j << " = " << sum << endl;
    }

    return 0;
}
