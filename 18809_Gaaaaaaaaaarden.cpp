//
// Created by 이승철 on 2022/11/03.
//
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 51
using namespace std;
int N, M, G, R, map[MAX][MAX], ans;
pair<int, int> day[MAX][MAX];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
vector<pair<int, int>> ground;
vector<int> mask;
queue<pair<int, int>> Q;

void input() {
    cin >> N >> M >> G >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2)
                ground.emplace_back(i, j);
        }
    }
}

void init() {
    mask.resize(ground.size());
    for (int i = 0; i < R; i++)
        mask[i] = 1;
    for (int i = R; i < R + G; i++)
        mask[i] = 2;
    for (int i = R + G; i < ground.size(); i++)
        mask[i] = 0;
    std::sort(mask.begin(), mask.end());
}

int bfs() {
    int flower = 0;
    while (!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        int c_day = day[r][c].first;
        int c_color = day[r][c].second;
        Q.pop();

        if (c_day == -2 && c_color == -2) // flower
            continue;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int n_day = day[nr][nc].first;
            int n_color = day[nr][nc].second;

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;
            if (map[nr][nc] == 0 || n_day == -2)
                continue;
            if (n_day == c_day + 1 && c_color != n_color) {
                flower++;
                day[nr][nc] = {-2, -2};
                continue;
            }
            if (n_day == -1 && n_color == -1) {
                day[nr][nc].first = c_day + 1;
                day[nr][nc].second = c_color;
                Q.push({nr,nc});
            }
        }
    }
    return flower;
}

void sol() {
    do {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                day[i][j] = {-1, -1};
        }
        for (int i = 0; i < mask.size(); i++) {
            if (mask[i] != 0) {
                Q.push({ground[i].first, ground[i].second});
                day[ground[i].first][ground[i].second] = {0, mask[i]};
            }
        }
        ans = max(ans, bfs());
    } while (next_permutation(mask.begin(), mask.end()));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    init();
    sol();
    cout << ans;
}
