//
// Created by 이승철 on 2022/08/28.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, u, v;
int in_degree[1005];
int ans[1005];
vector<vector<int>> edge;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    edge.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        in_degree[v]++;
    }
    queue<pair<int, int>> Q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            Q.push({i, 1});
        }
    }

    while (!Q.empty()) {
        auto u = Q.front();
        Q.pop();
        ans[u.first] = u.second;
        for (auto v: edge[u.first]) {
            in_degree[v]--;
            if (in_degree[v] == 0)
                Q.push({v, u.second + 1});
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}

