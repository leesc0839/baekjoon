//
// Created by 이승철 on 2022/08/29.
//
#include <iostream>
#include <queue>

using namespace std;
int n, m, u, v, d, ans, edge_cnt;
char gender[1005];
int parent[1005];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> edge;

/*
 * n (vertex 2 ~ 1000)
 * m (edge 1 ~ 10000)
 */

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
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> gender[i];

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> d;
        if (gender[u] != gender[v])
            edge.push({d, {u, v}});
    }

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    while (!edge.empty()) {
        int dist = edge.top().first;
        int from = edge.top().second.first;
        int to = edge.top().second.second;

        edge.pop();
        if (find(from) == find(to))
            continue;
        merge(from, to);
        ans += dist;
        edge_cnt++;
    }

    (edge_cnt == n - 1) ? cout << ans : cout << -1;

}
