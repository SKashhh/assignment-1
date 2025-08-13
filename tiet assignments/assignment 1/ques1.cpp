/*
1 Develop a Menu driven program to demonstrate the following operations of Arrays
——MENU——- 1.CREATE
2. DISPLAY
3. INSERT
4. DELETE
5. LINEAR SEARCH
6. EXIT 
*/
#include <iostream>
using namespace std;

int arr[100];
int size, i, pos, val;

void createarray() {
    cout << "Enter number of elements in array: ";
    cin >> size;
    if (size > 100) {
        cout << "You exceeded max array size limit\n";
        return;
    }
    cout << "Enter the elements:\n";
    for (i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Your array has been created\n";
}

void displayarray() {
    cout << "Your array is: ";
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertelement() {
    cout << "Enter the position at which you want to insert element (0-based index): ";
    cin >> pos;
    cout << "Enter the value you want to insert: ";
    cin >> val;

    if (pos < 0 || pos > size || size == 100) {
        cout << "Invalid position or array is full\n";
        return;
    }

    for (i = size - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = val;
    size++;

    cout << "Your new array is: ";
    displayarray();
}

void deleteelement() {
    cout << "Enter the position at which you want to delete element (0-based index): ";
    cin >> pos;

    if (pos < 0 || pos >= size) {
        cout << "Invalid position\n";
        return;
    }

    for (i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;

    cout << "Your new array is: ";
    displayarray();
}

void linearsearch() {
    cout << "Enter value you want to find in array: ";
    cin >> val;
    bool found = false;
    for (i = 0; i < size; i++) {
        if (arr[i] == val) {
            cout << "Your element is found at position " << i << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Element not found\n";
    }
}

void exitmenu() {
    cout << "You opted to exit the menu\n";
}

int main() {
    createarray();
    displayarray();
    insertelement();
    deleteelement();
    linearsearch();
    exitmenu();
    return 0;
}
