/*
2) Design the logic to remove the duplicate elements from an Array 
and after the deletion the array should contain the unique elements.
*/
#include <iostream>
using namespace std;

int arr[100];
int size, i, j, k;

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

void removeduplicates() {
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                for (k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--;
                j--;
            }
        }
    }
}

int main() {
    createarray();
    displayarray();
    removeduplicates();
    displayarray();
    return 0;
}
