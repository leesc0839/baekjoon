//
// Created by 이승철 on 2022/08/29.
//
#include <iostream>

using namespace std;
int R, C, cnt;
int dr[3] = {-1, 0, 1}; /* greedy */
int dc[3] = {1, 1, 1};
char map[10005][505];
bool visit[10005][505];
bool is_finish = false;

void dfs(int r, int c) {
    if (c == C - 1) {
        cnt++;
        is_finish = true;
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (is_finish)
            return;

        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
            continue;
        if (visit[nr][nc] || map[nr][nc] == 'x')
            continue;

        visit[nr][nc] = true;
        dfs(nr, nc);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cin >> map[i][j];
    }

    for (int i = 0; i < R; i++) {
        is_finish = false;
        visit[i][0] = true;
        dfs(i, 0);
    }
    cout << cnt;
}

