//
// Created by 이승철 on 2022/08/30.
//
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int N, K, R, r, c, r_, c_, ans;
set<pair<int, int>> road[101][101];
vector<pair<int, int>> cow;
queue<pair<int, int>> Q;
bool visit[101][101][2];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void first_bfs() {
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if (nr < 1 || nr > N || nc < 1 || nc > N)
                continue;

            if (visit[nr][nc][0] || road[cur.first][cur.second].count({nr, nc}))
                continue;

            visit[nr][nc][0] = true;
            Q.push({nr, nc});
        }
    }
}

bool second_bfs() {
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        if (visit[cur.first][cur.second][0])
            return true;

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if (nr < 1 || nr > N || nc < 1 || nc > N)
                continue;

            if (visit[nr][nc][1] || road[cur.first][cur.second].count({nr, nc}))
                continue;

            visit[nr][nc][1] = true;
            Q.push({nr, nc});
        }
    }
    return false;
}

void clear() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            visit[i][j][0] = visit[i][j][1] = false;
    }
}

void clear_second() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            visit[i][j][1] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> N >> K >> R;
    ans = K * (K - 1) / 2;

    for (int i = 0; i < R; i++) {
        cin >> r >> c >> r_ >> c_;
        road[r][c].insert({r_, c_});
        road[r_][c_].insert({r, c});
    }

    cow.resize(K + 1);

    for (int i = 0; i < K; i++) {
        cin >> r >> c;
        cow[i] = {r, c};
    }

    for (int i = 0; i < K - 1; i++) {
        Q = queue<pair<int, int>>();
        Q.push({cow[i].first, cow[i].second});
        clear();
        visit[cow[i].first][cow[i].second][0] = true;
        first_bfs();

        for (int j = i + 1; j < K; j++) {
            Q = queue<pair<int, int>>();
            Q.push({cow[j].first, cow[j].second});
            clear_second();
            visit[cow[j].first][cow[j].second][1] = true;
            if (second_bfs())
                ans--;
        }
    }
    cout << ans;
}
