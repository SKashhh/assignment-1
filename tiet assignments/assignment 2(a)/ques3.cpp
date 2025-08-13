/*
Design the Logic to Find a Missing Number in a Sorted Array
*/
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int missing = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            missing = i + 1;
            break;
        }
    }

    if (missing != -1) {
        cout << "The missing number is: " << missing << endl;
    } else {
        cout << "No number is missing in the array!" << endl;
    }

    return 0;
}
