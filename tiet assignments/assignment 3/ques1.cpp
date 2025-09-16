#include <iostream>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == MAX - 1);
}

void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow!\n";
    } else {
        stack[++top] = x;
        cout << x << " pushed.\n";
    }
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!\n";
        return -1; // error
    } else {
        return stack[top--];
    }
}

int peek() {
    if (isEmpty()) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return stack[top];
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty!\n";
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, val;
    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; push(val); break;
            case 2: val = pop(); if (val != -1) cout << "Popped: " << val << endl; break;
            case 3: val = peek(); if (val != -1) cout << "Top element: " << val << endl; break;
            case 4: cout << (isEmpty() ? "Stack is empty\n" : "Stack is not empty\n"); break;
            case 5: cout << (isFull() ? "Stack is full\n" : "Stack is not full\n"); break;
            case 6: display(); break;
        }
    } while (choice != 0);

    return 0;
}
