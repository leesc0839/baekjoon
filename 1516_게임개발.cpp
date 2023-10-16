//
// Created by 이승철 on 2022/08/28.
//
#include <iostream>
#include <queue>

using namespace std;
int n, u;
int in_degree[505];
int vertex_cost[505];
vector<vector<int>> edge;
int ans[505];

/*
 * n(vertex 개수 : 1 ~ 500)
 */
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    edge.resize(n + 1);
    for (int v = 1; v <= n; v++) {
        cin >> vertex_cost[v];
        while (true) {
            cin >> u;
            if (u == -1)
                break;
            edge[u].push_back(v);
            in_degree[v]++;
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> PQ;

    for (int v = 1; v <= n; v++) {
        if (in_degree[v] == 0)
            PQ.push({vertex_cost[v], v});
    }

    while (!PQ.empty()) {
        auto u = PQ.top();
        PQ.pop();
        ans[u.second] = u.first;

        for (auto v: edge[u.second]) {
            in_degree[v]--;
            if (in_degree[v] == 0)
                PQ.push({vertex_cost[v] + u.first, v});
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';


}