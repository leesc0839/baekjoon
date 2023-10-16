//
// Created by 이승철 on 2022/09/01.
//
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, from, to, u, v, c;
const int INF = 1e9 + 10;
int dist[1005];
int pre[1005];
vector<vector<pair<int, int>>> edge;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    edge.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        edge[u].push_back({c, v});
    }
    cin >> from >> to;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    fill(dist, dist + n + 1, INF);
    dist[from] = 0;
    pq.push({dist[from], from});

    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_vertex = pq.top().second;
        pq.pop();

        if (cur_vertex == to)
            break;

        if (dist[cur_vertex] != cur_cost)
            continue;

        for (auto nxt: edge[cur_vertex]) {
            int nxt_cost = nxt.first;
            int nxt_vertex = nxt.second;

            if (dist[nxt_vertex] <= dist[cur_vertex] + nxt_cost)
                continue;

            dist[nxt_vertex] = dist[cur_vertex] + nxt_cost;
            pq.push({dist[nxt_vertex], nxt_vertex});
            pre[nxt_vertex] = cur_vertex;
        }
    }

    cout << dist[to] << '\n';
    vector<int> path;

    int city = to;
    while (city != from) {
        path.push_back(city);
        city = pre[city];
    }
    path.push_back(city);

    std::reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for (auto cur: path)
        cout << cur << ' ';
}

