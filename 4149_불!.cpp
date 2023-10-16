//
// Created by 이승철 on 2023/03/19.
//
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define FIRE 1
#define JI 2

struct info {
    int r;
    int c;
    int elem;
};

using namespace std;
int R, C;
const int MX = 1001;
pair<int, int> J;
vector<pair<int, int>> F;
queue<info> Q;
char map[MX][MX];
int dist[MX][MX];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void init() {
    memset(dist, -1, sizeof(dist));
    for (auto cur: F) {
        dist[cur.first][cur.second] = 0;
        Q.push({cur.first, cur.second, FIRE});
    }
    dist[J.first][J.second] = 0;
    Q.push({J.first, J.second, JI});
}

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'J')
                J = {i, j};
            else if (map[i][j] == 'F') {
                F.emplace_back(i, j);
            }
        }
    }
}

bool OOB(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C)
        return true;
    return false;
}

void sol() {
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = cur.r + dr[dir];
            int nc = cur.c + dc[dir];

            if (cur.elem == JI && OOB(nr, nc)) {
                cout << dist[cur.r][cur.c] + 1;
                return;
            }
            if (OOB(nr, nc) || map[nr][nc] == '#' || dist[nr][nc] != -1)
                continue;
            dist[nr][nc] = dist[cur.r][cur.c] + 1;
            Q.push({nr, nc, cur.elem});
        }
    }
    cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    sol();
}
