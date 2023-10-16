//
// Created by 이승철 on 2022/10/24.
//
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 1005
using namespace std;
struct info {
    int player;
    int dist;
    int r;
    int c;
};
int N, M, P, S[10], ans[10];
vector<pair<int, int>> v[10];
char map[MAX][MAX], elem;
bool visit[MAX][MAX];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
queue<info> Q, q;

void input() {
    cin >> N >> M >> P;
    for (int i = 1; i <= P; i++)
        cin >> S[i];
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> elem;
            map[r][c] = elem;
            if (48 < elem && elem < 58) {// player
                v[elem - 48].emplace_back(r, c);
                visit[r][c] = true;
                ans[elem - 48]++;
            }
        }
    }
}

void init() {
    for (int player = 1; player < 10; player++) {
        for (auto c: v[player])
            Q.push({player, 0, c.first, c.second});
    }
}

void bfs() {
    while (!Q.empty()) {
        q.push({Q.front().player, 0, Q.front().r, Q.front().c});
        Q.pop();

        while (!Q.empty() && (Q.front().player == q.front().player)) {
            q.push({Q.front().player, 0, Q.front().r, Q.front().c});
            Q.pop();
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = cur.r + dr[i];
                int nc = cur.c + dc[i];

                if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;
                if (map[nr][nc] == '#' || visit[nr][nc] || (cur.dist + 1 > S[cur.player]))
                    continue;

                visit[nr][nc] = true;
                ans[cur.player]++;
                q.push({cur.player, cur.dist + 1, nr, nc});
                Q.push({cur.player, 0, nr, nc});
            }
        }
    }
}

void sol() {
    for (int i = 1; i <= 9; i++) {
        if (ans[i] == 0)
            return;
        cout << ans[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    bfs();
    sol();
}

