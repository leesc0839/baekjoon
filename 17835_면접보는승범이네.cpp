//
// Created by 이승철 on 2022/09/13.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

#define MAX 100005
using namespace std;
typedef long long ll;

int N, M, K, u, v, elem;
ll cost, dist[MAX];
const ll INF = LLONG_MAX;
bool is_interview[MAX];
vector<pair<int, int>> edge[MAX];
pair<ll, int> ans = {0, INT32_MAX};
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

void init() {
    fill(dist, dist + N + 1, INF);
}

void input() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> cost;
        edge[v].emplace_back(cost, u); // 거꾸로
    }

    init();
    for (int i = 0; i < K; i++) {
        cin >> elem;
        is_interview[elem] = true;
        dist[elem] = 0;
        pq.push({dist[elem], elem});
    }
}

void dijkstra() {
    while (!pq.empty()) {
        int cur_vertex = pq.top().second;
        ll cur_cost = pq.top().first;
        pq.pop();

        if (dist[cur_vertex] != cur_cost)
            continue;

        for (auto nxt: edge[cur_vertex]) {
            int nxt_vertex = nxt.second;
            ll edge_cost = nxt.first;

            if (dist[nxt_vertex] <= cur_cost + edge_cost)
                continue;

            dist[nxt_vertex] = cur_cost + edge_cost;
            pq.push({dist[nxt_vertex], nxt_vertex});
        }
    }
}

void output() {
    for (int i = 1; i <= N; i++) {
        if (is_interview[i])
            continue;

        if (ans.first < dist[i]) {
            ans.first = dist[i];
            ans.second = i;
        } else if (ans.first == dist[i] && ans.second > i)
            ans.second = i;
    }
    cout << ans.second << '\n' << ans.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    dijkstra();
    output();
}