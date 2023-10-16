//
// Created by 이승철 on 2022/08/27.
//
#include <iostream>
#include <tuple>
#include <queue>

using namespace std;
int v, e, from, to, weight, edge_cnt, sum;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> edge;
int parent[100005];

/*
 * v (정점의 개수) : 1 ~ 10000
 * e (간선) : 1 ~ 100000
 */

int union_find(int vertex) {
    if (parent[vertex] == vertex)
        return vertex;
    return parent[vertex] = union_find(parent[vertex]);
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

    cin >> v >> e;

    for (int i = 1; i <= v; i++) // union-find 초기 설정
        parent[i] = i;

    for (int i = 0; i < e; i++) {
        cin >> from >> to >> weight;
        edge.push({weight, {from, to}});
    }

    while (!edge.empty()) {
        if (edge_cnt == v - 1)
            break;
        auto cur = edge.top();
        edge.pop();

        if (union_find(cur.second.first) == union_find(cur.second.second))
            continue;
        merge(cur.second.first, cur.second.second);
        edge_cnt++;
        sum += cur.first;
    }
    cout << sum;
}
