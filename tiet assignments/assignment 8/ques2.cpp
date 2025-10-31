#include <iostream>
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

// Insert node in BST
Node* insert(Node* root, int data) {
    if (root == nullptr) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// (a) Search (Recursive)
bool searchRecursive(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

// (a) Search (Non-Recursive)
bool searchIterative(Node* root, int key) {
    while (root != nullptr) {
        if (root->data == key) return true;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

// (b) Maximum element
Node* findMax(Node* root) {
    while (root && root->right != nullptr)
        root = root->right;
    return root;
}

// (c) Minimum element
Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

// (d) Inorder Successor
Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right != nullptr)
        return findMin(node->right);
    Node* succ = nullptr;
    while (root != nullptr) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data)
            root = root->right;
        else
            break;
    }
    return succ;
}

// (e) Inorder Predecessor
Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left != nullptr)
        return findMax(node->left);
    Node* pred = nullptr;
    while (root != nullptr) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data)
            root = root->left;
        else
            break;
    }
    return pred;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Search 40 (Recursive): " << (searchRecursive(root, 40) ? "Found" : "Not Found") << endl;
    cout << "Search 90 (Iterative): " << (searchIterative(root, 90) ? "Found" : "Not Found") << endl;

    cout << "Minimum: " << findMin(root)->data << endl;
    cout << "Maximum: " << findMax(root)->data << endl;

    Node* node = root->left->right; // 40
    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);
    cout << "Inorder Successor of " << node->data << ": " << (succ ? to_string(succ->data) : "None") << endl;
    cout << "Inorder Predecessor of " << node->data << ": " << (pred ? to_string(pred->data) : "None") << endl;

    return 0;
}
