#include <iostream>
using namespace std;

#define SIZE 100

int q[SIZE];
int f = 0, r = -1;

void push(int x) {
    q[++r] = x;
    for (int i = 0; i < r - f; i++) {
        q[++r] = q[f++];
    }
}

int pop() {
    if (f > r) return -1;
    return q[f++];
}

int top() {
    if (f > r) return -1;
    return q[f];
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
