//
// Created by 이승철 on 2022/09/03.
//
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
int N, M, u, v, cost, dist[50005];
const int INF = INT32_MAX;
vector<vector<pair<int, int>>> edge;

void input() {
    cin >> N >> M;
    edge.resize(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> cost;
        edge[u].push_back({cost, v});
        edge[v].push_back({cost, u});
    }
}

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    fill(dist, dist + N + 1, INF);
    dist[1] = 0;
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_vertex = pq.top().second;
        pq.pop();

        if (cur_cost != dist[cur_vertex])
            continue;

        if (cur_vertex == N)
            break;

        for (auto nxt: edge[cur_vertex]) {
            int nxt_cost = nxt.first;
            int nxt_vertex = nxt.second;

            if (dist[nxt_vertex] <= dist[cur_vertex] + nxt_cost)
                continue;

            dist[nxt_vertex] = dist[cur_vertex] + nxt_cost;
            pq.push({dist[nxt_vertex], nxt_vertex});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    dijkstra();
    cout << dist[N];
}

