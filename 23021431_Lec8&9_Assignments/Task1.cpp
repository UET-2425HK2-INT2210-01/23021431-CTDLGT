#include <bits/stdc++.h>
using namespace std;

// Hàm phân hoạch
int partition(vector<double>& A, int low, int high) {
    double pivot = A[high]; // Chọn pivot là phần tử cuối
    int i = low - 1; // Chỉ số của phần tử nhỏ hơn pivot
    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]); // Hoán đổi phần tử nhỏ hơn hoặc bằng pivot
        }
    }
    swap(A[i + 1], A[high]); // Đặt pivot vào vị trí đúng
    return i + 1; // Trả về vị trí pivot
}

// Hàm QuickSort
void quickSort(vector<double>& A, int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high); // Phân hoạch mảng
        quickSort(A, low, pi - 1); // Sắp xếp nửa trái
        quickSort(A, pi + 1, high); // Sắp xếp nửa phải
    }
}

int main() {
    int n;
    cin >> n; // Nhập số lượng phần tử
    vector<double> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i]; // Nhập mảng số thực
    }

    quickSort(A, 0, n - 1); // Gọi QuickSort để sắp xếp

    // In kết quả
    for (int i = 0; i < n; i++) {
        cout << A[i];
        if (i < n - 1) cout << " "; // Thêm dấu cách giữa các số
    }
    cout << endl;

    return 0;
}
