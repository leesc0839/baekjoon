//
// Created by 이승철 on 2022/08/21.
//
#include <iostream>
#include <queue>

using namespace std;
int n, m;
int board[105][105];
bool visit[105][105];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            board[i][j + 1] = s[j] - '0';
    }
    queue<pair<int, int>> Q;
    Q.push({1, 1});
    visit[1][1] = true;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if (board[nr][nc] == 0 || visit[nr][nc] || nr < 1 || nr > n || nc < 1 || nc > m)
                continue;

            Q.push({nr, nc});
            visit[nr][nc] = true;
            board[nr][nc] = board[cur.first][cur.second] + 1;
        }
    }
    cout << board[n][m];

}

