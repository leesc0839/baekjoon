//
// Created by 이승철 on 2023/03/15.
//
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int MX = 1501;
char map[MX][MX];
int day[MX][MX];
char visit[MX][MX];
int R, C;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

queue<pair<int, int>> lake_Q;
priority_queue<pair<pair<int, char>, pair<int, int>>, vector<pair<pair<int, char>, pair<int, int>>>, greater<>> swan_pq;

void init() {
    memset(day, -1, sizeof(day));
}

void input() {
    cin >> R >> C;
    init();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] != 'X') {
                if (map[i][j] == 'L')
                    if (swan_pq.empty()) {
                        swan_pq.push({{0, 'a'},
                                      {i, j}});
                        visit[i][j] = 'a';
                    } else {
                        swan_pq.push({{0, 'b'},
                                      {i, j}});
                        visit[i][j] = 'b';
                    }
                day[i][j] = 0;
                lake_Q.push({i, j});
            }
        }
    }
}

bool OOB(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C)
        return true;
    return false;
}

void lake_bfs() {
    while (!lake_Q.empty()) {
        int r = lake_Q.front().first;
        int c = lake_Q.front().second;
        lake_Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (OOB(nr, nc) || day[nr][nc] != -1)
                continue;

            if (map[nr][nc] == 'X') {
                map[nr][nc] = '.';
                day[nr][nc] = day[r][c] + 1;
                lake_Q.push({nr, nc});
            }
        }
    }
}

void swan_bfs() {
    while (!swan_pq.empty()) {
        int c_day = swan_pq.top().first.first;
        char idx = swan_pq.top().first.second;
        int r = swan_pq.top().second.first;
        int c = swan_pq.top().second.second;

        swan_pq.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (OOB(nr, nc) || visit[nr][nc] == idx)
                continue;
            if (visit[nr][nc] == 0) {
                visit[nr][nc] = idx;
                swan_pq.push({{day[nr][nc], idx},
                              {nr,          nc}});
                continue;
            }
            if (visit[nr][nc] != idx) {
                cout << day[nr][nc];
                exit(0);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    lake_bfs();
    swan_bfs();
}
