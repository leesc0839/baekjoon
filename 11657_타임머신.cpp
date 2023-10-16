//
// Created by 이승철 on 2022/09/02.
//
#include <iostream>
#include <vector>
#include <climits>
typedef long long ll;
using namespace std;
int n, m, u, v;
vector<pair<ll, pair<int, int>>> edge;
const ll INF = LLONG_MAX;
ll cost, dist[505];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> cost;
        edge.push_back({cost, {u, v}});
    }
    for (int i = 2; i <= n; i++)
        dist[i] = INF;
}

void bellman() {
    for (auto cur: edge) {
        int from = cur.second.first;
        int to = cur.second.second;
        ll weight = cur.first;

        if (dist[from] != INF && dist[from] + weight < dist[to])
            dist[to] = dist[from] + weight;
    }
}

bool isCycle() {
    for (auto cur: edge) {
        int from = cur.second.first;
        int to = cur.second.second;
        ll weight = cur.first;

        if (dist[from] != INF && dist[from] + weight < dist[to])
            return true;
    }
    return false;
}

void output() {
    for (int i = 2; i <= n; i++)
        dist[i] != INF ? cout << dist[i] << '\n' : cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    for (int i = 0; i < n - 1; i++)
        bellman();
    if (isCycle()) {
        cout << -1;
        return 0;
    } else
        output();
}


