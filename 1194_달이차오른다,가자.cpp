//
// Created by 이승철 on 2023/03/10.
//
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
struct info {
    int r;
    int c;
    int key;
};

int N, M;
const int MX = 51;
char map[MX][MX];
int dist[MX][MX][1 << 6];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int mask[103];
queue<info> Q;

void init() {
    memset(dist, -1, sizeof(dist));
    for (int i = 97; i < 103; i++)
        mask[i] = 1 << (i - 97);
}

void input() {
    cin >> N >> M;
    init();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == '0') {
                dist[i][j][0] = 0;
                Q.push({i, j, 0});
            }
        }
    }
}

bool OOB(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M)
        return true;
    return false;
}

int sol() {
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        if (map[cur.r][cur.c] == '1')
            return dist[cur.r][cur.c][cur.key];

        for (int dir = 0; dir < 4; dir++) {
            int nr = cur.r + dr[dir];
            int nc = cur.c + dc[dir];

            if (OOB(nr, nc) || dist[nr][nc][cur.key] != -1 || map[nr][nc] == '#')
                continue;

            // key
            if (97 <= map[nr][nc] && map[nr][nc] <= 102) {
                if (cur.key & (mask[map[nr][nc]])) {
                    dist[nr][nc][cur.key] = dist[cur.r][cur.c][cur.key] + 1;
                    Q.push({nr, nc, cur.key});
                } else {
                    dist[nr][nc][cur.key | mask[map[nr][nc]]] = dist[cur.r][cur.c][cur.key] + 1;
                    Q.push({nr, nc, cur.key | mask[map[nr][nc]]});
                }
            } else if (65 <= map[nr][nc] && map[nr][nc] <= 70) { // door
                if (!(cur.key & (mask[map[nr][nc] + 32])))
                    continue;
                dist[nr][nc][cur.key] = dist[cur.r][cur.c][cur.key] + 1;
                Q.push({nr, nc, cur.key});
            } else {
                dist[nr][nc][cur.key] = dist[cur.r][cur.c][cur.key] + 1;
                Q.push({nr, nc, cur.key});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << sol();
}

