//
// Created by 이승철 on 2022/08/28.
//
#include <iostream>
#include <queue>
#include <set>

typedef long long ll;
using namespace std;
int n, m, weight, u, v, rock, edge_cnt;
ll k;
int parent[1000005];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> edge;

int union_find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = union_find(parent[x]);
}

void merge(int x, int y) {
    x = union_find(x);
    y = union_find(y);
    if (x == y)
        return;
    parent[x] = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;

    for (int u = 1; u <= n; u++) {
        cin >> weight;
        edge.push({weight, {u, n + 1}});
    }
    set<pair<int, int>> cantgo;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        cantgo.insert({u, v});
    }

    for (int u = 1; u < n; u++) {
        if (!cantgo.count({u, u + 1}))
            edge.push({0, {u, u + 1}});
    }

    if (!cantgo.count({n, 1}))
        edge.push({0, {n, 1}});


    for (int vertex = 1; vertex <= n; vertex++)
        parent[vertex] = vertex;


    while (!edge.empty()) {
        if (edge_cnt == n)
            break;
        int cost = edge.top().first;
        int from = edge.top().second.first;
        int to = edge.top().second.second;

        edge.pop();
        if (union_find(from) == union_find(to))
            continue;

        rock += cost;
        edge_cnt++;
        merge(from, to);

    }
    if (m == 0)
        (rock <= k) ? cout << "YES" : cout << "NO";
}
