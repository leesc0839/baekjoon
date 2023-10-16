#include <iostream>
#include <map>
#include <queue>

#define MAX 105
using namespace std;
int N, M, x, y, a, b, ans;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
vector<pair<int, int>> sw[MAX][MAX];
queue<pair<int, int>> Q;
bool light[MAX][MAX], can_go[MAX][MAX];

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> a >> b;
        sw[x][y].emplace_back(a, b);
    }
}


void init() {
    light[1][1] = can_go[1][1] = true;
    Q.push({1, 1});
}

bool check_can_go(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 1 || nr > N || nc < 1 || nc > N)
            continue;
        if (can_go[nr][nc])
            return true;
    }
    return false;
}

void switch_on(int r, int c) {
    for (auto cur: sw[r][c])
        light[cur.first][cur.second] = true;


    for (auto cur: sw[r][c]) {
        if (can_go[cur.first][cur.second])
            continue;
        if (check_can_go(cur.first, cur.second)) {
            Q.push({cur.first, cur.second});
            can_go[cur.first][cur.second] = true;
        }
    }
    sw[r][c].clear();
}

void bfs() {
    init();
    while (!Q.empty()) {
        auto cur = Q.front();
        switch_on(cur.first, cur.second);
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if (nr < 1 || nr > N || nc < 1 || nc > N)
                continue;
            if (!light[nr][nc] || can_go[nr][nc])
                continue;
            can_go[nr][nc] = true;
            Q.push({nr, nc});
        }
    }
}

void sol() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            if (light[i][j])
                ans++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    bfs();
    sol();
}