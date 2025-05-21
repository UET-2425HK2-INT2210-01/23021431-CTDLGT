#include <bits/stdc++.h>
using namespace std;

// Cách 1: Lặp - O(n)
long long power_iterative(int n) {
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result *= 2; // Nhân 2 n lần
    }
    return result;
}

// Cách 2: Đệ quy - O(n)
long long power_recursive(int n) {
    if (n == 0) return 1; // Trường hợp cơ sở
    return 2 * power_recursive(n - 1); // Gọi đệ quy
}

int main() {
    int n;
    cin >> n; // Nhập n
    cout << "Iterative: " << power_iterative(n) << endl;
    cout << "Recursive: " << power_recursive(n) << endl;
    return 0;
}
