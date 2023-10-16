//
// Created by 이승철 on 2022/11/04.
//
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>

#define MAX 1005

struct info {
    int dest;
    int cost;
};
using namespace std;
int N, M, u, v, cost, dist[MAX], dist2[MAX], edge_cnt[MAX], pre[MAX];
vector<info> edge[MAX];
set<pair<int, int>> ans;

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> cost;
        edge[u].push_back({v, cost});
        edge[v].push_back({u, cost});
    }
}

void init() {
    fill(dist, dist + N + 1, INT32_MAX);
}

void dijkstra() {
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    // dist,  vertex
    pq.push({0, 1});
    while (!pq.empty()) {
        int c_vertex = pq.top().second;
        int c_dist = pq.top().first;
        pq.pop();

        if (dist[c_vertex] != c_dist)
            continue;

        for (auto nxt: edge[c_vertex]) {
            if (dist[nxt.dest] <= c_dist + nxt.cost)
                continue;
            dist[nxt.dest] = c_dist + nxt.cost;
            pq.push({dist[nxt.dest], nxt.dest});
            pre[nxt.dest] = c_vertex;
        }
    }
}

void sol() {
    for (int i = 2; i <= N; i++) {
        int vertex = i;
        while (true) {
            if (vertex == 1)
                break;
            ans.insert({pre[vertex], vertex});
            vertex = pre[vertex];
        }
    }
    cout << ans.size() << '\n';
    for (auto cur: ans)
        cout << cur.first << ' ' << cur.second << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    dijkstra();
    sol();
}
