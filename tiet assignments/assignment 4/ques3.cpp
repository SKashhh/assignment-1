#include <iostream>
using namespace std;

int main() {
    int n = 6; // size of queue (must be even)
    int arr[6] = {4, 7, 11, 20, 5, 9};

    int first[10], second[10];
    int i, j = 0, k = 0;

    // split into two halves
    for (i = 0; i < n/2; i++) {
        first[j++] = arr[i];
    }
    for (i = n/2; i < n; i++) {
        second[k++] = arr[i];
    }

    // interleave
    j = 0; k = 0;
    for (i = 0; i < n; i++) {
        if (i % 2 == 0)
            arr[i] = first[j++];
        else
            arr[i] = second[k++];
    }

    cout << "Interleaved Queue: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
