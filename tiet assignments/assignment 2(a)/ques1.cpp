/*
1) Implement the Binary search algorithm regarded 
as a fast search algorithm with run-time complexity
 of Ο(log n) in comparison to the Linear Search.
*/
#include <iostream>
using namespace std;

int arr[100];
int size, i, j, temp, val;

void createarray() {
    cout << "Enter number of elements in array: ";
    cin >> size;
    cout << "Enter elements of the array:\n";
    for (i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void displayarray() {
    cout << "Your array is: ";
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortarray() {
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void binarysearch() {
    int low = 0, high = size - 1, mid;
    cout << "Enter value to search: ";
    cin >> val;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == val) {
            cout << "Element found at position " << mid << endl;
            return;
        } else if (arr[mid] < val) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << "Element not found\n";
}

int main() {
    createarray();
    cout << "Original ";
    displayarray();

    sortarray();
    cout << "Sorted ";
    displayarray();

    binarysearch();
    return 0;
}
