#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, d; // Cạnh từ u đến v với trọng số d
};

int main() {
    freopen("dirty.txt", "r", stdin); // Đọc từ file
    freopen("dirty.out", "w", stdout); // Ghi ra file

    int n, m, s, e;
    cin >> n >> m >> s >> e; // Nhập số đỉnh, cạnh, s, e
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].d; // Nhập cạnh
    }

    // Khởi tạo khoảng cách
    vector<long long> dist(n + 1, LLONG_MAX);
    vector<int> parent(n + 1, -1);
    dist[s] = 0;

    // Bellman-Ford
    for (int i = 0; i < n - 1; i++) {
        for (const auto& edge : edges) {
            int u = edge.u, v = edge.v, d = edge.d;
            if (dist[u] != LLONG_MAX && dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d; // Cập nhật khoảng cách
                parent[v] = u; // Lưu đỉnh trước
            }
        }
    }

    // In tổng mức độ bẩn
    cout << dist[e] << endl;

    // Tái tạo đường đi
    vector<int> path;
    for (int v = e; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (int v : path) {
        cout << v << " "; // In đường đi
    }
    cout << endl;

    return 0;
}
