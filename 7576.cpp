#include <iostream>
#include <queue>

#define R first
#define C second
using namespace std;
int r, c;
int board[1001][1001];
bool visit[1001][1001];
bool impossibleAllRipe;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int maxValue;

void findDays() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 0) {
                impossibleAllRipe = true;
                return;
            }
            if (board[i][j] > maxValue)
                maxValue = board[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> c >> r;

    queue<pair<int, int>> Q;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int t;
            cin >> t;
            if (t == 1) {
                Q.push({i, j});
                visit[i][j] = true;
            }
            board[i][j] = t;
        }
    }

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.R + dr[i];
            int nc = cur.C + dc[i];

            if (nr < 0 || nr >= r || nc < 0 || nc >= c)
                continue;
            if (visit[nr][nc] || board[nr][nc] != 0)
                continue;

            board[nr][nc] = board[cur.R][cur.C] + 1;
            visit[nr][nc] = true;
            Q.push({nr, nc});
        }
    }
    findDays();
    if(impossibleAllRipe)
        cout<<-1;
    else
        cout<<maxValue-1;
}
