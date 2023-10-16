//
// Created by 이승철 on 2023/03/20.
//
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> info;
const int MX = 101;
const int INF = INT32_MAX;
int R, C, dist[MX][MX][4], ans = INT32_MAX;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
char map[MX][MX];
pair<int, int> S;
priority_queue<pair<int, info>, vector<pair<int, info>>, greater<>> pq;

void init() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            for (int k = 0; k < 4; k++)
                dist[i][j][k] = INF;
    }
    for (int dir = 0; dir < 4; dir++) {
        pq.push({0, {dir, S.first, S.second}});
        dist[S.first][S.second][dir] = 0;
    }
}

void input() {
    cin >> C >> R;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'C')
                S = {i, j};
        }
    }
}

bool OOB(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C)
        return true;
    return false;
}

void dijkstra() {
    while (!pq.empty()) {
        auto cur = pq.top().second;
        int mir = pq.top().first;
        int dir = get<0>(cur);
        int r = get<1>(cur);
        int c = get<2>(cur);

        pq.pop();

        if (dist[r][c][dir] != mir)
            continue;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (OOB(nr, nc) || i == (dir + 2) % 4 || map[nr][nc] == '*')
                continue;

            if (i != dir) {
                if (dist[nr][nc][i] <= mir + 1)
                    continue;
                if (map[nr][nc] == 'C') {
                    ans = min(mir + 1, ans);
                    continue;
                }
                dist[nr][nc][i] = mir + 1;
                pq.push({mir + 1, {i, nr, nc}});
            } else {
                if (dist[nr][nc][dir] <= mir)
                    continue;
                if (map[nr][nc] == 'C') {
                    ans = min(mir, ans);
                    continue;
                }
                dist[nr][nc][dir] = mir;
                pq.push({mir, {dir, nr, nc}});
            }
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    dijkstra();
}

