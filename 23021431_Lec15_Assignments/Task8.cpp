#include <bits/stdc++.h>
using namespace std;

//Tương tự bài Lect11, chia thành hai phần.
vector<vector<int>> adj;
vector<bool> visited;
vector<int> result;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    result.push_back(v);
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int v = 1; v <= n; v++) {
        if (!visited[v]) {
            dfs(v);
        }
    }

    reverse(result.begin(), result.end());
    for (int v : result) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
