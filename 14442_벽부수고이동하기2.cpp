//
// Created by 이승철 on 2022/09/22.
//
#include <iostream>
#include <queue>
#include <climits>

#define MAX 1001
using namespace std;
int R, C, K, dist[MAX][MAX][11];
char map[MAX][MAX];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
const int INF = INT32_MAX;

void init() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++)
            for (int k = 0; k <= K; k++)
                dist[i][j][k] = INF;
    }
}

void input() {
    cin >> R >> C >> K;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++)
            cin >> map[i][j];
    }
}

void dijkstra() {
    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<>> pq;
    dist[1][1][0] = 1;
    pq.push({
                    {1, 0}, // {cur_cost, crash}, {r,c}
                    {1, 1}
            });

    while (!pq.empty()) {
        int cur_r = pq.top().second.first;
        int cur_c = pq.top().second.second;
        int cur_cost = pq.top().first.first;
        int cur_crash = pq.top().first.second;
        pq.pop();

        if (cur_r == R && cur_c == C){
            cout << cur_cost;
            return;
        }

        if (dist[cur_r][cur_c][cur_crash] != cur_cost)
            continue;

        for (int i = 0; i < 4; i++) {
            int nxt_r = cur_r + dr[i];
            int nxt_c = cur_c + dc[i];

            if (nxt_r <= 0 || nxt_r > R || nxt_c <= 0 || nxt_c > C)
                continue;

            if (map[nxt_r][nxt_c] == '1') {
                if (cur_crash + 1 > K)
                    continue;
                if (dist[nxt_r][nxt_c][cur_crash + 1] <= cur_cost + 1)
                    continue;
                dist[nxt_r][nxt_c][cur_crash + 1] = cur_cost + 1;
                pq.push({{cur_cost + 1, cur_crash + 1},
                         {nxt_r,        nxt_c}});
            } else {
                if (dist[nxt_r][nxt_c][cur_crash] <= cur_cost + 1)
                    continue;
                dist[nxt_r][nxt_c][cur_crash] = cur_cost + 1;
                pq.push({{cur_cost + 1, cur_crash},
                         {nxt_r,        nxt_c}});
            }
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
