//
// Created by 이승철 on 2022/09/01.
//
#include <iostream>
#include <algorithm>

using namespace std;
int n, m, u, v, c;
int cost[105][105];
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        fill(cost[i], cost[i] + n + 1, INF);

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        cost[u][v] = min(cost[u][v], c);
    }

    for (int vertex = 1; vertex <= n; vertex++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (u == v || cost[u][vertex] == INF || cost[vertex][v] == INF)
                    continue;
                cost[u][v] = min(cost[u][v], cost[u][vertex] + cost[vertex][v]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cost[i][j] != INF ? cout << cost[i][j] << ' ' : cout << 0 << ' ';
        cout << '\n';
    }
}

