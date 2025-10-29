#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert as first node
void insertAtBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

// Insert before or after specific node
void insertBeforeAfter(int key, int val, bool before) {
    if (!head) { cout << "List empty!\n"; return; }
    Node* newNode = new Node();
    newNode->data = val;

    Node* temp = head;
    Node* prev = NULL;
    do {
        if (temp->data == key) break;
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    if (temp->data != key) { cout << "Node not found!\n"; delete newNode; return; }

    if (before) {
        if (temp == head) { // before head
            insertAtBeginning(val);
            delete newNode;
            return;
        }
        prev->next = newNode;
        newNode->next = temp;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Delete specific node
void deleteNode(int key) {
    if (!head) { cout << "List empty!\n"; return; }

    Node* temp = head;
    Node* prev = NULL;
    do {
        if (temp->data == key) break;
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    if (temp->data != key) {
        cout << "Node not found!\n";
        return;
    }

    if (temp == head && temp->next == head) { // single node
        delete temp;
        head = NULL;
        return;
    }

    if (temp == head) { // delete head
        Node* last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
        delete temp;
    } else {
        prev->next = temp->next;
        delete temp;
    }
}

// Search for a node
void search(int key) {
    if (!head) { cout << "List empty!\n"; return; }
    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    cout << "Not found!\n";
}

// Display (repeat head at end)
void display() {
    if (!head) { cout << "List empty!\n"; return; }
    Node* temp = head;
    cout << "Circular List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl; // repeat head
}

// Menu
int main() {
    int choice, val, key;
    bool before;
    while (true) {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before/After Node\n4. Delete Node\n5. Search Node\n6. Display\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; insertAtBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; insertAtEnd(val); break;
            case 3:
                cout << "Enter key: "; cin >> key;
                cout << "Enter value: "; cin >> val;
                cout << "Insert before(1) or after(0)? "; cin >> before;
                insertBeforeAfter(key, val, before);
                break;
            case 4: cout << "Enter node to delete: "; cin >> key; deleteNode(key); break;
            case 5: cout << "Enter node to search: "; cin >> key; search(key); break;
            case 6: display(); break;
            case 7: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
