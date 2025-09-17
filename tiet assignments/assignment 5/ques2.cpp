#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// Insert at end
Node* insertEnd(Node* head, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Display linked list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

// Count occurrences of key and delete all
int countAndDelete(Node* &head, int key) {
    int count = 0;

    // Delete nodes from head if they match the key
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    // Delete nodes after head
    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->data == key) {
            Node* delNode = curr->next;
            curr->next = delNode->next;
            delete delNode;
            count++;
        } else {
            curr = curr->next;
        }
    }

    return count;
}

int main() {
    Node* head = NULL;

    // Sample linked list: 1->2->1->2->1->3->1
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int n = 7;
    for (int i = 0; i < n; i++)
        head = insertEnd(head, arr[i]);

    cout << "Original Linked List: ";
    display(head);

    int key;
    cout << "Enter key to delete: ";
    cin >> key;

    int cnt = countAndDelete(head, key);
    cout << "Count: " << cnt << endl;

    cout << "Updated Linked List: ";
    display(head);

    return 0;
}
