#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

struct CNode {
    int data;
    CNode* next;
};

int sizeDoubly(DNode* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int sizeCircular(CNode* head) {
    if (!head) return 0;
    int count = 0;
    CNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    // Example Doubly LL
    DNode* d1 = new DNode{1, NULL, NULL};
    DNode* d2 = new DNode{2, NULL, d1};
    d1->next = d2;
    cout << "Size of Doubly LL: " << sizeDoubly(d1) << endl;

    // Example Circular LL
    CNode* c1 = new CNode{1, NULL};
    CNode* c2 = new CNode{2, NULL};
    c1->next = c2;
    c2->next = c1;
    cout << "Size of Circular LL: " << sizeCircular(c1) << endl;
}
