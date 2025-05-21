#include <bits/stdc++.h>
using namespace std;

void buildHeap(vector<int>& arr) {
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap
    for (int x : arr) {
        minHeap.push(x); // Thêm phần tử vào heap
    }
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top()); // Lấy phần tử nhỏ nhất
        minHeap.pop();
    }
    for (int x : result) {
        cout << x << " "; // In mảng heap
    }
    cout << endl;
}

int main() {
    vector<int> list1 = {1, 4, 8, 6, 20, 15, 49, 21, 35, 67, 57};
    vector<int> list2 = {1, 2, 57, 9, 20, 11, 56, 32, 119};

    cout << "Heap for list 1: ";
    buildHeap(list1);

    cout << "Heap for list 2: ";
    buildHeap(list2);

    return 0;
}
