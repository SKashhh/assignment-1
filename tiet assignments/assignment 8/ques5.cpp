#include <iostream>
using namespace std;

// function to heapify a subtree
void heapify(int arr[], int n, int i, bool isMaxHeap)
{
    int extreme = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // for increasing order (max heap)
    if (isMaxHeap)
    {
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    }
    // for decreasing order (min heap)
    else
    {
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    // if root is not extreme
    if (extreme != i)
    {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, isMaxHeap);
    }
}

void heapSort(int arr[], int n, bool increasing = true)
{
    bool isMaxHeap = increasing;

    // build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    // extract elements one by one
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, isMaxHeap);
    }
}

int main()
{
    int arr[] = {15, 3, 17, 8, 22, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n, true); // increasing order
    cout << "\nSorted in Increasing Order: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    int arr2[] = {15, 3, 17, 8, 22, 9, 1};
    heapSort(arr2, n, false); // decreasing order
    cout << "\nSorted in Decreasing Order: ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";

    cout << endl;
    return 0;
}
