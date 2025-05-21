#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val); // Tạo nút mới
    if (val < root->data) {
        root->left = insert(root->left, val); // Chèn vào bên trái
    } else {
        root->right = insert(root->right, val); // Chèn vào bên phải
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " "; // In theo thứ tự inorder
    inorder(root->right);
}

int main() {
    vector<int> list1 = {1, 4, 8, 6, 20, 15, 49, 21, 35, 67, 57};
    vector<int> list2 = {1, 2, 57, 9, 20, 11, 56, 32, 119};

    Node* root1 = nullptr;
    for (int x : list1) {
        root1 = insert(root1, x); // Xây BST cho list1
    }
    cout << "BST for list 1 (inorder): ";
    inorder(root1);
    cout << endl;

    Node* root2 = nullptr;
    for (int x : list2) {
        root2 = insert(root2, x); // Xây BST cho list2
    }
    cout << "BST for list 2 (inorder): ";
    inorder(root2);
    cout << endl;

    return 0;
}
