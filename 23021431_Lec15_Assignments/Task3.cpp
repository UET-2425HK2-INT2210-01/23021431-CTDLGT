#include <bits/stdc++.h>
using namespace std;

// Gộp hai mảng con
void merge(vector<double>& A, int left, int mid, int right) {
    vector<double> leftArr(A.begin() + left, A.begin() + mid + 1);
    vector<double> rightArr(A.begin() + mid + 1, A.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            A[k++] = leftArr[i++]; // Lấy từ mảng trái
        } else {
            A[k++] = rightArr[j++]; // Lấy từ mảng phải
        }
    }
    while (i < leftArr.size()) {
        A[k++] = leftArr[i++]; // Gộp phần còn lại của mảng trái
    }
    while (j < rightArr.size()) {
        A[k++] = rightArr[j++]; // Gộp phần còn lại của mảng phải
    }
}

// Hàm MergeSort
void mergeSort(vector<double>& A, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Tính chỉ số giữa
        mergeSort(A, left, mid); // Sắp xếp nửa trái
        mergeSort(A, mid + 1, right); // Sắp xếp nửa phải
        merge(A, left, mid, right); // Gộp hai nửa
    }
}

int main() {
    int n;
    cin >> n;
    vector<double> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i]; // Nhập mảng
    }

    mergeSort(A, 0, n - 1); // Gọi MergeSort

    for (int i = 0; i < n; i++) {
        cout << A[i] << " "; // In kết quả
    }
    cout << endl;

    return 0;
}
