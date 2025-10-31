#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

// Helper function to check BST
bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == nullptr) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(2);
    root->left->right = newNode(8);

    cout << (isBST(root) ? "It is a BST" : "Not a BST") << endl;

    // Example of invalid BST
    root->right->left = newNode(6);
    cout << (isBST(root) ? "It is a BST" : "Not a BST") << endl;

    return 0;
}
