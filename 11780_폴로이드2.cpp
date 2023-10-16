//
// Created by 이승철 on 2022/08/31.
//
#include <iostream>
#include <vector>

using namespace std;
int n, m, u, v, c;
const int INF = 0x3f3f3f3f;
int cost[105][105];
int nxt[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        fill(cost[i], cost[i] + n + 1, INF);

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        if (cost[u][v] > c) {
            cost[u][v] = c;
            nxt[u][v] = v;
        }
    }

    for (int vertex = 1; vertex <= n; vertex++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || cost[i][vertex] == INF || cost[vertex][j] == INF)
                    continue;
                if (cost[i][j] > cost[i][vertex] + cost[vertex][j]) {
                    cost[i][j] = cost[i][vertex] + cost[vertex][j];
                    nxt[i][j] = nxt[i][vertex];
                }

            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cost[i][j] != INF ? cout << cost[i][j] << ' ' : cout << 0 << ' ';
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || nxt[i][j] == 0)
                cout << 0 << '\n';
            else {
                vector<int> path;
                int cur = i;
                while (cur != j) {
                    path.push_back(cur);
                    cur = nxt[cur][j];
                }
                path.push_back(cur);
                cout << path.size() << ' ';
                for (auto nx: path)
                    cout << nx << ' ';
                cout << '\n';
            }
        }
    }

}