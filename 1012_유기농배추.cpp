//
// Created by 이승철 on 2022/09/15.
//
#include <iostream>
#include <queue>

#define MAX 51
using namespace std;
//flood-fill
int T, R, C, M, r, c, map[MAX][MAX], ans;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void init() {
    for (int i = 0; i < R; i++)
        fill(map[i], map[i] + C, 0);
    ans = 0;
}

void input() {
    cin >> C >> R >> M;
    for (int i = 0; i < M; i++) {
        cin >> c >> r;
        map[r][c] = 1;
    }
}

void bfs(int r, int c) {
    queue<pair<int, int>> Q;
    Q.push({r, c});

    while (!Q.empty()) {
        int cur_r = Q.front().first;
        int cur_c = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;
            if (map[nr][nc] == 0 || map[nr][nc] == -1)
                continue;
            map[nr][nc] = -1;
            Q.push({nr, nc});
        }
    }
}

void sol() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 1) {
                ans++;
                map[i][j] = -1;
                bfs(i, j);
            }

        }
    }
    cout << ans << '\n';
}

int main() {
    cin >> T;
    while (T--) {
        init();
        input();
        sol();
    }
}
