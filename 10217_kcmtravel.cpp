//
// Created by 이승철 on 2023/03/17.
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> info;

int T, N, M, K, U, V, C, D;
const int INF = INT32_MAX;
const int MX = 101;
int dist[MX][10001];
vector<info> edge[MX];
priority_queue<info, vector<info>, greater<>> pq;


void init() {
    for (int i = 1; i <= N; i++)
        fill(dist[i], dist[i] + M + 1, INF);
    for (int i = 1; i <= N; i++)
        edge[i].clear();
    pq = priority_queue<info, vector<info>, greater<>>();
}

void dijkstra() {
    dist[1][0] = 0;
    pq.push({0, 0, 1});

    while (!pq.empty()) {
        auto cur = pq.top();
        int cur_t = get<0>(cur);
        int cur_c = get<1>(cur);
        int cur_v = get<2>(cur);
        pq.pop();

        if (dist[cur_v][cur_c] != cur_t)
            continue;

        if (cur_v == N) {
            cout << dist[cur_v][cur_c] << '\n';
            return;
        }

        for (auto nxt: edge[cur_v]) {
            int nxt_v = get<0>(nxt);
            int cost = get<1>(nxt);
            int time = get<2>(nxt);

            if (M < cur_c + cost)
                continue;
            if (dist[nxt_v][cur_c + cost] <= cur_t + time)
                continue;

            dist[nxt_v][cur_c + cost] = cur_t + time;
            pq.push({dist[nxt_v][cur_c + cost], cur_c + cost, nxt_v});
        }
    }
    cout << "Poor KCM\n";
}

void sol() {
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        init();
        for (int i = 0; i < K; i++) {
            cin >> U >> V >> C >> D;
            edge[U].emplace_back(V, C, D);
        }
        dijkstra();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
}
