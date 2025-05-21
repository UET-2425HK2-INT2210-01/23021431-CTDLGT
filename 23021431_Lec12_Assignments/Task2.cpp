#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, d; // Cạnh từ u đến v với chi phí d
    bool operator<(const Edge& other) const {
        return d < other.d; // So sánh để sắp xếp cạnh theo chi phí
    }
};

vector<int> parent, rank;

int find(int u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]); // Tìm gốc với nén đường
    }
    return parent[u];
}

void unite(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return;
    if (rank[pu] < rank[pv]) swap(pu, pv);
    parent[pv] = pu; // Gộp hai tập hợp
    if (rank[pu] == rank[pv]) rank[pu]++;
}

int main() {
    freopen("connection.txt", "r", stdin);
    freopen("connection.out", "w", stdout);

    int n, m;
    cin >> n >> m; // Nhập số máy tính và cạnh
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].d; // Nhập cạnh
    }

    // Khởi tạo Union-Find
    parent.resize(n + 1);
    rank.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // Sắp xếp cạnh theo chi phí
    sort(edges.begin(), edges.end());

    long long total_cost = 0;
    vector<Edge> mst; // Lưu các cạnh của cây khung
    for (const auto& edge : edges) {
        if (find(edge.u) != find(edge.v)) { // Nếu không tạo chu trình
            unite(edge.u, edge.v); // Gộp hai đỉnh
            total_cost += edge.d; // Cộng chi phí
            mst.push_back(edge); // Thêm cạnh vào cây khung
        }
    }

    // In kết quả
    cout << total_cost << endl;
    for (const auto& edge : mst) {
        cout << edge.u << " " << edge.v << " " << edge.d << endl;
    }

    return 0;
}
