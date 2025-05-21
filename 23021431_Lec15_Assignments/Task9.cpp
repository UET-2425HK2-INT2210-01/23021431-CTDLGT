#include <bits/stdc++.h>
using namespace std;

//giống lec11

struct Edge {
    int u, v, d;
};

int main() {
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].d;
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    vector<int> parent(n + 1, -1);
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (const auto& edge : edges) {
            int u = edge.u, v = edge.v, d = edge.d;
            if (dist[u] != LLONG_MAX && dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
                parent[v] = u;
            }
        }
    }

    cout << dist[e] << endl;
    vector<int> path;
    for (int v = e; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
