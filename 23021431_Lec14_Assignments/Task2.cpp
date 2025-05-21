#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Tìm số lẻ nhỏ nhất
int findSmallestOdd(Node* head) {
    int minOdd = INT_MAX;
    Node* current = head;
    while (current) {
        if (current->data % 2 == 1 && current->data < minOdd) {
            minOdd = current->data; // Cập nhật số lẻ nhỏ nhất
        }
        current = current->next;
    }
    return minOdd == INT_MAX ? -1 : minOdd;
}

// Xóa tất cả số lẻ
Node* removeOdd(Node* head) {
    Node dummy(0);
    dummy.next = head;
    Node* prev = &dummy;
    Node* current = head;

    while (current) {
        if (current->data % 2 == 1) {
            prev->next = current->next; // Bỏ qua nút lẻ
            delete current; // Giải phóng bộ nhớ
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return dummy.next;
}

int main() {
    // Tạo danh sách ví dụ
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Smallest odd number: " << findSmallestOdd(head) << endl;

    head = removeOdd(head); // Xóa số lẻ

    Node* current = head;
    while (current) {
        cout << current->data << " "; // In danh sách sau khi xóa
        current = current->next;
    }
    cout << endl;

    return 0;
}
