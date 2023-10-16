//
// Created by 이승철 on 2022/08/28.
//
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

#define X first
#define Y second
using namespace std;

int n;
double x, y;
priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> edge;
vector<pair<double, double>> location;
int parent[105];

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
    cin >> n;
    location.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        location[i] = {x, y};
    }
    for (int u = 1; u < n; u++) {
        auto from = location[u];
        for (int v = u + 1; v <= n; v++) {
            auto to = location[v];
            edge.push({sqrt(pow(from.X - to.X, 2) + pow(from.Y - to.Y, 2)), {u, v}});
        }
    }

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    double ans = 0;
    while (!edge.empty()) {
        double cost = edge.top().first;
        int from = edge.top().second.first;
        int to = edge.top().second.second;

        edge.pop();
        if (union_find(from) == union_find(to))
            continue;

        merge(from, to);
        ans += cost;
    }
    cout << ans;
}

