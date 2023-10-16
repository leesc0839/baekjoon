//
// Created by 이승철 on 2022/09/13.
//
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define MAX 1001
using namespace std;

const int INF = INT32_MAX;
int N, M, u, v, cost, dist[MAX], start, destination;
vector<pair<int, int>> edge[MAX];

void init() {
    fill(dist, dist + N + 1, INF);
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> cost;
        edge[u].emplace_back(cost, v);
    }
    cin >> start >> destination;
}

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({dist[start], start});

    while (!pq.empty()) {
        int cur_vertex = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();

        if (cur_vertex == destination)
            break;

        if (dist[cur_vertex] != cur_cost)
            continue;

        for (auto nxt: edge[cur_vertex]) {
            int nxt_vertex = nxt.second;
            int edge_cost = nxt.first;

            if (dist[nxt_vertex] <= cur_cost + edge_cost)
                continue;

            dist[nxt_vertex] = cur_cost + edge_cost;
            pq.push({dist[nxt_vertex], nxt_vertex});
        }
    }
    cout << dist[destination];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    dijkstra();
}
