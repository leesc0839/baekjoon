//
// Created by 이승철 on 2022/09/03.
//
#include <iostream>
#include <climits>

using namespace std;
typedef long long ll;
int TC, N, M, W, u, v;
const ll INF = LLONG_MAX;
ll cost, dist[505][505];

void input() {
    cin >> N >> M >> W;
    for (int i = 1; i <= N; i++)
        fill(dist[i], dist[i] + N + 1, INF);

    for (int i = 0; i < M; i++) {
        cin >> u >> v >> cost;
        if (dist[u][v] > cost)
            dist[u][v] = cost;
        if (dist[v][u] > cost)
            dist[v][u] = cost;
    }

    for (int i = 0; i < W; i++) {
        cin >> u >> v >> cost;
        if (dist[u][v] > -1 * cost)
            dist[u][v] = -1 * cost;
    }
}

void floyd() {
    for (int vertex = 1; vertex <= N; vertex++) {
        for (int from = 1; from <= N; from++) {
            for (int to = 1; to <= N; to++) {
                if (dist[from][vertex] == INF || dist[vertex][to] == INF)
                    continue;
                if (dist[from][to] > dist[from][vertex] + dist[vertex][to])
                    dist[from][to] = dist[from][vertex] + dist[vertex][to];
            }
        }
    }
}

bool sol() {
    for (int i = 1; i <= N; i++)
        if (dist[i][i] < 0)
            return true;
    return false;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> TC;
    while (TC--) {
        input();
        floyd();
        sol() ? cout << "YES\n" : cout << "NO\n";
    }
}

