//
// Created by 이승철 on 2022/12/19.
//
#include <iostream>
#include <algorithm>

using namespace std;
int N, M, ans;
const int MX = 501;
int board[MX][MX];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool visit[MX][MX];

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }
}

bool OBB(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M)
        return true;
    return false;
}

void sol(int r, int c, int cnt, int sum) {
    if (cnt == 4) {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (OBB(nr, nc) || visit[nr][nc])
            continue;

        visit[nr][nc] = true;
        sol(nr, nc, cnt + 1, sum + board[nr][nc]);
        if (cnt == 2) { // ㅗ ㅓ ㅏ ㅜ
            sol(r, c, cnt + 1, sum + board[nr][nc]);
        }
        visit[nr][nc] = false;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visit[i][j] = true;
            sol(i, j, 1, board[i][j]);
            visit[i][j] = false;
        }
    }
    cout << ans;
}
