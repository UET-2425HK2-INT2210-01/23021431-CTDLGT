#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X; // Nhập số học sinh và tổng tuổi cần tìm
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i]; // Nhập danh sách tuổi
    }

    // Tạo bảng DP cho bài toán Subset Sum
    vector<vector<bool>> dp(n + 1, vector<bool>(X + 1, false));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true; // Tổng 0 luôn đạt được
    }

    // Điền bảng DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= X; j++) {
            if (j < A[i - 1]) {
                dp[i][j] = dp[i - 1][j]; // Không chọn học sinh i
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]]; // Chọn hoặc không chọn học sinh i
            }
        }
    }

    // In kết quả
    cout << (dp[n][X] ? "YES" : "NO") << endl;

    return 0;
}
