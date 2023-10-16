//
// Created by 이승철 on 2022/09/27.
//
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

#define MAX 51
using namespace std;
int map[MAX][MAX], copied_map[MAX][MAX], N, M, ans = INT32_MAX;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool isUsed[11];
vector<pair<int, int>> virus;
queue<pair<int, int>> Q;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                map[i][j] = 0;
                virus.emplace_back(i, j);
            }
        }
    }
}

void copy_map() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1)
                copied_map[i][j] = -1; // 벽
            else
                copied_map[i][j] = -2; // 비방문
        }
    }
    for (int i = 0; i < virus.size(); i++) {
        if (isUsed[i]) {
            copied_map[virus[i].first][virus[i].second] = 0;
            Q.push({virus[i].first, virus[i].second});
        }
    }
}

void bfs() {
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N || copied_map[nr][nc] == -1)
                continue;
            if (copied_map[nr][nc] != -2)
                continue;

            copied_map[nr][nc] = copied_map[cur.first][cur.second] + 1;
            Q.push({nr, nc});
        }
    }
}

void find_time() {
    int max_cur_time = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (copied_map[i][j] == -2)
                return;
            max_cur_time = max(max_cur_time, copied_map[i][j]);
        }
    }
    ans = min(ans, max_cur_time);
}

void back_tracking(int cnt, int idx) {
    if (cnt == M) {
        copy_map();
        bfs();
        find_time();
        return;
    }
    for (int i = idx; i < virus.size(); i++) {
        if (!isUsed[i]) {
            isUsed[i] = true;
            back_tracking(cnt + 1, i + 1);
            isUsed[i] = false;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    back_tracking(0,0);
    ans == INT32_MAX ? cout << -1 : cout << ans;
}

