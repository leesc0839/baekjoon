//
// Created by 이승철 on 2022/09/15.
//
#include <iostream>
#include <queue>

#define MAX 101
using namespace std;
int N, ans;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
char elem, map[MAX][MAX];
bool visit[MAX][MAX];


void init() {
    for (int i = 0; i < N; i++)
        fill(visit[i], visit[i] + N, false);
    ans = 0;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> elem;
            map[i][j] = elem;
        }
    }
}

void bfs(int r, int c, char e) {
    ans++;
    queue<pair<int, int>> Q;
    visit[r][c] = true;
    Q.push({r, c});
    while (!Q.empty()) {
        int cur_r = Q.front().first;
        int cur_c = Q.front().second;

        if (map[cur_r][cur_c] == 'G')
            map[cur_r][cur_c] = 'R';

        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = cur_r + dr[dir];
            int nc = cur_c + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N || visit[nr][nc])
                continue;
            if (map[nr][nc] != e)
                continue;

            visit[nr][nc] = true;
            Q.push({nr, nc});
        }
    }
}

void sol() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'R' && !visit[i][j])
                bfs(i, j, 'R');
            else if (map[i][j] == 'G' && !visit[i][j])
                bfs(i, j, 'G');
            else if (map[i][j] == 'B' && !visit[i][j])
                bfs(i, j, 'B');
        }
    }
    cout << ans << ' ';
    init();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'R' && !visit[i][j])
                bfs(i, j, 'R');
            else if (map[i][j] == 'B' && !visit[i][j])
                bfs(i, j, 'B');
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}
