//
// Created by 이승철 on 2022/08/21.
//
#include <iostream>
#include <queue>

using namespace std;
/*
 * n(크기) : 4~300
 */
int t, n, start_r, start_c, dest_r, dest_c;
int board[305][305];
bool visit[305][305];
int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> start_r >> start_c;
        cin >> dest_r >> dest_c;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = 0;
                visit[i][j] = false;
            }
        }
        queue<pair<int, int>> Q;
        Q.push({start_r, start_c});
        visit[start_r][start_c] = true;

        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();

            for (int i = 0; i < 8; i++) {
                int nr = cur.first + dr[i];
                int nc = cur.second + dc[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;
                if (visit[nr][nc])
                    continue;

                board[nr][nc] = board[cur.first][cur.second] + 1;
                visit[nr][nc] = true;
                Q.push({nr, nc});
            }
        }
        cout << board[dest_r][dest_c] << '\n';
    }


}

