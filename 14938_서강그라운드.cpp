//
// Created by 이승철 on 2022/09/02.
//
#include <iostream>
#include <algorithm>

using namespace std;
int n, m, r, u, v, cost, max_item;
int item[105];
int dist[105][105];
const int INF = 1e4 + 10;

void input() {
    cin >> n >> m >> r;
    for (int vertex = 1; vertex <= n; vertex++)
        cin >> item[vertex];
    for (int i = 1; i <= n; i++)
        fill(dist[i], dist[i] + n + 1, INF);

    for (int i = 0; i < r; i++) {
        cin >> u >> v >> cost;
        if (dist[u][v] > cost)
            dist[u][v] = cost;

        if (dist[v][u] > cost)
            dist[v][u] = cost;
    }
}

void floyd() {
    for (int vertex = 1; vertex <= n; vertex++) {
        for (int from = 1; from <= n; from++) {
            for (int to = 1; to <= n; to++) {
                if (from == to || dist[from][vertex] == INF || dist[vertex][to] == INF)
                    continue;
                if (dist[from][to] > dist[from][vertex] + dist[vertex][to])
                    dist[from][to] = dist[from][vertex] + dist[vertex][to];
            }
        }
    }
}

void sol() {

    int item_cnt = 0;
    for (int vertex = 1; vertex <= n; vertex++) {
        item_cnt += item[vertex];
        for (int to = 1; to <= n; to++) {
            if (vertex == to)
                continue;
            if (dist[vertex][to] <= m)
                item_cnt += item[to];
        }
        max_item = max(max_item, item_cnt);
        item_cnt = 0;
    }
    cout << max_item;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    floyd();
    sol();


}
