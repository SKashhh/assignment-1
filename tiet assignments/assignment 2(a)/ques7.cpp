/* Let A[1 …. n] be an array of n real numbers.
 A pair (A[i], A[j ]) is said to be an inversion
  if these numbers are out of order, i.e., i < j
 but A[i]>A[j ]. Write a program to count the number 
 of inversions in an array.*/
 #include <iostream>
using namespace std;

int main() {
    double A[] = {2.5, 3.1, 1.2, 5.0, 4.3};
    int n = sizeof(A) / sizeof(A[0]);
    int inversions = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                inversions++;
            }
        }
    }

    cout << "Number of inversions: " << inversions << endl;
    return 0;
}
