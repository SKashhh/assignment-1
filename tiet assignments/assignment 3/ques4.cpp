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

char peek() {
    return stack[top];
}

bool isEmpty() {
    return (top == -1);
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

int strLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int k = 0, n = strLength(infix);

    for (int i = 0; i < n; i++) {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        } else {
            while (!isEmpty() && precedence(c) <= precedence(peek())) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while (!isEmpty()) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';

    cout << "Postfix: " << postfix << endl;
}

int main() {
    char infix[MAX];
    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix);

    return 0;
}
