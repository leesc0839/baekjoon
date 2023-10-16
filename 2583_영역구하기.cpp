//
// Created by 이승철 on 2022/09/15.
//
#include <iostream>
#include <queue>

#define MAX 101
using namespace std;
int M, N, K, s_x, s_y, e_x, e_y, area, cnt;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
priority_queue<int, vector<int>, greater<>> pq;
int map[MAX][MAX];
bool visit[MAX][MAX];

void input() {
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> s_x >> s_y >> e_x >> e_y;
        for (int y = s_y; y < e_y; y++) {
            for (int x = s_x; x < e_x; x++)
                map[y][x] = 1;
        }
    }
}

void bfs(int y, int x) {
    queue<pair<int, int>> Q;
    Q.push({y, x});

    while (!Q.empty()) {
        int cur_y = Q.front().first;
        int cur_x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nxt_y = cur_y + dy[i];
            int nxt_x = cur_x + dx[i];

            if (nxt_y < 0 || nxt_y >= M || nxt_x < 0 || nxt_x >= N)
                continue;
            if (map[nxt_y][nxt_x] == 1 || visit[nxt_y][nxt_x])
                continue;
            visit[nxt_y][nxt_x] = true;
            Q.push({nxt_y, nxt_x});
            area++;
        }
    }
    pq.push(area);
}

void sol() {
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            if (!visit[y][x] && map[y][x] == 0) {
                area = 1;
                cnt++;
                visit[y][x] = true;
                bfs(y, x);
            }
        }
    }
    cout << cnt << '\n';
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    sol();
}

