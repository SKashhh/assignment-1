#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

DNode* head = NULL;

// Insert anywhere (first, last, after/before)
void insertFirst(int val) {
    DNode* newNode = new DNode();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head) head->prev = newNode;
    head = newNode;
}

void insertLast(int val) {
    DNode* newNode = new DNode();
    newNode->data = val;
    newNode->next = NULL;
    if (!head) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    DNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertBeforeAfter(int key, int val, bool before) {
    if (!head) { cout << "List empty!\n"; return; }
    DNode* temp = head;
    while (temp && temp->data != key)
        temp = temp->next;
    if (!temp) { cout << "Node not found!\n"; return; }

    DNode* newNode = new DNode();
    newNode->data = val;

    if (before) {
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev) temp->prev->next = newNode;
        else head = newNode;
        temp->prev = newNode;
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }
}

// Delete specific node
void deleteNode(int key) {
    if (!head) { cout << "Empty list!\n"; return; }
    DNode* temp = head;
    while (temp && temp->data != key)
        temp = temp->next;
    if (!temp) { cout << "Node not found!\n"; return; }

    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
}

// Search node
void search(int key) {
    DNode* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found!\n";
}

// Display
void display() {
    DNode* temp = head;
    cout << "Doubly Linked List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Menu
int main() {
    int choice, val, key;
    bool before;
    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before/After Node\n4. Delete Node\n5. Search Node\n6. Display\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; insertFirst(val); break;
            case 2: cout << "Enter value: "; cin >> val; insertLast(val); break;
            case 3:
                cout << "Enter key: "; cin >> key;
                cout << "Enter value: "; cin >> val;
                cout << "Insert before(1) or after(0)? "; cin >> before;
                insertBeforeAfter(key, val, before);
                break;
            case 4: cout << "Enter node to delete: "; cin >> key; deleteNode(key); break;
            case 5: cout << "Enter value to search: "; cin >> key; search(key); break;
            case 6: display(); break;
            case 7: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
