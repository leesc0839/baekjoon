//
// Created by 이승철 on 2022/09/15.
//
#include <iostream>
#include <queue>

#define MAX 26
using namespace std;
int N, area_size, cnt;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
char map[MAX][MAX];
bool visit[MAX][MAX];
priority_queue<int, vector<int>, greater<>> pq;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    }
}

void bfs(int r, int c) {
    queue<pair<int, int>> Q;
    Q.push({r, c});

    while (!Q.empty()) {
        int cr = Q.front().first;
        int cc = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;
            if (visit[nr][nc] || map[nr][nc] == '0')
                continue;

            visit[nr][nc] = true;
            Q.push({nr, nc});
            area_size++;
        }
    }
    pq.push(area_size);
}

void flood_fill() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j] && map[i][j] == '1') {
                cnt++;
                area_size = 1;
                visit[i][j] = true;
                bfs(i, j);
            }
        }
    }

    cout << cnt << '\n';
    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    flood_fill();
}
