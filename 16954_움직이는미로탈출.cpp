//
// Created by 이승철 on 2023/03/22.
//
#include <iostream>
#include <queue>
#include <set>

#define WALL 1
#define UK 2

struct info {
    int r;
    int c;
    int type;
    int turn;
};
using namespace std;
const int MX = 8;
char map[MX][MX];
bool visit[MX][MX][MX * MX]; // r c turn
int dr[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dc[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
queue<info> Q;
set<pair<int, int>> wall[MX * MX]; // idx : turn

void input() {
    visit[7][0][1] = true;
    Q.push({7, 0, UK, 1});

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> map[i][j];
            if (map[i][j] == '#') {
                wall[1].insert({i, j});
                Q.push({i, j, WALL, 1});
            }
        }
    }
}

bool OOB(int r, int c) {
    if (r < 0 || r >= 8 || c < 0 || c >= 8)
        return true;
    return false;
}

void sol() {
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        //uk die
        if (cur.type == UK && wall[cur.turn].count({cur.r, cur.c}))
            continue;
        //uk clear
        if (cur.type == UK && cur.r == 0 && cur.c == 7) {
            cout << 1;
            return;
        }
        //wall
        if (cur.type == WALL) {
            int nr = cur.r + 1;
            int nc = cur.c;

            if (OOB(nr, nc))
                continue;
            wall[cur.turn + 1].insert({nr, nc});
            Q.push({nr, nc, WALL, cur.turn + 1});
            continue;
        }
        //uk
        for (int dir = 0; dir < 9; dir++) {
            int nr = cur.r + dr[dir];
            int nc = cur.c + dc[dir];

            if (OOB(nr, nc))
                continue;

            if (visit[nr][nc][cur.turn + 1] || wall[cur.turn].count({nr, nc}))
                continue;
            visit[nr][nc][cur.turn + 1] = true;
            Q.push({nr, nc, UK, cur.turn + 1});
        }
    }
    cout << 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}
