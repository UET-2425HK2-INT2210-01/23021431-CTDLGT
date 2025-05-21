#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X; // Nhập số vật và trọng lượng tối đa
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i]; // Nhập trọng lượng và giá trị
    }

    // Tạo bảng DP
    vector<vector<int>> dp(n + 1, vector<int>(X + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= X; j++) {
            if (j < w[i - 1]) {
                dp[i][j] = dp[i - 1][j]; // Không chọn vật i
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]); // Chọn hoặc không chọn vật i
            }
        }
    }

    // In kết quả
    cout << dp[n][X] << endl;

    return 0;
}
