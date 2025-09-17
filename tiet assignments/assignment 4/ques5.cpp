#include <iostream>
using namespace std;

#define SIZE 100

int q1[SIZE], q2[SIZE];
int f1 = 0, r1 = -1, f2 = 0, r2 = -1;

void push(int x) {
    q2[++r2] = x;
    while (f1 <= r1) {
        q2[++r2] = q1[f1++];
    }
    // swap q1 and q2
    int tempArr[SIZE]; int tf=f1, tr=r1;
    for(int i=f1;i<=r1;i++) tempArr[i]=q1[i];
    f1=f2; r1=r2;
    for(int i=f2;i<=r2;i++) q1[i]=q2[i];
    f2=0; r2=-1;
}

int pop() {
    if (f1 > r1) return -1;
    return q1[f1++];
}

int top() {
    if (f1 > r1) return -1;
    return q1[f1];
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Top: " << top() << endl;
    cout << "Pop: " << pop() << endl;
    cout << "Top: " << top() << endl;

    return 0;
}
