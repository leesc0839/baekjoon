//
// Created by 이승철 on 2022/08/29.
//
#include <iostream>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;

int n, m, from, to;
ll k, cost, cost_min;
priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<>> edge;
set<pair<int, int>> construct;
int parent[1000005];

int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    parent[x] = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    if (m == 0 || m == 1) {
        cout << "YES";
        return 0;
    }

    for (int u = 1; u <= n; u++) {
        cin >> cost;
        edge.push({cost, {u, n + 1}}); // 와우도와의 edge 추가
    }

    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        construct.insert({from, to}); // 공사 구간 일단 저장
    }

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int u = 1; u < n; u++) { // 공사구간 제외하고 edge 추가
        if (!construct.count({u, u + 1}))
            edge.push({0, {u, u + 1}});
    }
    if (!construct.count({n, 1}))
        edge.push({0, {n, 1}});

    while (!edge.empty()) {
        ll dist = edge.top().first;
        int u = edge.top().second.first;
        int v = edge.top().second.second;

        edge.pop();

        if (find(u) == find(v))
            continue;

        merge(u, v);
        cost_min += dist;
    }
    (cost_min <= k) ? cout << "YES" : cout << "NO";
}

