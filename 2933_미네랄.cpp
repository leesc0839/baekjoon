//
// Created by 이승철 on 2023/03/16.
//
#include <iostream>
#include <vector>
#include <cstring>

#define DOWN 3

using namespace std;
int R, C, N, K;
const int MX = 101;
char map[MX][MX];
bool visit[MX][MX];
int dr[4] = {0, 0, -1, 1}; // 동 서 북 남
int dc[4] = {1, -1, 0, 0};
vector<pair<int, int>> cluster;
bool is_separate = true;

bool OOB(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C)
        return true;
    return false;
}

void init() {
    memset(visit, 0, sizeof(visit));
}

void dfs(int idx, int r, int c) {
    if (r == R - 1)
        is_separate = false;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (OOB(nr, nc) || visit[nr][nc] || map[nr][nc] == '.')
            continue;

        visit[nr][nc] = true;
        cluster.emplace_back(nr, nc);
        dfs(idx, nr, nc);
    }
}

void down() {
    int cnt = 1;
    for (auto cur: cluster)
        map[cur.first][cur.second] = '.';

    while (true) {
        for (auto cur: cluster) {
            int nr = cur.first + cnt * dr[DOWN];
            int nc = cur.second + cnt * dc[DOWN];

            if (map[nr][nc] == 'x' || OOB(nr, nc)) {
                for (auto curr: cluster)
                    map[curr.first + (cnt - 1) * dr[DOWN]][curr.second + (cnt - 1) * dc[DOWN]] = 'x';
                return;
            }
        }
        cnt++;
    }
}

void hit(int k, int dir) {
    int c = (dir == 0) ? 0 : C - 1;
    while (true) {
        if (OOB(k, c))
            return;
        if (map[k][c] == 'x') {
            init();
            visit[k][c] = true;
            map[k][c] = '.';

            for (int i = 0; i < 4; i++) {
                int nr = k + dr[i];
                int nc = c + dc[i];

                if (OOB(nr, nc) || visit[nr][nc] || map[nr][nc] == '.')
                    continue;

                visit[nr][nc] = true;
                is_separate = true;
                cluster.clear();
                cluster.emplace_back(nr, nc);

                dfs(i, nr, nc);
                if (is_separate)
                    down();
            }
            return;
        }
        c += dc[dir];
    }
}

void sol() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> K;
        hit(R - K, i % 2);
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << map[i][j];
        cout << '\n';
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
}

