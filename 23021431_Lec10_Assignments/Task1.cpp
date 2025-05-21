#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Danh sách kề lưu đồ thị
vector<bool> visited;    // Mảng đánh dấu đỉnh đã thăm
int n, m;                // Số đỉnh và số cạnh

// Hàm DFS để duyệt một thành phần liên thông
void dfs(int v) {
    visited[v] = true; // Đánh dấu đỉnh v đã thăm
    for (int u : adj[v]) { // Duyệt các đỉnh kề
        if (!visited[u]) {
            dfs(u); // Gọi đệ quy cho đỉnh chưa thăm
        }
    }
}

int main() {
    cin >> n >> m; // Nhập số đỉnh và số cạnh
    adj.resize(n + 1); // Khởi tạo danh sách kề
    visited.assign(n + 1, false); // Khởi tạo mảng visited

    // Nhập m cạnh
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Thêm cạnh x->y
        adj[y].push_back(x); // Thêm cạnh y->x (đồ thị vô hướng)
    }

    int components = 0; // Đếm số thành phần liên thông
    for (int v = 1; v <= n; v++) {
        if (!visited[v]) { // Nếu đỉnh chưa thăm
            dfs(v); // Chạy DFS
            components++; // Tăng số thành phần
        }
    }

    cout << components << endl; // In kết quả
    return 0;
}
