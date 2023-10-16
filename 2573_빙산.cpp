#include <iostream>
#include <queue>

#define MAX 301
using namespace std;
struct info {
    int r;
    int c;
};

queue<info> Q;
int R, C, ans;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool visit[MAX][MAX];
int map[MAX][MAX], contact[MAX][MAX];

void init() {
    for (int i = 0; i < R; i++)
        fill(visit[i], visit[i] + C, false);
}

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cin >> map[i][j];
    }
}

void melt_bfs(int r, int c) {
    visit[r][c] = true;
    Q.push({r, c});
    while (!Q.empty()) {
        int cr = Q.front().r;
        int cc = Q.front().c;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;
            if (visit[nr][nc])
                continue;
            if (map[nr][nc] == 0) {
                visit[nr][nc] = true;
                Q.push({nr, nc});
            } else
                contact[nr][nc]++;
        }
    }
}

void melt() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!visit[i][j] && map[i][j] == 0)
                melt_bfs(i, j);
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] - contact[i][j] <= 0)
                map[i][j] = 0;
            else
                map[i][j] -= contact[i][j];
            contact[i][j] = 0;
        }
    }
}

void visit_bfs(int r, int c) {
    queue<info> q;
    visit[r][c] = true;
    q.push({r, c});
    while (!q.empty()) {
        int cr = q.front().r;
        int cc = q.front().c;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;
            if (visit[nr][nc] || map[nr][nc] == 0)
                continue;
            visit[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}

int flood_fill() {
    int cnt = 0;
    init();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!visit[i][j] && map[i][j] > 0) {
                cnt++;
                visit_bfs(i, j);
            }
        }
    }
    return cnt;
}

int sol() {
    while (true) {
        int ice = flood_fill();
        if (ice >= 2)
            return ans;
        else if (ice == 0)
            return 0;
        ans++;
        init();
        melt();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << sol();
}