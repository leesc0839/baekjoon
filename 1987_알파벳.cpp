#include <iostream>

using namespace std;

int N, M;
int board[26][26];
bool visit[26][26];
bool used[26];
bool isEnd;
int maxCnt = 1;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(int curR, int curC, int cnt) {
    if (isEnd) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nr = curR + dr[i];
        int nc = curC + dc[i];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;
        if (visit[nr][nc] || used[board[nr][nc]])
            continue;

        isEnd = false;
        visit[nr][nc] = true;
        used[board[nr][nc]] = true;

        dfs(nr, nc, cnt + 1);
        maxCnt = max(maxCnt, cnt + 1);

        visit[nr][nc] = false;
        used[board[nr][nc]] = false;
    }

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char k;
            cin >> k;
            board[i][j] = k - 'A';
        }
    }
    visit[0][0] = true;
    used[board[0][0]] = true;
    dfs(0, 0, 1);
    cout << maxCnt;
}