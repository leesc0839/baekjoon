//
// Created by 이승철 on 2022/08/29.
//
#include <iostream>
#include <queue>

typedef long long ll;
using namespace std;
int n, m, u, v, edge_cnt;
ll cost_sum, cost_tmp, cost;
int parent[100005];
priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<>> edge;

void init(){
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> cost;
        cost_sum += cost;
        edge.push({cost, {u, v}});
    }

    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

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
    init();
    while (!edge.empty()) {
        ll weight = edge.top().first;
        int from = edge.top().second.first;
        int to = edge.top().second.second;
        edge.pop();

        if (find(from) == find(to))
            continue;

        merge(from, to);
        edge_cnt++;
        cost_tmp += weight;
    }

    (edge_cnt == n - 1) ? cout << cost_sum - cost_tmp : cout << -1;

}

