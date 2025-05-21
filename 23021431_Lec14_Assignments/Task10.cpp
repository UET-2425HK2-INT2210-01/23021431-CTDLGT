#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Duyệt preorder
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " "; // Xử lý gốc
    preorder(root->left); // Duyệt trái
    preorder(root->right); // Duyệt phải
}

// Duyệt inorder
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left); // Duyệt trái
    cout << root->data << " "; // Xử lý gốc
    inorder(root->right); // Duyệt phải
}

// Duyệt postorder
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left); // Duyệt trái
    postorder(root->right); // Duyệt phải
    cout << root->data << " "; // Xử lý gốc
}

int main() {
    // Xây cây ví dụ
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}
