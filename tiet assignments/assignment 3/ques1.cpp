#include <iostream>
using namespace std;

#define SIZE 5  // stack size

class Stack {
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack is full! Cannot push." << endl;
        } else {
            arr[++top] = x;
            cout << x << " pushed into stack." << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == SIZE - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        case 4:
            cout << (s.isFull() ? "Stack is full." : "Stack is not full.") << endl;
            break;
        case 5:
            s.display();
            break;
        case 6:
            s.peek();
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}
