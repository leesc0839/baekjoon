//
// Created by 이승철 on 2023/03/08.
//
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int N, cost;
struct info {
    int v;
    int cost;
};
const int MX = 11;
int dist[MX], ans = INT32_MAX, start;
bool visit[MX];
vector<info> edge[MX];

void input() {
    cin >> N;
    for (int u = 1; u <= N; u++) {
        for (int v = 1; v <= N; v++) {
            cin >> cost;
            if (cost != 0)
                edge[u].push_back({v, cost});
        }
    }
}

void init(int u) {
    start = u;
    memset(visit, false, sizeof(visit));
}

void fun(int cnt, int vertex, int weight) {
    if (cnt == N) {
        for (auto info: edge[vertex]) {
            if (info.v != start)
                continue;
            ans = min(ans, weight + info.cost);
        }
        return;
    }

    for (auto info: edge[vertex]) {
        if (visit[info.v])
            continue;

        visit[info.v] = true;
        fun(cnt + 1, info.v, weight + info.cost);
        visit[info.v] = false;
    }
}


void sol() {
    for (int u = 1; u <= N; u++) {
        init(u);
        visit[u] = true;
        fun(1, u, 0);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();


}

