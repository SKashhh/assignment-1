/*
Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑐𝑜𝑙𝑢𝑚𝑛𝑠. Assuming array is used to store elements of the following matrices, implement an efficient way that reduces the space requirement.
(a) Diagonal Matrix.*/
#include<iostream>
using namespace std;
#include <iomanip>
int main(){
 int n;
 cout<<"no of rows and columns "<<endl;
 cin>>n;
 int arr[n];
 cout<<" enter elements(row major) ";
 for(int k = 0; k<n; k++){
    cin>>arr[k];
    //cout<<endl;
 }
 for(int i=0;i<n;i++){
    for(int j = 0; j<n;j++){
        if(i==j){
            cout<<arr[i]<<setw(3)<<" ";
        }
        else cout<<"0"<<setw(3)<<" ";
    }
    cout<<endl;
 }
    return 0;
}
//(b) Tri-diagonal Matrix.
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "No of rows and columns: ";
    cin >> n;

    int arr[3*n - 2];  // store only non-zero elements
    cout << "Enter " << 3*n - 2 << " elements (first lower, then main, then upper):\n";
    for (int k = 0; k < 3*n - 2; k++) {
        cin >> arr[k];
    }

    cout << "Tri-diagonal matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) { 
                // main diagonal
                cout << setw(5) << arr[n-1 + i] << " ";
            } 
            else if (i - j == 1) { 
                // lower diagonal
                cout << setw(5) << arr[i-1] << " ";
            } 
            else if (j - i == 1) { 
                // upper diagonal
                cout << setw(5) << arr[2*n - 1 + i] << " ";
            } 
            else {
                cout << setw(5) << 0 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
//(c) Lower triangular Matrix.
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "No of rows and columns: ";
    cin >> n;

    int size = n*(n+1)/2;
    int arr[size];
    cout << "Enter " << size << " elements (row-wise lower triangle):\n";
    for (int k = 0; k < size; k++) {
        cin >> arr[k];
    }

    cout << "Lower Triangular Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                int index = i*(i+1)/2 + j;
                cout << setw(5) << arr[index] << " ";
            } else {
                cout << setw(5) << 0 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
//(d) Upper triangular Matrix.
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "No of rows and columns: ";
    cin >> n;

    int size = n*(n+1)/2;
    int arr[size];
    cout << "Enter " << size << " elements (row-wise upper triangle):\n";
    for (int k = 0; k < size; k++) {
        cin >> arr[k];
    }

    cout << "Upper Triangular Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                int index = (i*n - (i*(i-1))/2) + (j - i);
                cout << setw(5) << arr[index] << " ";
            } else {
                cout << setw(5) << 0 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
//(e) Symmetric Matrix
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "No of rows and columns: ";
    cin >> n;

    int size = n*(n+1)/2;
    int arr[size];
    cout << "Enter " << size << " elements (row-wise lower triangle):\n";
    for (int k = 0; k < size; k++) {
        cin >> arr[k];
    }

    cout << "Symmetric Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                int index = i*(i+1)/2 + j;
                cout << setw(5) << arr[index] << " ";
            } else {
                int index = j*(j+1)/2 + i;
                cout << setw(5) << arr[index] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}


