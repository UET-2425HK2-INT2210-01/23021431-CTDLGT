#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Danh sách kề
vector<bool> visited;    // Đánh dấu đỉnh đã thăm
vector<int> result;      // Lưu thứ tự tô pô

// Hàm DFS để thực hiện sắp xếp tô pô
void dfs(int v) {
    visited[v] = true; // Đánh dấu đỉnh v đã thăm
    for (int u : adj[v]) { // Duyệt các đỉnh kề
        if (!visited[u]) {
            dfs(u); // Gọi đệ quy cho đỉnh chưa thăm
        }
    }
    result.push_back(v); // Thêm v vào kết quả
}

int main() {
    freopen("jobs.txt", "r", stdin);
    freopen("jobs.out", "w", stdout);

    int n, m;
    cin >> n >> m; // Nhập số công việc và yêu cầu
    adj.resize(n + 1);
    visited.assign(n + 1, false);

    // Nhập m yêu cầu thứ tự
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Thêm cạnh u->v
    }

    // Chạy DFS
    for (int v = 1; v <= n; v++) {
        if (!visited[v]) {
            dfs(v);
        }
    }

    // In kết quả (đảo ngược)
    reverse(result.begin(), result.end());
    for (int v : result) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
