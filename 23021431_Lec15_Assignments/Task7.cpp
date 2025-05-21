#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int component_size;

void dfs(int v) {
    visited[v] = true;
    component_size++; // Tăng kích thước thành phần
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u); // Duyệt đỉnh kề
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int count = 0;
    for (int v = 1; v <= n; v++) {
        if (!visited[v]) {
            component_size = 0;
            dfs(v);
            if (component_size >= 3) {
                count++; // Đếm thành phần có >= 3 đỉnh
            }
        }
    }

    cout << count << endl;
    return 0;
}
