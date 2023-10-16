//
// Created by 이승철 on 2022/09/04.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N, M, K, from, to, cost, ans;
int dist_go[1005];
int dist_back[1005];
const int INF = 1e9 + 10;
vector<vector<pair<int, int>>> edge;

void input() {
    cin >> N >> M >> K;
    edge.resize(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> from >> to >> cost;
        edge[from].push_back({cost, to});
    }
}

void dijkstra(int v, int *dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    fill(dist, dist + N + 1, INF);
    dist[v] = 0;
    pq.push({dist[v], v});
    while (!pq.empty()) {
        int cur_vertex = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();

        if (dist[cur_vertex] != cur_cost)
            continue;

        if (v != K && cur_vertex == K) {
            ans = max(ans, dist_back[v] + dist_go[K]);
            return;
        }

        for (auto nxt: edge[cur_vertex]) {
            int nxt_vertex = nxt.second;
            int nxt_cost = nxt.first;

            if (dist[nxt_vertex] <= dist[cur_vertex] + nxt_cost)
                continue;

            dist[nxt_vertex] = dist[cur_vertex] + nxt_cost;
            pq.push({dist[nxt_vertex], nxt_vertex});
        }
    }
}

void sol() {
    dijkstra(K, dist_back);
    for (int i = 1; i <= N; i++) {
        if (i == K)
            continue;
        dijkstra(i, dist_go);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}

