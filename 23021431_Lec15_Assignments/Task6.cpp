#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // Nhập số lượng phần tử
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i]; // Nhập mảng
    }

    vector<int> dp(n, 1); // Độ dài LIS tại i
    vector<int> prev(n, -1); // Lưu chỉ số trước
    int maxLen = 1, endIdx = 0;

    // Tính LIS
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1; // Cập nhật độ dài
                prev[i] = j; // Lưu chỉ số trước
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            endIdx = i;
        }
    }

    // Tái tạo dãy
    vector<int> lis;
    for (int i = endIdx; i != -1; i = prev[i]) {
        lis.push_back(A[i]);
    }
    reverse(lis.begin(), lis.end());

    for (int x : lis) {
        cout << x << " "; // In dãy con
    }
    cout << endl;

    return 0;
}
