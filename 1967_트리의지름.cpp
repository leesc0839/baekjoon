//
// Created by 이승철 on 2023/10/06.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int MX = 10005;
int N, start, length;
bool visit[MX];
vector<pair<int, int>> edge[MX];

void input() {
    cin >> N;
    int u, v, cost;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v >> cost;
        edge[u].emplace_back(cost, v);
        edge[v].emplace_back(cost, u);
    }
}

void dfs(int v, int len) {
    for (auto e: edge[v]) {
        int nxt = e.second;
        int cost = e.first;

        if (visit[nxt])
            continue;

        visit[nxt] = true;
        if (length < len + cost) {
            length = len + cost;
            start = nxt;
        }
        dfs(nxt, len + cost);
    }
}

void sol() {
    visit[1] = true;
    dfs(1, 0);

    memset(visit, 0, sizeof(visit));
    visit[start] = true;
    dfs(start, 0);
    cout << length;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    sol();
}

