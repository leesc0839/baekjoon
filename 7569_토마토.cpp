//
// Created by 이승철 on 2022/09/15.
//
#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 101
using namespace std;

int dr[6] = {-1, 0, 1, 0, 0, 0};
int dc[6] = {0, 1, 0, -1, 0, 0};
int dl[6] = {0, 0, 0, 0, -1, 1};

struct info {
    int l;
    int r;
    int c;
};
queue<info> Q;
int map[MAX][MAX][MAX];
int R, C, L, ans;

void input() {
    cin >> C >> R >> L;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                cin >> map[i][j][k];
                if (map[i][j][k] == 1)
                    Q.push({i, j, k});
            }
        }
    }
}

void bfs() {
    while (!Q.empty()) {
        int cur_l = Q.front().l;
        int cur_c = Q.front().c;
        int cur_r = Q.front().r;
        Q.pop();

        for (int i = 0; i < 6; i++) {
            int nxt_l = cur_l + dl[i];
            int nxt_r = cur_r + dr[i];
            int nxt_c = cur_c + dc[i];

            if (nxt_l < 0 || nxt_c < 0 || nxt_r < 0 || nxt_l >= L || nxt_r >= R || nxt_c >= C)
                continue;
            if (map[nxt_l][nxt_r][nxt_c] == -1 || map[nxt_l][nxt_r][nxt_c] >= 1)
                continue;
            map[nxt_l][nxt_r][nxt_c] = map[cur_l][cur_r][cur_c] + 1;
            Q.push({nxt_l, nxt_r, nxt_c});
        }
    }
}

bool sol() {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                if (map[i][j][k] == 0)
                    return false;
                ans = max(ans, map[i][j][k]);
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    bfs();
    (sol()) ? cout << ans - 1 : cout << -1;

}
