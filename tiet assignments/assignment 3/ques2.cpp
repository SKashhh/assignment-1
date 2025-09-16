#include <iostream>
using namespace std;

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int strLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin >> str;

    int n = strLength(str);
    for (int i = 0; i < n; i++) {
        push(str[i]);
    }

    cout << "Reversed string: ";
    while (top != -1) {
        cout << pop();
    }
    cout << endl;

    return 0;
}
