//
// Created by 이승철 on 2022/08/29.
//
#include <iostream>
#include <queue>

using namespace std;
int m, n, u, v, weight, weight_sum, weight_min;
int parent[200005];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> edge;

/*
 * m (vertex : 1 ~ 200000)
 * n (edge : 0 ~ 200000)
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

void init() {
    edge = priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>>();
    for (int i = 0; i < m; i++)
        parent[i] = i;
    weight_sum = weight_min = 0;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        cin >> m >> n;
        if (m == 0 && n == 0)
            return 0;
        init();
        for (int i = 0; i < n; i++) {
            cin >> u >> v >> weight;
            edge.push({weight, {u, v}});
            weight_sum += weight;
        }

        while (!edge.empty()) {
            int cost = edge.top().first;
            int from = edge.top().second.first;
            int to = edge.top().second.second;

            edge.pop();
            if (find(from) == find(to))
                continue;
            merge(from, to);
            weight_min += cost;
        }
        cout << weight_sum - weight_min << '\n';
    }
}

