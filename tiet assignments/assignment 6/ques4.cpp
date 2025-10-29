#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* tail = head;
    while (tail->next) tail = tail->next;
    while (head && tail && head != tail && tail->next != head) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    Node* a = new Node{'r', NULL, NULL};
    Node* b = new Node{'a', a, NULL};
    Node* c = new Node{'d', b, NULL};
    Node* d = new Node{'a', c, NULL};
    Node* e = new Node{'r', d, NULL};
    a->next = b; b->next = c; c->next = d; d->next = e;

    cout << (isPalindrome(a) ? "Palindrome" : "Not Palindrome");
}
