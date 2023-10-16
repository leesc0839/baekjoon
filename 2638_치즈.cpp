//
// Created by 이승철 on 2022/08/30.
//

#include <iostream>
#include <queue>

using namespace std;
int R, C, cheese_cnt, ans_cnt;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int map[105][105];
int contact[105][105];
bool visit[105][105];

struct info {
    int r;
    int c;
};

void clear() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            visit[i][j] = contact[i][j] = 0;
    }
}

void bfs() {
    queue<info> Q;
    Q.push({0, 0});
    visit[0][0] = true;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;
            if (visit[nr][nc])
                continue;
            if (map[nr][nc] == 1) {
                contact[nr][nc]++;
                continue;
            }

            visit[nr][nc] = true;
            Q.push({nr, nc});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1)
                cheese_cnt++;
        }
    }

    while (cheese_cnt) {
        clear();
        bfs();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (contact[i][j] >= 2) {
                    map[i][j] = 0;
                    cheese_cnt--;
                }
            }
        }
        ans_cnt++;
    }
    cout << ans_cnt;
}

