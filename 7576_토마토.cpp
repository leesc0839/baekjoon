//
// Created by 이승철 on 2022/08/21.
//
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int c, r, day;
int board[1005][1005];
queue<pair<int, int>> Q;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void bfs() {

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if (board[nr][nc] == -1 || board[nr][nc] > 0 || nr < 0 || nr >= r || nc < 0 || nc >= c)
                continue;
            board[nr][nc] = board[cur.first][cur.second] + 1;
            Q.push({nr, nc});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> r;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int elem;
            cin >> elem;
            if (elem == 1)
                Q.push({i, j});
            board[i][j] = elem;
        }
    }

    bfs();

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            day = max(day, board[i][j] - 1);
            if (!board[i][j]) {
                cout << -1;
                exit(0);
            }
        }
    }
    cout << day;
}