#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Danh sách kề
vector<int> dist;        // Khoảng cách từ X đến các đỉnh

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y; // Nhập số đỉnh, cạnh, X, Y
    adj.resize(n + 1); // Khởi tạo danh sách kề
    dist.assign(n + 1, -1); // Khởi tạo khoảng cách

    // Nhập m cạnh
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Thêm cạnh x->y
    }

    // BFS từ X
    queue<int> q;
    q.push(X);
    dist[X] = 0; // Khoảng cách từ X đến X là 0
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) { // Duyệt các đỉnh kề
            if (dist[u] == -1) { // Nếu chưa thăm
                dist[u] = dist[v] + 1; // Cập nhật khoảng cách
                q.push(u); // Thêm vào hàng đợi
            }
        }
    }

    cout << dist[Y] << endl; // In số cạnh tối thiểu đến Y
    return 0;
}
