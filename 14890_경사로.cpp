//
// Created by 이승철 on 2022/12/22.
//
#include <iostream>
#include <stack>

using namespace std;
const int MX = 101;
int board[MX][MX], visit[MX][MX];
int N, L, ans;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
struct info {
    int r;
    int c;
    int floor;
    int cnt;
};

void input() {
    cin >> N >> L;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> board[r][c];

}

bool OBB(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N)
        return true;
    return false;
}

bool check(int idx, int dir) {
    stack<info> S;
    if (dir == 1)
        S.push({idx, 0, board[idx][0], 1});
    else
        S.push({0, idx, board[0][idx], 1});

    for (int i = 0; i < N; i++) {
        int nr = S.top().r + dr[dir];
        int nc = S.top().c + dc[dir];
        auto pre = S.top();
        if (OBB(nr, nc))
            break;
        if (abs(pre.floor - board[nr][nc]) > 1)
            return false;

        if (pre.floor > board[nr][nc]) {
            if (pre.cnt < 0 || visit[nr][nc])
                return false;
            S.push({nr, nc, board[nr][nc], -1 * (L - 1)});
            continue;
        }
        if (S.top().floor < board[nr][nc]) {
            if (pre.cnt < L)
                return false;
            for (int j = 0; j < L; j++) {
                if (visit[S.top().r][S.top().c])
                    return false;
                visit[S.top().r][S.top().c] = true;
                S.pop();
            }
            S.push({nr, nc, board[nr][nc], 1});
            continue;
        }
        if (S.top().cnt == -1) { // 해결
            for (int cnt = 0; cnt < L - 1; cnt++)
                S.pop();
            S.push({nr, nc, board[nr][nc], L});
            stack<pair<int, int>> s;
            s.push({nr, nc});
            if (visit[nr][nc])
                return false;
            visit[nr][nc] = true;
            for (int j = 0; j < L - 1; j++) {
                int nr = s.top().first - dr[dir];
                int nc = s.top().second - dc[dir];
                if (visit[nr][nc])
                    return false;
                visit[nr][nc] = true;
                s.push({nr, nc});
            }
            continue;
        }
        S.push({nr, nc, board[nr][nc], S.top().cnt + 1});
    }
    return S.top().cnt >= 0;
}

void clear() {
    for (int r = 0; r < N; r++)
        fill(visit[r], visit[r] + N, false);
}

void sol() {
    for (int r = 0; r < N; r++) {
        if (check(r, 1))
            ans++;
        clear();
    }
    for (int c = 0; c < N; c++) {
        if (check(c, 2))
            ans++;
        clear();
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();

}
