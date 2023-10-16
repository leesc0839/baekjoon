//
// Created by 이승철 on 2022/08/21.
//
#include <iostream>
#include <queue>

using namespace std;
int r, c, mx, rtn_mx;
bool visit[55][55];
char board[55][55];
int dist[55][55];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

/*
 * L : 76, W : 87
 */

void clear() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            visit[i][j] = false;
            dist[i][j] = 0;
        }
    }
    rtn_mx = max(rtn_mx, mx);
    mx = 0;
}

void bfs(int i, int j) {
    queue<pair<int, int>> Q;
    Q.push({i, j});
    visit[i][j] = true;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int d = 0; d < 4; d++) {
            int nr = cur.first + dr[d];
            int nc = cur.second + dc[d];
            if (nr < 0 || nr >= r || nc < 0 || nc >= c)
                continue;
            if (visit[nr][nc] || board[nr][nc] == 87)
                continue;
            Q.push({nr, nc});
            visit[nr][nc] = true;
            dist[nr][nc] = dist[cur.first][cur.second] + 1;
            mx = max(mx, dist[nr][nc]);
        }
    }
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            board[i][j] = s[j];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 76) {
                bfs(i, j);
                clear();
            }
        }
    }
    cout << rtn_mx;
}

