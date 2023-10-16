//
// Created by 이승철 on 2022/08/28.
//
#include <iostream>
#include <queue>

using namespace std;

int n, m, k, u, v;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> edge;
int parent[1005];

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

    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        edge.push({i, {u, v}});
    }

    for (int i = 0; i < k; i++) {
        int ans = 0;
        int cnt = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> edge_tmp;
        for (int vertex = 1; vertex <= n; vertex++)
            parent[vertex] = vertex;

        while (!edge.empty()) {
            int cost = edge.top().first;
            int from = edge.top().second.first;
            int to = edge.top().second.second;
            edge_tmp.push(edge.top());
            edge.pop();

            if (union_find(from) == union_find(to))
                continue;

            cnt++;
            if (cnt == 1)
                edge_tmp.pop();
            merge(from, to);
            ans += cost;
        }

        if (cnt == n - 1)
            cout << ans << ' ';
        else
            cout << 0 << ' ';
        edge = edge_tmp;
    }
}
