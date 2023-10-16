//
// Created by 이승철 on 2022/09/22.
//
#include <iostream>
#include <queue>
#include <climits>
#include <stack>

#define MAX 100001
using namespace std;
int N, K, dist[MAX], pre[MAX];
const int INF = INT32_MAX;

void init() {
    fill(dist, dist + MAX, INF);
}

void input() {
    cin >> N >> K;
}

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[N] = 0;
    pq.push({dist[N], N});
    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_vertex = pq.top().second;
        pq.pop();

        if (cur_vertex == K)
            return;

        if (dist[cur_vertex] != cur_cost)
            continue;

        for (auto nxt: {cur_vertex - 1, cur_vertex + 1, 2 * cur_vertex}) {
            if (nxt < 0 || nxt >= MAX)
                continue;
            if (dist[nxt] <= cur_cost + 1)
                continue;
            dist[nxt] = cur_cost + 1;
            pq.push({dist[nxt], nxt});
            pre[nxt] = cur_vertex;
        }
    }
}

void sol() {
    cout << dist[K] << '\n';
    stack<int> path;
    int dot = K;
    while (dot != N) {
        path.push(dot);
        dot = pre[dot];
    }
    path.push(N);

    while (!path.empty()) {
        cout << path.top() <<' ';
        path.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    dijkstra();
    sol();

}
