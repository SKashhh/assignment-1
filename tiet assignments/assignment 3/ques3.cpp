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

bool isEmpty() {
    return (top == -1);
}

char peek() {
    return stack[top];
}

int strLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

bool isBalanced(char exp[]) {
    int n = strLength(exp);
    for (int i = 0; i < n; i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty()) return false;
            char topChar = pop();
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    return isEmpty();
}

int main() {
    char exp[MAX];
    cout << "Enter expression: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
