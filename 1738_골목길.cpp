//
// Created by 이승철 on 2022/09/05.
//
#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;
typedef long long ll;
int n, m, u, v;
ll w, dist[105];
int pre[105];
vector<pair<ll, pair<int, int>>> edge;
vector<int> cycle_vertex;
const ll INF = LLONG_MIN;

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edge.push_back({w, {u, v}});
    }
    fill(dist, dist + n + 1, INF);
    dist[1] = 0;
}

void bellman() {
    for (auto cur: edge) {
        int from = cur.second.first;
        int to = cur.second.second;
        ll cost = cur.first;

        if (dist[from] != INF && dist[to] < dist[from] + cost) {
            dist[to] = dist[from] + cost;
            pre[to] = from;
        }
    }
}

void isCycle() {
    for (auto cur: edge) {
        int from = cur.second.first;
        int to = cur.second.second;
        ll cost = cur.first;

        if ((dist[from] != INF && dist[to] < dist[from] + cost)) {
            dist[to] = dist[from] + cost;
            pre[to] = from;
            cycle_vertex.push_back(to);
        }
    }
}

void sol() {
    for (int i = 0; i < n - 1; i++)
        bellman();
    isCycle();
    for (auto vertex: cycle_vertex) {
        for (auto e: edge) {
            if (e.second.first == vertex && e.second.second == n) {
                cout << -1;
                exit(0);
            }
        }
    }
    stack<int> path;
    int cur = n;
    while (cur != 1) {
        path.push(cur);
        cur = pre[cur];
    }
    path.push(cur);
    while (!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}
