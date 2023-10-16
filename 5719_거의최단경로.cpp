//
// Created by 이승철 on 2022/09/06.
//
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>

#define MAX 501

using namespace std;
int N, M, start, destination, u, v, cost, dist[MAX];
const int INF = 1e9 + 10;
vector<vector<pair<int, int>>> edge;
vector<vector<pair<int, int>>> reverse_edge;
set<pair<int, int>> used_edge;
bool visit[MAX][MAX];

void init() {
    edge.clear();
    reverse_edge.clear();
    edge.resize(N);
    reverse_edge.resize(N);
    used_edge.clear();
    fill(dist, dist + N, INF);

    for (int i = 0; i < N; i++)
        fill(visit[i], visit[i] + N, false);
}

bool input() {
    cin >> N >> M;
    if (N == 0 && M == 0)
        return true;
    init();
    cin >> start >> destination;

    for (int i = 0; i < M; i++) {
        cin >> u >> v >> cost;
        edge[u].push_back({cost, v});
        reverse_edge[v].push_back({cost, u});
    }
    return false;
}

void dfs(int vertex) {
    for (auto e: reverse_edge[vertex]) {
        int nxt_vertex = e.second;
        int weight = e.first;

        if (dist[nxt_vertex] != dist[vertex] - weight)
            continue;
        if (visit[nxt_vertex][vertex])
            continue;

        used_edge.insert({nxt_vertex, vertex});
        visit[nxt_vertex][vertex] = true;
        dfs(nxt_vertex);
    }
}

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({dist[start], start});

    while (!pq.empty()) {
        int cur_vertex = pq.top().second;
        int cur_cost = pq.top().first;

        pq.pop();

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
    dfs(destination);
}

void last_dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    fill(dist, dist + N, INF);
    dist[start] = 0;
    pq.push({dist[start], start});
    while (!pq.empty()) {
        int cur_vertex = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();

        if (cur_vertex == destination)
            break;

        if (dist[cur_vertex] < cur_cost)
            continue;

        for (auto nxt: edge[cur_vertex]) {
            int nxt_vertex = nxt.second;
            int nxt_cost = nxt.first;

            if (used_edge.count({cur_vertex, nxt_vertex}))
                continue;

            if (dist[nxt_vertex] <= dist[cur_vertex] + nxt_cost)
                continue;

            dist[nxt_vertex] = dist[cur_vertex] + nxt_cost;
            pq.push({dist[nxt_vertex], nxt_vertex});
        }
    }
    dist[destination] == INF ? cout << -1 << "\n" : cout << dist[destination] << '\n';
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        if (input())
            return 0;
        dijkstra();
        last_dijkstra();
    }
}
