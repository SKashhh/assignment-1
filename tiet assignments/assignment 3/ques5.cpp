#include <iostream>
using namespace std;

#define MAX 100
int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int strLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int evaluatePostfix(char exp[]) {
    int n = strLength(exp);
    for (int i = 0; i < n; i++) {
        char c = exp[i];
        if (c >= '0' && c <= '9') {
            push(c - '0');
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push(power(val1, val2)); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[MAX];
    cout << "Enter postfix expression (single digit only): ";
    cin >> exp;

    cout << "Result = " << evaluatePostfix(exp) << endl;
    return 0;
}
