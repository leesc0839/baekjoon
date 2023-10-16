//
// Created by 이승철 on 2023/10/09.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MX = 70;
int N, M, board[MX][MX], cp[MX][MX], cp2[MX][MX], arr[1005];
bool visit[MX][MX];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
queue<pair<int, int>> Q;

void input() {
    cin >> N >> M;
    for (int i = 1; i <= (1 << N); i++)
        for (int j = 1; j <= (1 << N); j++)
            cin >> board[i][j];
    for (int i = 0; i < M; i++)
        cin >> arr[i];
}

void turn(int i, int j, int len) {
    for (int r = 0; r < len; r++)
        for (int c = 0; c < len; c++)
            cp[i + r][j + c] = board[len + i - 1 - c][j + r];
}

bool OOB(int r, int c) {
    if (r < 1 || r > (1 << N) || c < 1 || c > (1 << N))
        return true;
    return false;
}

void melt() {
    for (int i = 1; i <= (1 << N); i++) {
        for (int j = 1; j <= (1 << N); j++) {
            int cnt = 0;
            for (int dir = 0; dir < 4; dir++) {
                int nr = i + dr[dir];
                int nc = j + dc[dir];

                if (OOB(nr, nc))
                    continue;
                if (cp[nr][nc] > 0)
                    cnt++;
            }
            cp2[i][j] = (cnt < 3) ? cp[i][j] - 1 : cp[i][j];
            if (cp2[i][j] < 0)
                cp2[i][j] = 0;
        }
    }

    for (int i = 1; i <= (1 << N); i++)
        for (int j = 1; j <= (1 << N); j++)
            board[i][j] = cp2[i][j];
}


void fire_storm(int l) {
    if (l == 0) {
        for (int i = 1; i <= (1 << N); i++)
            for (int j = 1; j <= (1 << N); j++)
                cp[i][j] = board[i][j];
        melt();
        return;
    }
    int len = (1 << l);

    for (int i = 1; i <= (1 << N); i += len)
        for (int j = 1; j <= (1 << N); j += len)
            turn(i, j, len);
    melt();
}

int bfs(int i, int j) {
    int ret = 0;

    visit[i][j] = true;
    Q.emplace(i, j);

    while (!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        ret++;
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (OOB(nr, nc) || visit[nr][nc] || !board[nr][nc])
                continue;

            visit[nr][nc] = true;
            Q.emplace(nr, nc);
        }
    }
    return ret;
}

void sol() {
    for (int i = 0; i < M; i++)
        fire_storm(arr[i]);

    int ret = 0;
    int cnt = 0;

    for (int i = 1; i <= (1 << N); i++) {
        for (int j = 1; j <= (1 << N); j++) {
            ret += board[i][j];
            if (visit[i][j] || !board[i][j])
                continue;

            int cur = bfs(i, j);
            if (cur > 1)
                cnt = max(cur, cnt);
        }
    }

    cout << ret << '\n' << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    sol();
}
