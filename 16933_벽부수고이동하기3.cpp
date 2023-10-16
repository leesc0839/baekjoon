//
// Created by 이승철 on 2022/10/01.
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

#define MAX 1001
char map[MAX][MAX];
int dist[MAX][MAX][11][2], R, C, K, ans = INT32_MAX;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
using namespace std;

struct info {
    int r;
    int c;
    int crash_cnt;
    bool is_day;
};

void init() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            for (int k = 0; k <= K; k++) {
                for (int d = 0; d < 2; d++)
                    dist[i][j][k][d] = INT32_MAX;
            }
        }
    }
}

void input() {
    cin >> R >> C >> K;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++)
            cin >> map[i][j];
    }
}

void bfs() {
    queue<info> Q;
    dist[1][1][0][0] = 1;
    Q.push({1, 1, 0, true});
    while (!Q.empty()) {
        int cur_r = Q.front().r;
        int cur_c = Q.front().c;
        int cur_crash_cnt = Q.front().crash_cnt;
        bool cur_is_day = Q.front().is_day;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nxt_r = cur_r + dr[i];
            int nxt_c = cur_c + dc[i];

            if (nxt_r < 1 || nxt_r > R || nxt_c < 1 || nxt_c > C)
                continue;

            if (cur_is_day) {
                if (map[nxt_r][nxt_c] == '1') {
                    if (cur_crash_cnt + 1 > K)
                        continue;
                    if (dist[nxt_r][nxt_c][cur_crash_cnt + 1][1] <= dist[cur_r][cur_c][cur_crash_cnt][0] + 1)
                        continue;
                    dist[nxt_r][nxt_c][cur_crash_cnt + 1][1] = dist[cur_r][cur_c][cur_crash_cnt][0] + 1;
                    Q.push({nxt_r, nxt_c, cur_crash_cnt + 1, false});
                } else {
                    if (dist[nxt_r][nxt_c][cur_crash_cnt][1] <= dist[cur_r][cur_c][cur_crash_cnt][0] + 1)
                        continue;
                    dist[nxt_r][nxt_c][cur_crash_cnt][1] = dist[cur_r][cur_c][cur_crash_cnt][0] + 1;
                    Q.push({nxt_r, nxt_c, cur_crash_cnt, false});
                }
            } else {
                if (map[nxt_r][nxt_c] == '1') {
                    if (dist[cur_r][cur_c][cur_crash_cnt][0] <= dist[cur_r][cur_c][cur_crash_cnt][1] + 1)
                        continue;
                    dist[cur_r][cur_c][cur_crash_cnt][0] = dist[cur_r][cur_c][cur_crash_cnt][1] + 1;
                    Q.push({cur_r, cur_c, cur_crash_cnt, true});
                } else {
                    if (dist[nxt_r][nxt_c][cur_crash_cnt][0] <= dist[cur_r][cur_c][cur_crash_cnt][1] + 1)
                        continue;
                    dist[nxt_r][nxt_c][cur_crash_cnt][0] = dist[cur_r][cur_c][cur_crash_cnt][1] + 1;
                    Q.push({nxt_r, nxt_c, cur_crash_cnt, true});
                }
            }
        }
    }

    for (int i = 0; i <= K; i++) {
        for (int j = 0; j < 2; j++) {
            ans = min(ans, dist[R][C][i][j]);
        }
    }
    ans == INT32_MAX ? cout << -1 : cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    bfs();

}

