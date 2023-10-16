//
// Created by 이승철 on 2022/08/27.
//
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;
int n, m, weight, from, to, ans, edge_cnt;
int parent[1005];
tuple<int, int, int> edge[100005];

/*
 * n (버텍스 : 1 ~ 1000)
 * m (엣지 : 1 ~ 100000 )
 */

int union_find(int vertex) {
    if (vertex == parent[vertex])
        return vertex;
    return parent[vertex] = union_find(parent[vertex]);
}

void merge(int u, int v) {
    u = union_find(u);
    v = union_find(v);
    if (u == v)
        return;
    parent[u] = v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++) {
        cin >> from >> to >> weight;
        edge[i] = {weight, from, to};
    }

    sort(edge, edge + m);

    for (int i = 0; i < m; i++) {
        if (edge_cnt == n - 1)
            break;

        int cost, u, v;
        tie(cost, u, v) = edge[i];
        if (union_find(u) == union_find(v))
            continue;
        merge(u, v);
        ans += cost;
        edge_cnt++;
    }
    cout << ans;
}
