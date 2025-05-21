#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX / 2;

int main() {
    freopen("dirty.txt", "r", stdin);
    freopen("dirty.out", "a", stdout); // Ghi thêm vào file

    int n, m, s, e;
    cin >> n >> m >> s >> e; // Nhập số đỉnh, cạnh, s, e
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

    // Khởi tạo ma trận khoảng cách
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0; // Khoảng cách từ đỉnh đến chính nó là 0
    }
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        dist[u][v] = d; // Thêm cạnh vào ma trận
    }

    // Floyd-Warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]; // Cập nhật khoảng cách
                }
            }
        }
    }

    // In ma trận khoảng cách
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
