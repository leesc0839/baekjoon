//
// Created by 이승철 on 2022/09/03.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
int n, m, u, v, cost, j, s, dist_s[105], dist_j[105], min_dist = INT32_MAX;
const int INF = INT32_MAX;
vector<vector<pair<int, int>>> edge;
vector<int> ans;

void input() {
    cin >> n >> m;
    edge.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> cost;
        edge[u].push_back({cost, v});
        edge[v].push_back({cost, u});
    }
    cin >> j >> s;
    if (n == 2) {
        cout << -1;
        exit(0);
    }
}

void dijkstra(int person, int *dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    fill(dist, dist + n + 1, INF);
    dist[person] = 0;
    pq.push({dist[person], person});
    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_vertex = pq.top().second;
        pq.pop();

        if (dist[cur_vertex] != cur_cost)
            continue;

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


void sol() {
    for (int i = 1; i <= n; i++) {
        if (i == s || i == j || dist_j[i] == 0 || dist_s[i] == 0)
            continue;
        min_dist = min(min_dist, dist_j[i] + dist_s[i]);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int vertex = 1; vertex <= n; vertex++) {
        if (vertex == s || vertex == j || dist_j[vertex] == 0 || dist_s[vertex] == 0)
            continue;
        if (dist_j[vertex] + dist_s[vertex] != min_dist)
            continue;
        if (dist_j[vertex] > dist_s[vertex])
            continue;
        pq.push({dist_j[vertex], vertex});
    }
    if (pq.empty())
        cout << -1;
    else
        cout << pq.top().second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    dijkstra(j, dist_j);
    dijkstra(s, dist_s);
    sol();


}

