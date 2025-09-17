#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

// (a) Insert at beginning
void insertBegin(int x) {
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

// (b) Insert at end
void insertEnd(int x) {
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// (c) Insert before a given value
void insertBefore(int val, int x) {
    if (head == NULL) return;
    if (head->data == val) {  // before head
        insertBegin(x);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Value not found\n";
        return;
    }
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}

// (c) Insert after a given value
void insertAfter(int val, int x) {
    Node *temp = head;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Value not found\n";
        return;
    }
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}

// (d) Delete from beginning
void deleteBegin() {
    if (head == NULL) return;
    Node *temp = head;
    head = head->next;
    delete temp;
}

// (e) Delete from end
void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

// (f) Delete specific node
void deleteNode(int val) {
    if (head == NULL) return;
    if (head->data == val) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Value not found\n";
        return;
    }
    Node *delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

// (g) Search for a node
void searchNode(int val) {
    Node *temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == val) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found\n";
}

// (h) Display all nodes
void display() {
    Node *temp = head;
    if (temp == NULL) {
        cout << "List is empty\n";
        return;
    }
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, val, key;
    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a value\n";
        cout << "4. Insert after a value\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific node\n";
        cout << "8. Search for a node\n";
        cout << "9. Display\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 10) break;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; insertBegin(val); break;
            case 2: cout << "Enter value: "; cin >> val; insertEnd(val); break;
            case 3: cout << "Insert value: "; cin >> val; cout << "Before which value? "; cin >> key; insertBefore(key, val); break;
            case 4: cout << "Insert value: "; cin >> val; cout << "After which value? "; cin >> key; insertAfter(key, val); break;
            case 5: deleteBegin(); break;
            case 6: deleteEnd(); break;
            case 7: cout << "Enter value to delete: "; cin >> val; deleteNode(val); break;
            case 8: cout << "Enter value to search: "; cin >> val; searchNode(val); break;
            case 9: display(); break;
            default: cout << "Invalid choice\n";
        }
    }
    cout << "Program exited." << endl;
    return 0;
}
