//
// Created by 이승철 on 2022/09/03.
//
#include <iostream>

using namespace std;
int n, ans;
int cost[25][25];
bool already_erase[25][25];

void input() {
    cin >> n;
    for (int from = 1; from <= n; from++) {
        for (int to = 1; to <= n; to++) {
            cin >> cost[from][to];
        }
    }

    for (int from = 1; from <= n; from++) {
        for (int to = 1; to <= from; to++) {
            ans += cost[from][to];
        }
    }
}

void floyd() {
    for (int vertex = 1; vertex <= n; vertex++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (u == v || u == vertex || vertex == v)
                    continue;
                if (already_erase[u][v])
                    continue;
                if (cost[u][v] == cost[u][vertex] + cost[vertex][v]) {
                    already_erase[u][v] = already_erase[v][u] = true;
                    ans -= cost[u][v];
                }
            }
        }
    }
}

bool isPossible() {
    for (int vertex = 1; vertex <= n; vertex++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (u == v || u == vertex || vertex == v)
                    continue;
                if (cost[u][v] > cost[u][vertex] + cost[vertex][v])
                    return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    floyd();
    isPossible() ? cout << ans : cout << -1;
}
