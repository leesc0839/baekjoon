//
// Created by 이승철 on 2022/09/04.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 1e9 + 10;
int N, E, u, v, cost, v1, v2, dist[805], root1, root2, ans = INF;
vector<vector<pair<int, int>>> edge;


void input() {
    cin >> N >> E;
    edge.resize(N + 1);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> cost;
        edge[u].push_back({cost, v});
        edge[v].push_back({cost, u});
    }
    cin >> v1 >> v2;
}

bool dijkstra(int start, int end, int root) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    fill(dist, dist + N + 1, INF);
    dist[start] = 0;
    pq.push({dist[start], start});
    while (!pq.empty()) {
        int cur_vertex = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();

        if (cur_vertex == end) {
            if (root == 1)
                root1 += dist[end];
            else if (root == 2)
                root2 += dist[end];
            return true;
        }

        if (dist[cur_vertex] != cur_cost)
            continue;

        for (auto nxt: edge[cur_vertex]) {
            int nxt_vertex = nxt.second;
            int nxt_cost = nxt.first;

            if (dist[nxt_vertex] <= dist[cur_vertex] + nxt_cost)
                continue;

            dist[nxt_vertex] = dist[cur_vertex] + nxt_cost;
            pq.push({dist[nxt_vertex], nxt_vertex});
        }
    }
    return false;
}

void sol() {
    if (dijkstra(1, v1, 1) && dijkstra(v1, v2, 1) && dijkstra(v2, N, 1))
        ans = min(ans, root1);
    if (dijkstra(1, v2, 2) && dijkstra(v2, v1, 2) && dijkstra(v1, N, 2))
        ans = min(ans, root2);

    (ans == INF) ? cout << "-1" : cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}

