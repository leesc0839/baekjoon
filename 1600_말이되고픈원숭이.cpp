//
// Created by 이승철 on 2022/09/19.
//
#include <iostream>
#include <queue>
#include <climits>

#define MAX 201
using namespace std;
int K, R, C;
int map[MAX][MAX];
int dist[MAX][MAX][31];
const int INF = INT32_MAX;
int hdr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int hdc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<>> pq;

void init() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            for (int k = 0; k <= K; k++)
                dist[i][j][k] = INF;
    }
}

void input() {
    cin >> K;
    cin >> C >> R;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cin >> map[i][j];
    }
}

void dijkstra() {
    dist[0][0][0] = 0; // r, c, 말동작 횟수
    pq.push({{dist[0][0][0], 0},
             {0,             0}}); // {동작 횟수, 말동작 횟수}, {r, c}
    while (!pq.empty()) {
        int cur_cost = pq.top().first.first;
        int cur_jump = pq.top().first.second;
        int cur_r = pq.top().second.first;
        int cur_c = pq.top().second.second;
        pq.pop();

        if (dist[cur_r][cur_c][cur_jump] < cur_cost)
            continue;

        if (cur_r == R - 1 && cur_c == C - 1) {
            cout << dist[R - 1][C - 1][cur_jump];
            return;
        }

        for (int i = 0; i < 8; i++) { // 말
            if (K < cur_jump + 1)
                continue;
            int nxt_r = cur_r + hdr[i];
            int nxt_c = cur_c + hdc[i];

            if (nxt_r < 0 || nxt_r >= R || nxt_c < 0 || nxt_c >= C || map[nxt_r][nxt_c] == 1)
                continue;
            if (dist[nxt_r][nxt_c][cur_jump + 1] <= cur_cost + 1)
                continue;
            dist[nxt_r][nxt_c][cur_jump + 1] = cur_cost + 1;
            pq.push({{dist[nxt_r][nxt_c][cur_jump + 1], cur_jump + 1},
                     {nxt_r,                            nxt_c}});
        }

        for (int i = 0; i < 4; i++) { // 일반
            int nxt_r = cur_r + dr[i];
            int nxt_c = cur_c + dc[i];
            if (nxt_r < 0 || nxt_r >= R || nxt_c < 0 || nxt_c >= C || map[nxt_r][nxt_c] == 1)
                continue;
            if (dist[nxt_r][nxt_c][cur_jump] <= cur_cost + 1)
                continue;
            dist[nxt_r][nxt_c][cur_jump] = cur_cost + 1;
            pq.push({{dist[nxt_r][nxt_c][cur_jump], cur_jump},
                     {nxt_r,                        nxt_c}});
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    dijkstra();
}

